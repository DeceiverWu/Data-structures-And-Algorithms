#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "PolyNomial_H.h"

typedef struct{
	int CoeffArray[MaxDeGree + 1];
	int HighPower;
}*Polynomial;

void ZeroPolynomial(Polynomial *Poly){
	int i;

	for(i = 0 ; i <= MaxDeGree ; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolySum){
	int i;

	ZeroPolynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower,Poly2->HighPower);

	for(i = PolySum->HighPower ; i >= 0 ; i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];

}

int Max(const Polynomial *Poly1, const Polynomial *Poly2){
	return (Poly1->HighPower > Poly2->HighPower) ? Poly1->HighPower : Poly2->HighPower;
}

void MultPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolyProd){
	int i, j;

	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if(PolyProd->HighPower > MaxDeGree)
		cout << "Exceeded array size" << endl;
	else{
		for(i = 0 ; i <= Poly1->HighPower ; i++)
			for(j = 0 ; j <= Poly2->HighPower ; j++)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j]; 
	}

}

//自己发挥
int main(void){


}
