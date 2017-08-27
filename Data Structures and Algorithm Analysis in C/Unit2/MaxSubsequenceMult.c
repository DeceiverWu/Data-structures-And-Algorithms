/*
*	求最大子序列乘积
*
*考虑存在负数的情况(ps：负负会得正)，因此我们用两个辅助数组
*max[i]和min[i]
*max[i]来表示以arr[i]结尾的最大连续子序列乘积
*min[i]来表示以arr[i]结尾的最小连续子序列乘积
*/

#include <iostream>
using std::cin; using std::cout; using std::endl;

const int MAX =	1000;

int max_three(int x, int y, int z)
{
	int max;
	max = x > y ? x : y;
	max = max > z ? max : z;
	return max;
}

int min_three(int x, int y, int z)
{
	int min;
	min = x < y ? x : y;
	min = min < z ? min : z;
	return min;
}

int MaxSubsequenceMult(const int *A, int N)
{
	int max[N], min[N], maxSubsequence;
	max[0] = min[0] = maxSubsequence = A[0];

	for(int i = 1; i < N; i++){
		max[i] = max_three(A[i], max[i-1] * A[i], min[i-1] * A[i]);
		min[i] = min_three(A[i], max[i-1] * A[i], min[i-1] * A[i]);
		if(maxSubsequence < max[i])
			maxSubsequence = max[i];
	}

	return maxSubsequence;
}


int main()
{
	int arr[10] = {-1, 10, 5, 6, -8, -9, 5, -6, 11, -5};
	int max = 0;

	cout << "最大子序列乘积:";
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	max = MaxSubsequenceMult(arr, 10);
	cout << max << endl;

	return 0;
}
