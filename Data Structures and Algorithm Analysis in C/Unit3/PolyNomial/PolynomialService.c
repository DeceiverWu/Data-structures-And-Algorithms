/*
*实现功能(调用底层函数)
*/
#include "PolynomialService_H.h"
#include <stdio.h>

typedef struct{
	List list;
}Polynomial;

struct Node{
	ElementType Element;
	Position Next;
};

Polynomial createPolynomial()
{
	Polynomial poly;
	poly.list = CreateList();
	return poly;
}

void InsertMonomials(ElementType e,Polynomial poly)
{
	List p = poly.list;
	
}

void InputPolynomial(Polynomial poly)
void ZeroPolynomial(Polynomial Poly)
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
int Max(const Polynomial Poly1, const Polynomial Poly2)
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
