#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <bits/stdc++.h>

// TODO: Implement split function here
// Do not change main function


std::vector<std::string> split(std::string str, char separator, bool truth=false)
{
    std::string result_part;
    std::string& part = result_part;
    std::vector<std::string> result;
    std::string empty = "";
    std::vector<int>::size_type  size = str.size();
    size = str.size();
    for (std::string::size_type i=0; i <= size-1; ++i)  {
        if (str.at(i) == separator)
            continue;
        else if (str.at(i) != separator){
            part+=(str.at(i));
            if (i==size-1)
                result.push_back(part);
            }
        else {
        result.push_back(part);
        part = "";
        }

        }
    if (truth==false)  {
        return result;
    }
    if (truth==true)    {
        std::string::size_type true_size = result.size();
        std::string::size_type& size_ref = true_size;
        for (std::string::size_type i=0; i < true_size-1; ++i)  {
            if (result.at(i)==empty){
                auto it = result.begin()+i;
                result.erase(it);
                size_ref -= 1;
                i=0;
            }
        }
        return result;
    }


}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
