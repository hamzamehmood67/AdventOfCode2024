#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

bool isSafe(const std::vector<int> &arr)
{
    if (arr.size() < 2) // A single element or empty vector is trivially safe
        return true;

    bool isIncreasing = arr[1] > arr[0]; // Determine the initial trend

    for (size_t i = 1; i < arr.size(); i++)
    {
        int diff = abs(arr[i] - arr[i - 1]);

        // Check difference condition
        if (diff < 1 || diff > 3)
            return false;

        // Check monotonicity condition
        if (isIncreasing && arr[i] <= arr[i - 1])
            return false;
        if (!isIncreasing && arr[i] >= arr[i - 1])
            return false;
    }

    return true; // If we pass all checks, the vector is safe
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open the file!" << endl;
        return 1;
    }
    string line;
    vector<int> numbers;
    int safe{};
    while (getline(inputFile, line))
    {
        istringstream iss(line); // To parse words in the line
        int num;
        while (iss >> num) // Extract integers one by one
        {
            numbers.push_back(num);
        }

        if (isSafe(numbers))
            safe++;

        numbers.clear();
    }
    cout << safe << endl;
    inputFile.close();

    return 0;
}