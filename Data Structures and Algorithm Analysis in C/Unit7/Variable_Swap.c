/*
*值交换
*/

void Swap_v1(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap_v2(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void Swap_v3(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}