#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
    int length = s.length();
    char end = s.back();
    char first = s.front();
    if (length <= 1){
      return true;
    }
    else if (length == 2 && end == first){
        return true;
    }else{
        if (end == first){
            return palindrome_recursive(s.substr(1, length-2));
        }
        else if (end != first){
            return false;
        }
    }
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif


// deleveled
