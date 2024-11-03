#include <iostream>
#include<vector>

int main()
{
    std::cout << "Hello World!\n";
}

void insertSort(std::vector<int>& arr, int n)
{
	//定义一个中间变量存放待插入排序的数据的值
    int key;
	//从待排序数组的第二个元素开始循环
	for (int i = 1; i < n; i++)
	{
		//将待插入排序的数组元素的值赋给key
		key = a[i];
		//定义一个整型数据，其值为当前数组下标的前一个数组下标
		int j = i - 1;
		//当被比较的数组元素还没从后往前遍历完，且，待排序数组元素的值小于遍历到的前面数组元素的值时，进入循环
		while (j > 0 && a[j] > key)
		{
			//将遍历到的数组元素的值往后移一位
			a[j+1] = a[j];
			//被比较数组元素往前遍历一位
			j--;
		}
		//当所有元素比较完毕，跳出循环，将key的值（也就是待插入排序的数组元素的值）赋给结束时指向的元素的后一位
		a[j + 1] = key;
	}
}