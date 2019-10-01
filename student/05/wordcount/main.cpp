#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>

std::vector<std::string> split(std::string str, char separator = ' ')
{
    std::string result_part;
    std::string& part = result_part;
    std::vector<std::string> result;
    std::string empty = "";
    std::vector<int>::size_type  size = str.size();
    size = str.size();
    for (std::string::size_type i=0; i <= size-1; ++i)  {
        if (str.at(i) == separator){
            result.push_back(part);
            part.clear();
            continue;
        }
        else if (str.at(i) != separator){
            part+=(str.at(i));
            if (i==size-1)
                result.push_back(part);
            }
    }
    return result;
}



int main()
{
    std::cout << "Input file: ";
    std::string input_file;
    std::getline(std::cin, input_file);
    std::ifstream input(input_file);
    if (!input){
        std::cout << "Error! The file " << input_file << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    std::map<std::string, std::vector<int>> word_at_rows;
    std::vector<std::string> words_in_row;
    std::string row;
    int rivi = 0;
    while (getline(input, row)){
        ++rivi;
        words_in_row = split(row);
        for (std::string word : words_in_row){
            if (word_at_rows.find(word) != word_at_rows.end()){
                if (find(word_at_rows.at(word).begin(), word_at_rows.at(word).end(), rivi) == word_at_rows.at(word).end()){
                    word_at_rows.at(word).push_back(rivi);
                }
            }else{
                word_at_rows.insert({word, {rivi}});
            }
        }
    }
    std::map<std::string, std::vector<int>>::iterator iter = word_at_rows.begin();
    while (iter != word_at_rows.end()){
        std::cout << iter->first << " " << iter->second.size() << ": ";
        std::cout << iter->second.at(0);
        iter->second.erase(iter->second.begin());
        for (int row_num : iter->second){
            std::cout << ", " << row_num;
        }
        std::cout << std::endl;
        ++iter;
    }

}
