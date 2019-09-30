#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    cout << "Input file: ";
    string input_file;
    getline(cin, input_file);
    ifstream input(input_file);
    string row;
    map<string, int> points_sum;
    if (!input) {
        cout << "Error! The file " << input_file <<  " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    while (getline(input, row)){
        int index = row.find(':');
        int len = row.length();
        string name = row.substr(0, index);
        string points = row.substr(index+1, len-index);
        int point = stoi(points);
        if (points_sum.find(name) != points_sum.end()){
            points_sum.at(name) = points_sum.at(name) + point;
        }else{
            points_sum.insert({name, point});
        }
    }
    cout << "Final scores:" << endl;
    map<string, int>::iterator it = points_sum.begin();
    while (it != points_sum.end()){
        cout << it->first << ": " << it->second << endl;
        ++it;
    }
}
