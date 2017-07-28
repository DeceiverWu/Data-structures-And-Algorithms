//数据结构与算法分析——C语言描述 练习1.1
//找第k大的元素
//先读入k个数，然后后面的假如大于k就把最后一个数挤出去，用了二分查找。
#include <stdio.h>
#define MAX 1024

void quick_sort(int *arr, int left, int right);
void insertNum(int x, int N, int *arr);	//x:要插入的元素

int main()
{
	int k, n;
	int arr[MAX];
	printf("Input the max of array:");
	scanf("%d", &n);
	k = n / 2;

	printf("First, Input %d number:", k);
	for(int i = 0; i < k; i++){
		scanf("%d", &arr[i]);
	}

	quick_sort(arr, 0, k-1);

	printf("Second, Input rest %d number:", (n-k));
	for(int i = k; i < n; i++){
		int tmp;
		scanf("%d", &tmp);
		if(tmp > arr[k-1]){
			insertNum(tmp, k, arr);
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("The %d  maximum: %d\n", k, arr[k-1]);


	return 0;
}

void quick_sort(int *arr, int left, int right)
{
	if(left < right){
		int i = left;
		int j = right;
		int key = arr[left];

		while(i < j){
			while(i < j && arr[j] < key)
				j--;
			if(i < j)
				arr[i++] = arr[j];

			while(i < j && arr[i] >= key)
				i++;
			if(i < j)
				arr[j--] = arr[i];
		}

		arr[i] = key;
		quick_sort(arr, left, i-1);
		quick_sort(arr, i+1, right);
	}
}

void insertNum(int x, int N, int *arr)
{
	int low, mid, high;
	low = 0; high = N - 1;

	while(low <= high){
		mid = (low + high) / 2;

		if(arr[mid] < x){
			high = mid - 1;
		}else if(arr[mid] > x){
			low = mid + 1;
		}
	}

	while(arr[low] > x)
		low++;

	for(int i = N-1; i > low; i--){
		arr[i] = arr[i - 1];
	}

	arr[low] = x;
}


