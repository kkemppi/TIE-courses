#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Input file: ";
    string input_file;
    getline(cin, input_file);
    ifstream input(input_file);
    cout << "Output file: ";
    string output_file;
    getline(cin, output_file);
    if (!input){
        cout << "Error! The file " << input_file << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    ofstream output(output_file);
    string row;
    int i = 1;
    while (getline(input, row)){
        output << i << " " << row << endl;
        ++i;
    }
    input.close();
    output.close();
}
