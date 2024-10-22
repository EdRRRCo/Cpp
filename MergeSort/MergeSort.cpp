#include <iostream>
#include <vector>

//定义动态整型数组arr，整型left，mid，right
void merge(std::vector<int>& arr, int left, int mid, int right) {
    //定义一个临时向量temp，长度为right-left+1，righ和left为原数组的左右边界，所以数组的长度为right-left+1
    std::vector<int> temp(right - left + 1);
    //定义整型i赋值为left，arr[i]为原数组的左子数组，j赋值为mid+1，arr[j]为原数组的右子数组，k赋值为0
    int i = left, j = mid + 1, k = 0;

    //当i<=mid且j<=right时进入循环,即
    while (i <= mid && j <= right) {
        //三元条件运算符，比较arr[i]与arr[j]的值，当arr[i]<=arr[j]为真时，选择arr[i]，放入temp[k],随后i++，继续与arr[j]进行比较，k++，以准备放入下一次比较得到的数；否则选择arr[j]和j完成操作
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    //确保左右子数组剩下的元素也被放入temp，当整体数组的长度为单数时，左右子数组长度不一致，比较后最后会剩下一个元素
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    //将temp数组中的数按顺序复制回arr数组
    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    //确保数组长度不小于等于1，需要拆分
    if (left < right) {
        //找到数组的中间位置
        int mid = left + (right - left) / 2;
        //递归拆分数组左半部分
        mergeSort(arr, left, mid);
        //递归拆分数组右半部分
        mergeSort(arr, mid + 1, right);
        //有序地合并数组
        merge(arr, left, mid, right);
    }
}

void print(const std::vector<int>& arr) {
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "请输入数组大小：";
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "请输入数组的" << n << "个数值";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "排序后的数组为：";
    mergeSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}
