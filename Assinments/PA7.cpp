/*
Caleb Goodart
CS2433
PA7
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

//Defining functions and constants;
double GregToJDN(vector<int>);
string Weekday(int);

vector<int> BASE_DATE;
string WEEKDAY[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int main(){

    //Establish base date for JDN calculation
    BASE_DATE.push_back(10);
    BASE_DATE.push_back(15);
    BASE_DATE.push_back(1582);

    ofstream output;
    ifstream input;

    input.open("indata7.txt");
    output.open("outdata7.txt");

    string inLine;

    //take lines of input until it reaches the end of file, computes JDN and finds day of the week
    while(!(input.eof())){


        getline(input, inLine);
        stringstream ss(inLine);
        string temp;
        vector<int> tokens;

        //brakes the string into strings by spaces and puts them into a vector as ints
        while(getline(ss, temp, ' ')){

            tokens.push_back((int)strtof(temp.c_str(), NULL));
        }
        cout << Weekday((int)GregToJDN(tokens) + 1) << endl;
        // +1 is for rounding up to get the correct day from calculation (.5 rounds down when converted to int)
    }

    output.close();
    input.close();

    return 0;
}


double GregToJDN(vector<int> date){

    long intRes1 = 0;
    double intRes2;
    double intRes3;

    int month = date[0];
    int day = date[1];
    int year = date[2];
    if ( (year <= BASE_DATE[2]) && (month <= BASE_DATE[1]) && (day <= BASE_DATE[0]) ){

        intRes1 = 2 * year / 100 + year / 400;
    }

    intRes2 = (365.25 * year);
    intRes3 = (30.6001 * (month + 1));
    return (intRes1 + intRes2 + intRes3 + day + 1720994.5);
}

string Weekday(int JDN){

    return WEEKDAY[(JDN + 1) % 7];
}