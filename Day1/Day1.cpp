#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream> // For stringstream
#include <cmath>
#include <unordered_map> // For std::abs

using namespace std;

int main()
{
    std::ifstream inputFile("input.txt"); // Replace with your input file name
    if (!inputFile)
    {
        std::cerr << "Error: Unable to open the file!" << std::endl;
        return 1;
    }

    std::vector<int> array1, array2;
    std::string line;

    // Read the file line by line
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line); // To parse each line
        int num1, num2;
        if (iss >> num1 >> num2)
        { // Extract two numbers
            array1.push_back(num1);
            array2.push_back(num2);
        }
    }

    inputFile.close();

    // Check if both arrays are of the same size
    if (array1.size() != array2.size())
    {
        std::cerr << "Error: Arrays are of different sizes!" << std::endl;
        return 1;
    }

    // Sort both arrays
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    unordered_map<int, int> mp;

    for (int a : array2)
        mp[a]++;

    long ans{};
    for (int a : array1)
    {
        int occur = mp[a];
        ans += a * occur;
    }

    cout << ans << endl;
    return 0;
}
