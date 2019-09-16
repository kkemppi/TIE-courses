#include <iostream>

using namespace std;

bool ball_amounts(int drawn, int balls)
{
    if (balls <= 0) {
        cout << "The number of balls must be a positive number." << endl;
        return false;
    }
    else if (drawn > balls) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        return false;
    }
    else
        return true;

}

unsigned long int factorial(int n)
{
    unsigned long int factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
    return factorial;
}
unsigned long int chance(int drawn, int balls)
{
    unsigned long int chance;
    chance = factorial(balls)/(factorial(balls-drawn)*factorial(drawn));
    return chance;
}

int main()
{
    cout << "Enter the total number of lottery balls: ";
    int balls = 0;
    cin >> balls;
    cout << "Enter the number of drawn balls: ";
    int drawn = 0;
    cin >> drawn;
    if (ball_amounts(drawn, balls) == false)
        return 1;
    else {
        cout << "The probability of guessing all " << drawn <<  " balls correctly is 1/" << chance(drawn, balls) << endl;
    }
}

