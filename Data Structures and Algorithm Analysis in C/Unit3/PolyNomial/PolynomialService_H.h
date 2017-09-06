/*
*声明功能(调用底层函数)
*/
#include <stdlib.h>
#include "List_H.h"

Polynomial createPolynomial();  
void InsertMonomials(ElementType e,Polynomial poly);  
void InputPolynomial(Polynomial poly); 
void ZeroPolynomial(Polynomial Poly);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);
int Max(const Polynomial Poly1, const Polynomial Poly2);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);