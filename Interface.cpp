#include "Interface.h"
#include "Macierz.h"
using namespace std;

void menu()
{
    cout<<" 0 - Addition"<<endl;
    cout<<" 1 - Subtraction"<<endl;
    cout<<" 2 - Multiplication by constant"<<endl;
    cout<<" 3 - Multiplication of 2 matrixes"<<endl;
    cout<<" 4 - transposition of matrix"<<endl;
    cout<<" 5 - Close program"<<endl;
}

void fun_addition()
{
    int x, y;
    cout << "Addition "<<endl;
    cout << "Insert dimensions of matrix: " << endl;

    cin>>x;
    cin>>y;

    macierz m1(x, y), m2(x, y), C;

    cout<<"insert first matrix: "<<endl;

    cin >> m1;

    cout<<"insert second matrix: "<<endl;

    cin >> m2;

    C = m1 + m2;

    cout<<"Result matrix: \n"<<endl;

    cout << C;

}

void fun_subtraction()
{
    int x, y;
    cout << "Subtraction "<<endl;
    cout << "Insert dimensions of matrix: " << endl;

    cin>>x;
    cin>>y;

    macierz m1(x, y), m2(x, y), C;

    cout<<"insert first matrix: "<<endl;

    cin >> m1;

    cout<<"insert second matrix: "<<endl;

    cin >> m2;

    C = m1 - m2;

    cout<<"Result matrix: \n"<<endl;

    cout << C;
}

void fun_multiplicationC()
{
    int x, y, k;
    cout << "Multiplication by a constant "<<endl;
    cout << "Insert dimensions of matrix: " << endl;

    cin>>x;
    cin>>y;

    macierz m1(x, y), C;

    cout<<"insert matrix: "<<endl;

    cin >> m1;

    cout<<"insert constant: "<<endl;

    cin >> k;

    C = m1 * k;

    cout<<"Result matrix: \n"<<endl;

    cout << C;
}

void fun_multiplicationM()
{
    int x, y, z;
    cout << "Multiplication of matrixes "<<endl;
    cout << "Insert dimensions of first matrix: " << endl;

    cin>>x;
    cin>>y;

    cout <<" Insert number of rows in second matrix " << endl;

    cin>>z;

    macierz m1(x, y), m2(y, z), C;

    cout<<"insert first matrix: "<<endl;

    cin >> m1;

    cout<<"insert second matrix: "<<endl;

    cin >> m2;

    C = m1 * m2;

    cout<<"Result matrix: \n"<<endl;

    cout << C;
}

void Transposite()
{
    int x, y;
    cout << "Transposition of matrix "<<endl;
    cout << "Insert dimensions of matrix: " << endl;

    cin>>x;
    cin>>y;

    macierz X(x, y);

    cout << " Insert matrix " << endl;

    cin >> X;

    X.transposition();

    cout << X;
}
