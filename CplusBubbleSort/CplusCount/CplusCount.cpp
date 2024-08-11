#define arraySize 50000
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>  // for high_resolution_clock
#include <vector>

std::vector<std::string> ReadFromText()
{
    // Specify the file path
    std::string filePath = "F:\\Projects\\Github\\CSharpVsCPlus_BubleSort\\CplusBubbleSort\\CplusCount\\x64\\Release\\random_numbers.txt";

    // Open the file for reading
    std::ifstream inputFile(filePath);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }

    // Read lines into a vector of strings
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Close the file
    inputFile.close();
    return lines;
}

void SortArray(std::vector<std::string>& arr)
{
    auto start = std::chrono::high_resolution_clock::now();
    bool swapRequired;
    int swapCount = 0;
    int len = arr.size();

    for (int i = 0; i < len - 1; i++)
    {
        swapRequired = false;
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapCount++;
                swapRequired = true;
            }
        if (!swapRequired)
            break;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    setlocale(LC_NUMERIC, "");
    std::cout << "\n Swap Count " << swapCount << " \n";
    std::cout << "\n C++ Sorting Array Time: " << elapsed.count() << " s\n";
}

int main()
{
    // Read the array from the file
    std::vector<std::string> arr = ReadFromText();

    // Sort the array
    SortArray(arr);

    return 0;
}
