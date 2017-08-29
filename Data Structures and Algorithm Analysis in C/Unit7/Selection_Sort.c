/*
*选择排序(升序)
*/

void Selection_Sort(const int *arr, int N)
{
	int i, j, k, tmp;

	for(i = 0; i < N - 1; i++){
		k = i;
		for(j = i + 1; j < N; j++){
			if(arr[j] < arr[i]){
				k = j;
			}
		}

		if(k != i){
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
	}
}