using System.Threading.Channels;

const int arraySize = 50000;
var array = new int[arraySize];
ReadFromText(array);
SortArray(array);
void ReadFromText(int[] array)
{
	// Specify the file path
	string filePath = "random_numbers.txt";
	// Read all lines from the file
	string[] lines = File.ReadAllLines(filePath);
	// Create an array to store the integer values
	// Convert each line to an integer and fill the array
	for (int i = 0; i < lines.Length; i++)
	{
		array[i] = int.Parse(lines[i]);
	}
	//Console.WriteLine(array[200]);
	//Console.WriteLine(array[5000]);
	//Console.WriteLine(array[1000]);
	//Console.WriteLine(array[19500]);
	//Console.WriteLine(array[24000]);
	//Console.WriteLine(array[49999]);
}

void SortArray(int[] NumArray)
{
	DateTime time1 = DateTime.Now;
	bool swapRequired;
	int swapCount = 0;
	for (int i = 0; i < arraySize - 1; i++)
	{
		swapRequired = false;
		for (int j = 0; j < arraySize - i - 1; j++)
			if (NumArray[j] > NumArray[j + 1])
			{
				var tempVar = NumArray[j];
				NumArray[j] = NumArray[j + 1];
				NumArray[j + 1] = tempVar;
				swapCount++;
				swapRequired = true;
			}
		if (swapRequired == false)
			break;
	}
	DateTime time2 = DateTime.Now;
	Console.WriteLine("Swap Count : " + swapCount);
	Console.WriteLine("C# Sorting Array Time : " + (time2 - time1).TotalSeconds);
}

