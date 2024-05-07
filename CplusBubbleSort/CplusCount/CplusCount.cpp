#define  arraySize 50000
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>  // for high_resolution_clock
#include<array>
int* ReadFromText()
{
    // Specify the file path
    std::string filePath = "C:\\Users\\OmidTavana\\source\\repos\\CplusCount\\CplusCount\\x64\\Debug\\random_numbers.txt";

    // Open the file for reading
    std::ifstream inputFile(filePath);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }

    // Count the number of lines in the file
    int numLines = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        ++numLines;
    }

    // Reset the file pointer to the beginning of the file
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    // Dynamically allocate memory for the array
    int* a = new int[numLines];

    // Read each line from the file and convert it to an integer
    for (int i = 0; i < numLines; ++i) {
        if (std::getline(inputFile, line)) {
            try {
                a[i] = std::stoi(line);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Error reading line " << (i + 1) << " from file" << std::endl;
        }
    }

    // Close the file
    inputFile.close();
    std::cout<<"\n" << a[200];
    std::cout<<"\n" << a[5000];
    std::cout<<"\n" << a[1000];
    std::cout<<"\n" << a[19500];
    std::cout<<"\n" << a[24000];
    std::cout<<"\n" << a[49999];
    return a;
}

void SortArray(int* arr)
{
	auto start = std::chrono::high_resolution_clock::now();
	bool swapRequired;
    int swapCount = 0;
    for (int i = 0; i < arraySize - 1; i++)
	{
		swapRequired = false;
		for (int j = 0; j < arraySize - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int tempVar = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tempVar;
                swapCount++;
                swapRequired = true;
			}
		if (swapRequired == false)
			break;
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
    std::cout << "\n Swap Count " << swapCount << " \n";
    std::cout << "\n C++ Sorting Array Time: " << elapsed.count() << " s\n";
}
int main()
{
	// Record start time
	int* arrPointer;
	arrPointer = ReadFromText();
	SortArray(arrPointer);
}

