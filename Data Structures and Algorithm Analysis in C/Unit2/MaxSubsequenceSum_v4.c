/*求最大子序列和
*	version 4 效率简洁版
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
const int SIZE = 8;

int MaxSubsequenceSum(const int *A, int N) {
	int ThisSum, MaxSum, i;

	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main(void)
{
	int A[SIZE] = { 1, -2, 4, -6, 2, 4, -4, 1 };
	int MaxSum;

	MaxSum = MaxSubsequenceSum(A, SIZE);
	cout << MaxSum << endl;

	return 0;
}