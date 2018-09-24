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
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){

    ifstream input;
    ofstream output;

    input.open("indata1.txt");
    output.open("outdata1.txt");

    string money;
    double total;

    //sets the precision of the number in the output so the have 2 decimal places
    cout << fixed;
    cout << setprecision(2);

    output << fixed;
    output << setprecision(2);

    cout << "Denomination\tNumber\tAmount\n";
    cout << "------------------------------\n";

    output << "Denomination\tNumber\tAmount\n";
    output << "------------------------------\n";

    //take lines of input until it reaches the end of file and outputs formatted output
    while(!(input.eof())){

        getline(input, money);
        float tender;
        float amount;
        char* mid;

        //splits the string and converts it to a float
        tender = strtof(money.c_str(), &mid);
        amount = strtof(mid, NULL);
        total += (tender * amount);

        //prints formated output;
       cout << tender << setw(17) << amount << setw(10) << tender * amount << endl;
       output << tender << setw(17) << amount << setw(10) << tender * amount << endl;
    }

    cout << "------------------------------\n";
    cout << " Total" << setw(18) <<  "$  "  << total << endl;

    output << "------------------------------\n";
    output << " Total" << setw(18) <<  "$  "  << total << endl;

    output.close();
    input.close();

    return 0;
}