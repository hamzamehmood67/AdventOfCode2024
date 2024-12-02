#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

bool isSafeHelper(const std::vector<int> &arr)
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

// Main function to check safety with single removal allowed
bool isSafe(std::vector<int> arr)
{
    if (isSafeHelper(arr)) // Already safe
        return true;

    // Try removing each element and check if the resulting vector is safe
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::vector<int> modifiedArr = arr;
        modifiedArr.erase(modifiedArr.begin() + i); // Remove one element
        if (isSafeHelper(modifiedArr))
            return true; // If removing one element makes it safe
    }

    return false; // Not safe even after removing one level
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
