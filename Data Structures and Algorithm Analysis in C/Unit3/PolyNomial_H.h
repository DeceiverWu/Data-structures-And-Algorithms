#ifndef PolyNomial_H
#define PolyNomial_H

const int MaxDeGree = 50;

void ZeroPolynomial(Polynomial *Poly);
void AddPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolySum);
int Max(const Polynomial *Poly1, const Polynomial *Poly2);
void MultPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolyProd);
