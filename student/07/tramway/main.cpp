#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

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
    std::string old_part;
    std::string final;
    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (new_part.empty())){
            if(new_part.front()=='"'){
                if(new_part.back() == '"'){
                    result.push_back(new_part.substr(1, new_part.size()));
                }else{
                    old_part = new_part;
                }
            }else if(new_part.back()=='"'){
                final = old_part + " " + new_part;
                result.push_back(final.substr(1, final.size()-2));
                old_part.clear();
                final.clear();
            }else{
                result.push_back(new_part);
            }
        }
    }
    if(not tmp.empty()){
        if(tmp.front()=='"'){
            result.push_back(tmp.substr(1, tmp.size()-2));
        }else if(tmp.back()=='"'){
            final = old_part + " " + tmp;
            result.push_back(final.substr(1, final.size()-2));
        }else{
            result.push_back(tmp);
        }
    }
    return result;
}

void routing(std::map<std::string, std::vector<std::string>>& route, std::string inp)
{
    std::ifstream file(inp);
    std::string row;
    while(getline(file, row)){
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


// Check if station exists
bool is_Station(std::map<std::string, std::vector<std::string>>& routes, std::string stop)
{
    std::map<std::string, std::vector<std::string>>::iterator iter = routes.begin();
    while (iter != routes.end()){
        for (std::string station : iter->second)
            if (station == stop){
                return true;
            }
        ++iter;
    }
    return false;
}

void lines(std::map<std::string, std::vector<std::string>>& routes)
{
    std::cout << "All tramlines in alphabetical order:" << std::endl;
    std::vector<std::string> lines = {};
    std::map<std::string, std::vector<std::string>>::iterator iter = routes.begin();
    while (iter != routes.end()){
        lines.push_back(iter -> first);
        ++iter;
    }
    std::sort (lines.begin(), lines.end());
    for (std::string line : lines){
        std::cout << line << std::endl;
    }
}

void stations(std::map<std::string, std::vector<std::string>>& routes)
{
    std::cout << "All stations in alphabetical order:" << std::endl;
    std::map<std::string, std::vector<std::string>>::iterator iter = routes.begin();
    std::set<std::string> all_stops = {};
    std::vector<std::string> stops_vector = {};
    while (iter != routes.end()){
        for (std::string stop : iter -> second){
            all_stops.insert(stop);
        }
        ++iter;

    }
    std::set<std::string>::iterator set_iter = all_stops.begin();
    while (set_iter != all_stops.end()){
        stops_vector.push_back(*set_iter);
        ++set_iter;
    }
    std::sort (stops_vector.begin(), stops_vector.end());
    for (std::string stop : stops_vector){
        std::cout << stop << std::endl;
    }
}

void addstation(std::map<std::string, std::vector<std::string>>& routes, std::string route, std::string new_stop, std::string next_stop = "")
{
    if (routes.find(route) == routes.end()){
        std::cout << "Error: Line could not be found." << std::endl;
    }
    else if (std::find(routes.at(route).begin(), routes.at(route).end(), new_stop) != routes.at(route).end()){
        std::cout << "Error: Station/line already exists." << std::endl;
    }else{
        std::vector<std::string>::iterator iter = std::find(routes.at(route).begin(), routes.at(route).end(), next_stop);
        routes.at(route).insert(iter, new_stop);
        std::cout << "Station was added." << std::endl;
    }
}

void line(std::map<std::string, std::vector<std::string>>& routes, std::string route)
{
    if (routes.find(route) == routes.end()){
        std::cout << "Error: Line could not be found." << std::endl;
    }else{
        std::cout << "Line " << route <<" goes through these stations in the order they are listed:" << std::endl;
        for (std::string stop : routes.at(route)){
            std::cout << "- " << stop << std::endl;
        }
    }
}

void station(std::map<std::string, std::vector<std::string>>& routes, std::string stop)
{
    if (!is_Station(routes, stop)){
        std::cout << "Error: Station could not be found." << std::endl;
    }else{
        std::cout << "Station " << stop << " can be found on the following lines:" << std::endl;
        std::vector<std::string> stops = {};
        std::map<std::string, std::vector<std::string>>::iterator iter = routes.begin();
        while (iter != routes.end()){
            if (find(iter->second.begin(), iter->second.end(), stop) != iter->second.end()){
                stops.push_back(iter -> first);
            }
            ++iter;
        }
        std::sort(stops.begin(), stops.end());
        for (std::string stop : stops){
            std::cout << "- " << stop << std::endl;
        }
    }
}

void addline(std::map<std::string, std::vector<std::string>>& routes, std::string route)
{
    if(routes.find(route) == routes.end()){
        std::vector<std::string> s = {};
        routes.insert({route,s});
        std::cout << "Line was added." << std::endl;
    }
    else{
        std::cout << "Error: Station/line already exists." << std::endl;
    }
}

void remove(std::map<std::string, std::vector<std::string>>& routes, std::string stop)
{
    if (!is_Station(routes, stop)){
        std::cout << "Error: Station could not be found." << std::endl;
    }else{
        std::map<std::string, std::vector<std::string>>::iterator iter = routes.begin();
        while (iter != routes.end()){
            if (std::find(iter->second.begin(), iter->second.end(), stop) != iter->second.end()){
                iter->second.erase(std::find(iter->second.begin(), iter->second.end(), stop));
            }
            ++iter;
        }
        std::cout << "Station was removed from all lines." << std::endl;
    }
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
    std::string row;
    if ( not file ) {
        std::cout << "Error: File could not be read." << std::endl;
        return EXIT_FAILURE;
    }
    while(getline(file, row)){
        if (count(row.begin(), row.end(),';')!=1){
            std::cout << "Error: Invalid format in file." << std::endl;
            return EXIT_FAILURE;
        }
    }
    routing(routes, inp);
    while (true){
        std::cout << "tramway> ";
        std::string input;
        std::getline(std::cin, input);
        if (input.find(' ') == std::string::npos){
            std::transform(input.begin(), input.end(), input.begin(), ::toupper);
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
            std::transform(inputs.at(0).begin(), inputs.at(0).end(), inputs.at(0).begin(), ::toupper);
            if (inputs.at(0) == "ADDSTATION"){
                if (inputs.size() == 4){
                    addstation(routes, inputs.at(1), inputs.at(2), inputs.at(3));
                }
                else if (inputs.size() == 3){
                    addstation(routes, inputs.at(1), inputs.at(2));
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
            }else{
                std::cout << "Error: Invalid input." << std::endl;
                continue;
            }
        }
    }

    return EXIT_SUCCESS;
}
