#include<algorithm>
#include<vector>
#include <iostream>

void selectionSort(std::vector<int>& arr)
{
	int n = arr.size();

	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

void printVector(const std::vector<int>& arr)
{
	for (int num : arr)
	{
		std::cout << num << std::endl;
	}
}

int main()
{
	std::vector<int> arr = { 13,34,2,56,89,47,58 };
	std::cout << "排序前：" << std::endl;

	printVector(arr);

	selectionSort(arr);

	std::cout << "排序后：" << std::endl;
	printVector(arr);

	return 0;
	
}

