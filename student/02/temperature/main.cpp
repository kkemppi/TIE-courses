#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a temperature: ";
    int input = 0;
    cin >> input;
    double input_as_f = input * 1.8 + 32;
    double input_as_c = (input - 32) / 1.8;
    cout << input << " degrees Celsius is " << input_as_f << " degrees Fahrenheit" << endl;
    cout << input << " degrees Fahrhenheit is " << input_as_c << " degrees Celsius" << endl;

    return 0;
}
