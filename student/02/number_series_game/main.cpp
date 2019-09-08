#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";
    int amount = 0;
    std::cin >> amount;
    for ( int num = 1; num < amount+1; ++num ) {
        std::cout << num << std::endl;
    }
}
