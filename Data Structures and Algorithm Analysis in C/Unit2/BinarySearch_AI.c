/*
*给出一个有效的算法来确定在整数A1<A2<A3<...<AN的数组中是否存在整数i使得Ai=i
*/

#include <iostream>
using std::cin; using std::cout; using std::endl;

int BinarySearch_AI(const int *A, int N)
{
	int low = 0;
	int high = N - 1;
	int mid;

	while(low <= high){
		mid = (low + high) / 2;

		if(A[mid] < mid + 1)
			high = mid - 1;
		else if(A[mid] > mid + 1)
			low = mid + 1;
		else 
			return mid;
	}

	return -1;
}

int main()
{
	int arr[] = {24, 2, 1, 7, 14, 8};
	int result, length = sizeof(arr)/sizeof(int);

	result = BinarySearch_AI(arr, length);
	cout << "arr[" << result << "] 即 A"<< result + 1 <<" = " << arr[result] << endl;

	return 0;
}