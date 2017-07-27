//数据结构与算法分析——C语言描述 习题1.3
#include <stdio.h>

#define PrintDigit(ch) (putchar(ch + '0'))

void printInt(unsigned int N)
{
	if(N >= 10)
		printInt(N / 10);
	PrintDigit(N % 10);
}

//N:输入实数	decLoc:精确位置
void printOut(double N, int decLoc)
{
	//处理负数
	if(N < 0){
		putchar('-');
		N = -N;
	}

	int num = (int)N;	//强转取整
	printInt(num);

	double decimal = N - num;	//获取小数部分
	if(decimal > 0){
		putchar('.');
		double res = 0.5;
		
		//处理小数四舍五入问题
		for(int i = 0; i < decLoc; i++){
			res /= 10;
		}
		decimal += res;

		for(int i = 0; i < decLoc; i++){
			decimal *= 10;
		}

		printInt(decimal);
	}
}

int main()
{
	printOut(123.45678, 2);
	putchar('\n');

	return 0;
}