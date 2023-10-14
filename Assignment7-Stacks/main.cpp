using namespace std;

#include <iostream>
#include <iomanip>
#include <string>


int menuOption();
void n_QueensMenu();

int main()
{
    n_QueensMenu();

    //do
    //{
    //    switch (menuOption())
    //    {
    //    case 0: exit(1); break;
    //    case 1: //ticTacToeObject.ticTacToe(); break;
    //    case 2: //playTowerOfHanoi(); break;
    //    case 3: n_QueensMenu(); break;
    //    default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
    //    }
    //    cout << "\n";
    //    system("pause");
    //} while (true);

    return EXIT_SUCCESS;
}

//Precondition: None
//Postcondition: Returns an integer
//int menuOption()
//{
//    system("cls");
//    cout << "CMPR131 Chapter 7: Applications using Stacks by Saul Merino" << endl;
//    cout << string(100, char(205)) << endl;
//
//    cout << "1. Simple Calculator" << endl;
//    cout << string(100, char(196)) << endl;
//
//    cout << "2. Translation of Arithmetic Expression" << endl;
//    cout << string(100, char(196)) << endl;
//
//    cout << "3. n-Queens" << endl;
//    cout << string(100, char(196)) << endl;
//
//    cout << "0. Quit" << endl;
//    cout << string(100, char(205)) << endl;
//    int option = inputInteger("Option : ", 0, 3);
//    return option;
//}