#include <iostream>
#include<vector>
#include<algorithm>

void bubbleSort(std::vector<int>& arr) 
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void printVector(const std::vector<int>& arr)
{
	for (int num : arr)
	{
		std::cout << num << " ";
		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "请输入数组大小：";
	int n;
	std::cin >> n;

	std::vector<int> arr(n);
	std::cout << "请输入数组的" << n << "个数值";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	bubbleSort(arr);

	std::cout << "排序后的数组为："<<std::endl;
	printVector(arr);

	return 0;
}
