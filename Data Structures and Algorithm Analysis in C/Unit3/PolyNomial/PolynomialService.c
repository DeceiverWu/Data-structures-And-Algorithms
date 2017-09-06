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
	Position p = poly.list;

	while(Advance(p) != NULL && Advance(p)->Element.Exponent > e.Exponent){
		p = Advance(p);
	}
	//判断p是否尾结点，以及指数是否相同
	if( isLast(p) || Advance(p)->Element.Exponent != e.Exponent){
		Insert(e, p);
	}else{	//指数相同的情况
		Advance(p)->Element.Coefficient += e.Coefficient;
		if(Advance(p)->Element.Coefficient == 0){
			deleteNext(p);
		}
	}
}

void InputPolynomial(Polynomial poly)
{
    int coefficient, exponent;
    ElementType monomials;
    printf("please enter Coefficient and Exponent,alphabet to end\n");  
    while (scanf("%d", &coefficient) == 1) {  
        scanf("%d", &exponent);
        monomials.Coefficient = coefficient;  
        monomials.Exponent = exponent;  
        insertMonomials(monomials, poly);  
    }  
    getchar();	//字母还留在输入流当中，scanf是不会删去的  
}

void ZeroPolynomial(Polynomial Poly)
{
	MakeEmpty(poly.list);
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	Position p1 = Poly1.list;
	Position p2 = Poly2.list;
	
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{

}

void PrintPolynomial(const Polynomial Poly)
{

}