/*
*插入排序(升序)
*/

//一般写法:
void Insertion_Sort_v1(const int *arr, int N)
{
	int i, j, tmp;

	for(i = 1; i < N; i++){
		//将要排序的元素临时存储
		tmp = arr[i];
		//从i开始由后往前进行比值
		for(j = i; j > 0; j--){
			if(arr[j] < arr[j - 1])
				arr[j] = arr[j - 1];
		}
		//插入
		arr[j] = tmp;
	}

}

//优化一般写法(减少内循环次数):
void Insertion_Sort_v2(const int *arr, int N)
{
	int i, j, tmp;

	for(i = 1; i < N; i++){
		tmp = arr[i];
		//循环条件直接判断比值，不成立则中止循环
		for(j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			arr[j] = arr[j - 1];

		arr[j] = tmp;
	}
}

