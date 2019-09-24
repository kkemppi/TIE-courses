#include <iostream>
#include <string>
#include <vector>
#include <string>
// TODO: Implement split function here
// Do not change main function


std::vector<std::string> split(std::string str, char token, bool truth=false){
    std::vector<std::string>result;
    while(str.size()){
        unsigned long int index = str.find(token);
        unsigned long int a = std::string::npos;
        if(index!= a){
            result.push_back(str.substr(0,index));
            str = str.substr(index+1);
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    if(truth){
        int b = (result.size());
        std::vector <std::string> withoutspaces;
        for(int i=0; i<b; ++i){
            std::string word = result.at(i);
            if(word == ""){
            }else{
                withoutspaces.push_back(result.at(i));
            }
        }
        return withoutspaces;
    }
    return result;
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
