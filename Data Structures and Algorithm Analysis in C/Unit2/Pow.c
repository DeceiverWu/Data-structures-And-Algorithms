/*高效率取幂算法
* X is unknow number
*N is pow
*/

long int Pow(long int X, unsigned int N){
	if(N == 0)
		return 1;
	if(N == 1)
		return X;
	if(IsEven(N))
		return Pow(X * X, N / 2);
	else
		return Pow(X * X, N / 2) * X;
}

int IsEven(unsigned int N){
	if(N % 2)
		return 0;
	else
		return 1;
}

/*调整版
* 将 “X奇数次幂” 转换成 “X偶数次幂 * X” 取代了 “N==1” 的判断
*/
long int Pows(long int X, unsigned int N){
	if(N == 0)
		return 1;
	if(IsEven(N))
		return Pows(X * X, N / 2);
	else
		return Pows(X, N - 1) * X;
}

/*
*非递归快速求幂
*/
long int PowNotRecursion(long int X, unsigned int N){
	long pow = 1;

	while(N > 0){
		if(N & 1)
			pow *= X;
		X *= X;
		N >>= 1;
	}

	return pow;
}