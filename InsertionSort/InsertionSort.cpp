#include<vector>
#include <iostream>

void insertionSort(std::vector<int>& arr)
{
    int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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

	insertionSort(arr);

	std::cout << "排序后：" << std::endl;
	printVector(arr);

	return 0;
}

