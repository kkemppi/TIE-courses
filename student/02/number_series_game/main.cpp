#include <iostream>
using namespace std;

int main()
{
    cout << "How many numbers would you like to have? ";
    int amount = 0;
    cin >> amount;
    {
    for ( int num = 1; num < amount+1; ++num )
        if ( num % 3 == 0)
            cout << "zip"<< endl;
        else cout << num << endl;
    }
}

