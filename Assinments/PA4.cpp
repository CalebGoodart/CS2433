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

using namespace std;

int main(){

    ofstream output;
    ifstream input;

    input.open("indata.txt");
    output.open("outdata.txt");

    string word;

    //take lines of input until it reaches the end of file and outputs formatted output
    while(!(input.eof())){

        getline(input, word);
        stringstream ss(word);
        string temp;
        vector<string> tokens;

        //brakes the string into strings by spaces and puts them into a vector
        while(getline(ss, temp, ' ')){

            tokens.push_back(temp);
        }

        //prints the names to the output file and to the terminal in the proper format
        for (int i = 0; i < tokens.size(); ++i) {

            if (i == 0){

                cout << tokens[i] << ", ";
                output << tokens[i] << ", ";
            } else{

                cout << tokens[i];
                output << tokens[i];
            }
        }

        cout << endl;
        output << endl;
    }

    output.close();
    input.close();

    return 0;
}