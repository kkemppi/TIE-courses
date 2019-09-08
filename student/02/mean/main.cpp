#include <iostream>
using namespace std;

int main()
{
    cout << "From how many integer numbers you want to count the mean value? ";
    int amount = 0;
    cin >> amount;
    double sum = 0;
    double avg = 0;
    double value = 0; {
        if (amount > 0) {
            for (int num = 0; num < amount; ++num ) {
                cout << "Input " << num+1 << ". number: ";
                cin >> value;
                sum = sum + value;
            }
            avg = sum / amount;
            cout << "Mean value of the given numbers is " << avg << endl;
        }
        else {
            cout << "Cannot count mean value from " << amount << " numbers" << endl;
        }
    }


}
