#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

const std::string HELP_TEXT = "S = store id1 i2\n P = print id\n"
                              "C = count id\n D = depth id";


std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void print(std::map<std::string, std::vector<std::string>> network, std::string id, std::string dots)
{
    for (std::string name : network.at(id)){
        std::cout << dots << name << std::endl;
        if (!network.at(name).empty()){
            dots += "..";
            print(network, name, dots);
            dots = dots.substr(0, dots.length()-2);
        }else{
            dots = "..";
        }
    }
}

void count(std::map<std::string, std::vector<std::string>> network, std::string id, int& sum)
{
    for (std::string name : network.at(id)){
        sum++;
        if (!network.at(name).empty()){
            count(network, name, sum);
        }
    }
}


void depth(std::map<std::string, std::vector<std::string>> network, std::string id, int& biggest, int counter = 0){
    for (std::string name : network.at(id)){
        counter++;
        if (!network.at(name).empty()){
            depth(network, name, biggest, counter);
        }
        else if(counter > biggest){
            biggest = counter;
            counter = 0;
        }else{
            counter = 0;
        }
    }
}

int main()
{
    // TODO: Implement the datastructure here

    std::map<std::string, std::vector<std::string>> network;
    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);
            if (network.find(id1) != network.end()){
                network.at(id1).push_back(id2);
                network.insert({id2, {}});
            }else{
                std::vector<std::string> vec = {id2};
                network.insert({id1, vec});
                network.insert({id2, {}});
            }

        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);
            std::cout << id << std::endl;
            print(network, id, "..");

        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            int sum = 0;
            std::string id = parts.at(1);
            count(network, id, sum);
            std::cout << sum << std::endl;

        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);
            int biggest = 0;
            depth(network, id, biggest);
            std::cout << 1 + biggest << std::endl;

        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
