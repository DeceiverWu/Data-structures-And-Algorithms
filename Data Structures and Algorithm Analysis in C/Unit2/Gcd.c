/*欧几里德算法
*	计算最大公因数
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;

unsigned int Gcd(unsigned int M, unsigned int N){
	unsigned int rem;

	while(N > 0){
		rem = M % N;
		M = N;
		N = rem;
	}

	return M;
}

int main(void)
{
	int M, N, gcd;
	cin >> M >> N ;
	gcd = Gcd(M, N);
	cout << "最大公因数: " <<gcd << endl;

	return 0;
}