#include "Macierz.h"
#include <iostream>
#include <windows.h>
#include <new>
#include <iomanip>

using namespace std;



macierz::macierz(int x, int y)
{
    a = x;
    b = y;

    if (x > 0 && y > 0)
    {
    	
        try
        {
            A = new double* [x];
        }

        catch(bad_alloc())

        {
            cout<<"Error"<<endl;
        }

        for (int i = 0; i < x; i++)
        {
            try
            {
                A[i] = new double [y];
            }

            catch(bad_alloc())
            {
                cout<<"Error"<<endl;
			}         

        }

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
	        {
	            A[i][j] = 0;
	        }
    }

}


void macierz::input_data()
{
    if (a > 0 && b > 0)
    {
        cout<<"Wprowadz elementy macierzy (wprowadzanie odbywa sie wierszami)"<<endl;

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            cin>>A[i][j];
        }
    }
}

void macierz::print_matr()
{
    if (a > 0 && b > 0)
    {
            cout<<"Wypisuje macierz: "<<endl<<endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

macierz::~macierz()
{
    if (a > 0 && b > 0)
    {
            for (int i = 0; i < a; i++)
        {
            if (A[i]) delete [] A[i];
        }

        if (A) delete [] A;

        A = NULL;
    }

}

macierz operator* (const macierz &A, const macierz &B)
{

    if (A.a ==  0 || A.b == 0 || B.a == 0 || B.b == 0)
    {

        cout<<"Blad inicjalizacji mnozonej(ych) macierzy!"<<endl;
        system("pause");
        exit(0);
    }

    if (A.b != B.a)
    {
        cout<<"Nie mozna wykonac mnozenia!"<<endl;
        system("pause");
        exit(0);
    }
    
    int i , j, k;
    double s;

    macierz *C = NULL;
    C = new macierz;

    C[0].a = A.a;
    C[0].b = B.b;

    C[0].A = new double* [A.a];

    for (i = 0; i < A.a; i++)
    {
        C[0].A[i] = new double [B.b];
    }

     for(i = 0; i < A.a; i++)
        for(j = 0; j < B.b; j++)
        {
            s = 0;
            for(k = 0; k < A.b; k++) s += A.A[i][k] * B.A[k][j];
            C[0].A[i][j] = s;
        }

    return C[0];
}

macierz&  macierz:: operator= (const macierz & X)
{
	
int tmp = 0;

if (this->a == 0 || this->b == 0) tmp = 1;
if (this->a == X.a && this->b == X.b) tmp = 2;
if ((this->a != X.a || this->b != X.b) && (this->a != 0 && this->b != 0)) tmp = 3;

    switch (tmp)
    {
        case 1:
        {
            int x = X.a;
            int y = X.b;
            this->a = X.a;
            this->b = X.b;

            try
            {
                A = new double* [x];
            }

            catch(bad_alloc())

            {
                cout<<"Error"<<endl;
            }

            for (int i = 0; i < x; i++)
            {
                try
                {
                    A[i] = new double [y];
                }

                catch(bad_alloc())
                {
                    cout<<"Error"<<endl;
                }
            }

            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                {
                    this->A[i][j] = X.A[i][j];
                }

            return *this;
        }

        case 2:
        {

        int x = X.a;
        int y = X.b;

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                this->A[i][j]=X.A[i][j];
            }



            return *this;

        }

        case 3:
        {

            for (int i = 0; i < this->a; i++)
            {
                if (this->A[i]) delete [] this->A[i];
            }

            if (this->A) delete [] this->A;

            this -> a = X.a;
            this -> b = X.b;

            int x = X.a;
            int y = X.b;

            try
            {
                A = new double* [x];
            }

            catch(bad_alloc())

            {
                cout<<"Error"<<endl;
            }


            for (int i = 0; i < x; i++)
            {
                try
                {
                    A[i] = new double [y];
                }

                catch(bad_alloc())
                {
                    cout<<"Error"<<endl;
                }
            }

                for (int i = 0; i < x; i++)
                    for (int j = 0; j < y; j++)
                    {
                        this->A[i][j]=X.A[i][j];
                    }


            return *this;
        }

        default:
            {
                cout<<"Unknown situation, i don't know what to do"<<endl;
                cout<<"Operator = skonczyl"<<endl;
            }
    }

    return *this; 
}


ostream & operator<< (ostream &ekran, const macierz & X)
{
  

    if (X.a == 0 || 0 == X.b)
    {
        ekran << "Matrix initializing error! Won't print matrix\n";
        system("pause");
        exit(1);
    }

    ekran << setw(4);

    int i, j;


    for (i = 0; i < X.a; i++)
    {
         for (j = 0; j < X.b; j++)
            {
                ekran << setw(3) << X.A[i][j];
            }
        ekran << endl;
    }

  return ekran;
}

istream & operator>>(istream & keyboard, const macierz & X)
{


    if (0 == X.a || 0 == X.b || NULL == X.A)
    {

        cout << "Matrix initializing error!\n";
        system("pause");
        exit(1);
    }
    cout << "Wprowadz elementy macierzy ( Dane wprowadza sie wierszami ).\n";
    int i, j;

    for (i = 0 ; i < X.a; i++)
        for (j = 0; j < X.b; j++)
            {
                keyboard >> X.A[i][j];
            }

    return keyboard;
}

macierz operator+ (const macierz &A, const macierz &B)
{
     if (A.a ==  0 || A.b == 0 || B.a == 0 || B.b == 0)
    {

        cout<<"Blad inicjalizacji mnozonej(ych) macierzy!"<<endl;
        system("pause");
        exit(0);
    }

    if (A.a != B.a || A.b != B.b)
    {
        cout<<"diffrent sizez of matrixes, cannot make an addition\n";
        system("pause");
        exit(1);
    }

    int i, j;

    macierz *C = NULL;
    C = new macierz;


    C[0].a = A.a;
    C[0].b = A.b;

    C[0].A = new double* [A.a];

    for (i = 0; i < A.a; i++)
    {
        C[0].A[i] = new double [A.b];
    }

    for(i = 0; i < A.a; i++)
        for(j = 0; j < A.b; j++)
        {
            C[0].A[i][j] = A.A[i][j] + B.A[i][j];
        }

        return C[0];
}

macierz operator- (const macierz &A, const macierz &B)
{
     if (A.a ==  0 || A.b == 0 || B.a == 0 || B.b == 0)
    {

        cout<<"Blad inicjalizacji mnozonej(ych) macierzy!"<<endl;
        system("pause");
        exit(0);
    }

    if (A.a != B.a || A.b != B.b)
    {
        cout<<"diffrent sizez of matrixes, cannot make a subtraction\n";
        system("pause");
        exit(1);
    }

    int i, j;

    macierz *C = NULL;
    C = new macierz;


    C[0].a = A.a;
    C[0].b = A.b;

    C[0].A = new double* [A.a];

    for (i = 0; i < A.a; i++)
    {
        C[0].A[i] = new double [A.b];
    }

    for(i = 0; i < A.a; i++)
        for(j = 0; j < A.b; j++)
        {
            C[0].A[i][j] = A.A[i][j] - B.A[i][j];
        }

        return C[0];
}

macierz operator*(const macierz &X, const int k) // Może zmienić na funkcję globalną
{
    if (X.a == 0 || X.b == 0 || X.A == NULL)
    {
        cout<<"Failed while initializing matrix, cannot multiply by constant\n";
        system("pause");
        exit(0);
    }
    int i, j;

    macierz *C = NULL;
    C = new macierz;


    C[0].a = X.a;
    C[0].b = X.b;

    C[0].A = new double* [X.a];

    for (i = 0; i < X.a; i++)
    {
        C[0].A[i] = new double [X.b];
    }


    for(i = 0; i < X.a; i++)
        for(j = 0; j < X.b; j++)
        {
            C[0].A[i][j] = X.A[i][j] * k;
        }

        return C[0];
}

void macierz::transposition()
{

    double tmp[a * b];
    int i, j, k = 0;

    for (i = 0; i < b; i++)
        for(j = 0; j < a; j++)
    {
        tmp[k++] = A[j][i];
    }

    k = 0;

    for (i = 0; i < a; i++)
    {
        if (A[i]) delete [] A[i];
    }

    if (A) delete [] A;

    swap(a, b);

    A = new double * [a];

    for (i = 0; i < a; i++)
    {
        A[i] = new double [b];
    }

    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
    {
        A[i][j] = tmp[k++];
    }

}
