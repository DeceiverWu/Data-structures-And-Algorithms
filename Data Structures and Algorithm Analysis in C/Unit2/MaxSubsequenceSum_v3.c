/*求最大子序列和
*	version 3
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
const int SIZE = 8;

static int MaxSubSum(const int *A, int Left, int Right){
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if(Left == Right)
		if(A[Left] > 0)
			return A[Left];
		else
			return 0;

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i = Center; i >= Left; i--){
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i = Center + 1; i <= Right; i++){
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}

int Max3(int a, int b, int c){
	if(a > b && a > c) return a;
	if(b > c && b > a) return b;
	if(c > a && c > b) return c;
	return false;
}

int MaxSubsequenceSum(const int *A, int N){
	return MaxSubSum(A, 0, N - 1);
}

int main(void)
{
	int A[SIZE] = { 1, -2, 4, -6, 2, 4, -4, 1 };
	int MaxSum;

	MaxSum = MaxSubsequenceSum(A, SIZE);
	cout << MaxSum << endl;

	return 0;
}