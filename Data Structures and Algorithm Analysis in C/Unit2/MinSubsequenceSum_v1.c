/*求最小子序列和
*	version 4 效率简洁版
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
const int SIZE = 8;

int MinSubsequenceSum(const int *A, int N) {
	int ThisSum, MinSum, i;

	ThisSum = MinSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum < MinSum)
			MaxSum = ThisSum;
		else if (ThisSum > 0)
			ThisSum = 0;
	}
	return MinSum;
}

int main(void)
{
	int A[SIZE] = { 1, -2, 4, -6, 2, 4, -4, 1 };
	int MaxSum;

	MaxSum = MinSubsequenceSum(A, SIZE);
	cout << MaxSum << endl;

	return 0;
}