#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED
#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

class macierz
{
    double **A;
    int a, b;

public:
    macierz(int x = 0, int y = 0);
    void input_data();
    void print_matr();
    ~macierz();
    macierz* operator*=(const int k);
    macierz & operator= (const macierz & X);
    void transposition();
    friend macierz operator* (const macierz &A, const macierz &B);
    friend ostream & operator<<(ostream &ekran, const macierz & X);
    friend istream & operator>>(istream & keyboar, const macierz & X);
    friend macierz operator+ (const macierz &A, const macierz &B);
    friend macierz operator- (const macierz &A, const macierz &B);
    friend macierz operator*(const macierz &X, const int k);

};

ostream & operator<<(ostream &ekran, const macierz & X);
macierz operator* (const macierz &A, const macierz &B);
macierz operator+ (const macierz &A, const macierz &B);
macierz operator- (const macierz &A, const macierz &B);
macierz operator*(const macierz &X, const int k);
istream & operator>>(istream & keyboar, const macierz & X);

#endif // MACIERZ_H_INCLUDED
