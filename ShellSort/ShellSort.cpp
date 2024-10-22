#include<vector>
#include <iostream>

void shellSort(std::vector<int>& arr)
{
    int n = arr.size();
	for (int i = n/2; i > 0; i /= 2)
	{
		for (int j = i; j < n; j++)
		{
			int temp = arr[j];
			int k;
			for (k = j; k >= i && arr[k - i] > temp; k -= i)
			{
				arr[k] = arr[k - i];
			}
			arr[k] = temp;
		}
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

	shellSort(arr);

	std::cout << "排序后：" << std::endl;
	printVector(arr);

	return 0;
}
