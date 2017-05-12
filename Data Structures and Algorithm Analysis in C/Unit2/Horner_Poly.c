/*计算F(X) = ∑AX    0~N  A为系数 X的i次幂为未知数*/

double Horner_Poly(int* A, int X, int N){
	double Poly;
	int i;

	Poly = 0;
	for(i = N; i >= 0; i--){
		Poly = X * Poly + A[i];
	}

	return Poly;
}

/*
 *例子：当X = 3，F(X) = 4X^4 + 8X^3 + X + 2 
 *这里N = 4 , A[]{2, 1, 0, 8,4};
 *i = 4时, Poly = 4
 *i = 3时, Poly = 4X + 8
 *i = 2时, Poly = 4X^2 + 8X + 0
 *i = 1时, Poly = 4X^3 + 8X^2 + 0 + 1
 *i = 0时, Poly = 4X^4 + 8X^3 + 0 + X + 2
 *算法每循环一次，未知数阶都会上升，并且加上相应阶的系数
 */