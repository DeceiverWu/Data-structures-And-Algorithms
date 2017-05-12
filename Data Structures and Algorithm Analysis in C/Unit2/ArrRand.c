/*生成前N个自然数的一个随机置换
*	RandInt(i,j)随机生成i和j之间的一个整数
*	随机数组不允许有重复元素
*/

/*基本算法
*	A是指向数组的指针， N是生成的自然数个数
*/

void ArrInRand(int* A, int N){
	int num, i, j;
	for(i = 0; i < N; i++){
		num = RandInt(0, N);
		for(j = 0; j < i; j++){
			if(A[j] == num){
				num = RandInt(0, N);
				j = -1;
			}
		}

		A[i] = num;
	}
}


/*利用Used[Ran]数组来确认相应随机数是否已经存在*/
void ArrInRandUsed(int* A, int* Used, int N){
	int num, i;
	for(i = 0; i < N; i++){
		num = RandInt(0, N);
		if(Used[num])
			while(Used[(num = RandInt(0, N))]);
		A[i] = num;
		Used[num] = 1;
	}

}