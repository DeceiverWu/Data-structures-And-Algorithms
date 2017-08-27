/*
*编写一个程序来确定正整数N是否素数
*这里可以看之前写的Prime_Num.c文件，利用了素数表记录素数，第二次查询时可以直接通过Prime[num]判断，效率高
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;

int isPrime(int num)
{
	if(num == 2)
		return 1;

	if(num == 0 || num == 1 || num % 2 == 0)	//0,1都不是素数，除了2之外的偶数都不是素数
		return 0;

	for(int i = 3; i * i < num; i += 2)
		if(num % i == 0)
			return 0;

	return 1;
}

int mian()
{
	int N;

	cout << "输入要判断的正整数:";
	cin >> N;

	if(isPrime(N))
		cout << N << "是素数" << endl;
	else
		cout << N << "不是素数" << endl;

	return 0;
}