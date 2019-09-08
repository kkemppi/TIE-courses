#include <iostream>
using namespace std;

int main()
{
    cout << "How many numbers would you like to have? ";
    int amount = 0;
    cin >> amount;
    int num = 1;
    {
    for ( num = num; num < amount+1; ++num ) {
        if ( num % 7 == 0 && num % 3 == 0)
                    cout << "zip boing"<< endl;
        else if ( num % 3 == 0)
            cout << "zip"<< endl;
        else if ( num % 7 == 0)
            cout << "boing"<< endl;
        else cout << num << endl;
        }
    }
}

