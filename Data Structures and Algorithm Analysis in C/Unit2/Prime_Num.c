/*
*编写一个程序输出整数0~N之间的所有素数
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <math.h>

const int MAX = 100000000;

/*一般算法
 *因数都是成对出现的。比如，100的因数有：1和100，2和50，4和25，5和20，10和10。
 *看出来没有？成对的因数，其中一个必然小于等于100的开平方，另一个大于等于100的开平方。
 */
void getPrime(int N)
{
	int num = 0, j, count = 0;
	int prime[N] = {0};

	for(int i = 2; i <= N; i++){
		for(j = 2; j < sqrt(i); j++){
			if(i % j == 0)
				break;
		}
		if(j > sqrt(i)){
			prime[count++] = i;
		}
	}

	for(int i = 0; i < count; i++){
		cout << prime[i] << "\t";
		if(i % 10 == 0)
			cout << endl;
	}
}


//剔除偶数,但2是素数
void getPrime_No_Even(int N)
{
	int j, count = 1;
	int prime[N] = {0};

	prime[0] = 2;
	for(int i = 3; i <= N; i += 2){
		for(j = 2; j * j <= i; j++){	//j*j <= i 等同于 j <= sqrt(i),网上说前者更不容易出错，我估计是sqrt()精度问题
			if(i % j == 0)
				break;
		}
		if(j * j > i){
			prime[count++] = i;
		}
	}

	for(int i = 0; i < count; i++){
		cout << prime[i] << "\t";
		if(i % 10 == 0)
			cout << endl;
	}
}

/*筛选法
 *原理：首先，2是公认最小的质数，所以，先把所有2的倍数去掉；然后剩下的那些大于2的数里面，
 *		最小的是3，所以3也是质数；然后把所有3的倍数都去掉，剩下的那些大于3的数里面，最小
 *		的是5，所以5也是质数......
 *
 *得出结论：一旦得出一个数是素数，那么它的倍数就不可能是素数。
 *基于方法一和方法二，建立一张素数表，用于筛选和记录到目前为止的素数。
 *以空间换效率
 *
 *(暂时能想到的方法，绝对还有更优的算法,或者利用存储方式继续改善，比如按位存储)
 */
void getPrimeScreen_v1(int N)
{
	int count = 0;
	bool prime[N + 1];	//素数表

	//初始化素数表
	for(int i = 0; i <= N; i++){
		prime[i] = true;
	}

	prime[0] = prime[1] = false;
	prime[2] = true;

	for(int i = 2; i * i <= N; i++){	//只需要判断sqrt(N)个数就行了，
		if(prime[i]){	//如果prime[i]是素数，相应倍数的整数则不为素数，取false
			for(int j = i * 2; j <= N; j += i){
				prime[j] = false;
			}
		}
	}

	for(int i = 2; i <= N; i++){
		if(prime[i]){
			cout << i << "\t";
			if(i % 10 == 0)
				cout << endl;
		}
	}
}

int main()
{
	int N;
	int start, stop;

	cout << "输入要测试的范围(默认从2开始):" ;
	cin >> N;

	//方法一(一般算法):
	//getPrime(N);

	//方法二(剔除偶数):
	//getPrime_No_Even(N);

	//方法三():
	getPrimeScreen_v1(N);

	return 0;
}

