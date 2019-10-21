#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// The most magnificent function in this whole program.
// Prints a RASSE
void print_rasse()
{
    std::cout <<
                 "=====//==================//===\n"
                 "  __<<__________________<<__   \n"
                 " | ____ ____ ____ ____ ____ |  \n"
                 " | |  | |  | |  | |  | |  | |  \n"
                 " |_|__|_|__|_|__|_|__|_|__|_|  \n"
                 ".|                  RASSE   |. \n"
                 ":|__________________________|: \n"
                 "___(o)(o)___(o)(o)___(o)(o)____\n"
                 "-------------------------------" << std::endl;
}

std::vector<std::string> split(const std::string& s, char delimiter = ';'){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not tmp.empty())
    {
        result.push_back(tmp);
    }
    return result;
}

bool routing(std::map<std::string, std::vector<std::string>>& route, std::string inp)
{
    std::ifstream file(inp);
    std::string row;
    while(getline(file, row)){
        if (count(row.begin(), row.end(),';')!=1){
            return false;
        }
        else{
            std::vector<std::string> parts = split(row);
            std::string line = parts.at(0);
            std::string station = parts.at(1);
            if (route.count(line)>0){
                route.at(line).push_back(station);
            }
            else{
                std::vector <std::string> state = {station};
                route.insert({line,state});
            }
        }
    }
    return true;
}

void lines(std::map<std::string, std::vector<std::string>>& routes)
{

}

void stations(std::map<std::string, std::vector<std::string>>& routes)
{

}

void addstation(std::map<std::string, std::vector<std::string>>& routes, std::string route, std::string new_stop, std::string next_stop)
{

}

void line(std::map<std::string, std::vector<std::string>>& routes, std::string route)
{

}

void station(std::map<std::string, std::vector<std::string>>& routes, std::string stop)
{

}

void addline(std::map<std::string, std::vector<std::string>>& routes, std::string route)
{

}

void remove(std::map<std::string, std::vector<std::string>>& routes, std::string stop)
{

}


// Short and sweet main.
int main()
{
    std::map<std::string, std::vector<std::string>> routes;
    print_rasse();
    std::string inp;
    std::cout << "Give a name for input file: ";
    std::getline(std::cin, inp);
    std::ifstream file(inp);
    if ( not file ) {
        std::cout << "Error: File could not be read." << std::endl;
        return EXIT_FAILURE;
    }
    else if (!routing(routes, inp)){
        std::cout << "Error: Invalid format in file." << std::endl;
        return EXIT_FAILURE;
    }else{
        while (true){
            std::cout << "tramway>";
            std::string input;
            std::getline(std::cin, input);
            if (input.find(' ') == std::string::npos){
                if (input == "LINES"){
                    lines(routes);
                }else if (input == "STATIONS"){
                    stations(routes);
                }else{
                    if (input == "QUIT"){
                        return EXIT_SUCCESS;
                    }
                    std::cout << "Error: Invalid input." << std::endl;
                    continue;
                }
            }else{
                std::vector<std::string> inputs;
                inputs = split(input, ' ');
                if (inputs.size() == 4){
                    if (inputs.at(0) == "ADDSTATION"){
                        addstation(routes, inputs.at(1), inputs.at(2), inputs.at(3));
                    }else{
                        std::cout << "Error: Invalid input." << std::endl;
                        continue;
                    }
                }
                else if (inputs.size() == 2){
                    if (inputs.at(0) == "LINE"){
                        line(routes, inputs.at(1));
                    }
                    else if (inputs.at(0) == "STATION"){
                        station(routes, inputs.at(1));
                    }
                    else if (inputs.at(0) == "ADDLINE"){
                        addline(routes, inputs.at(1));
                    }
                    else if (inputs.at(0) == "REMOVE"){
                        remove(routes, inputs.at(1));
                    }else{
                        std::cout << "Error: Invalid input." << std::endl;
                        continue;
                    }
                }
            }
        }

    }
    return EXIT_SUCCESS;
}
