#include "Interface.h"
#include "Macierz.h"
#include "Interface.cpp"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int ops;
    cout << " Welcome to matrix calculator."<<endl;

    while (1)
    {
        menu();

        cin >> ops;

        switch (ops)
        {
            case 0:
                {
                    fun_addition();
                    system("pause");
                    system("cls");
                }
                break;

            case 1:
                {
                    fun_subtraction();
                    system("pause");
                    system("cls");
                }
                break;

            case 2:
                {
                    fun_multiplicationC();
                    system("pause");
                    system("cls");
                }
                break;

            case 3:
                {
                     fun_multiplicationM();
                     system("pause");
                     system("cls");
                }
                break;

            case 4:
                {
                     Transposite();
                     system("pause");
                     system("cls");
                }
                break;

            case 5:
                {
                    cout<<"Program will be closed"<<endl;
                    system("pause");
                    exit(0);
                }
                break;

            default:
                {
                    cout<< "Wrong operation number, try again." << endl;
                }
                break;


        }
    }

    system("pause");
    return 0;
}
