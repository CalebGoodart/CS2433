/*
Caleb Goodart
CS2433
PA4
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main(){

    ofstream output;
    ifstream input;

    input.open("indata.txt");
    output.open("outdata.txt");

    string word;

    while(!(input.eof())){

        getline(input, word);
        stringstream ss(word);
        string temp;
        vector<string> tokens;

        while(getline(ss, temp, ' ')){

            tokens.push_back(temp);
        }

        cout << tokens[tokens.size()-1] << ", ";
        output << tokens[tokens.size() - 1] << ", ";

        cout << tokens[tokens.size()-2];
        output << tokens[tokens.size() - 2];

        cout << endl;
        output << endl;
    }

    output.close();
    input.close();

    return 0;
}