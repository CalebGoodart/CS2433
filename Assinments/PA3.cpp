/*
Caleb Goodart
CS2433
PA2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    //base inputs
    int emplid = 12345;
    string name = "John Doe";
    string lastname = "Last";
    double wage = 123;
    double hours = 40;
    float SS_W = .625;
    float TAX_RATE = .17;

    //calculations for data
    double grosspay = wage * hours;
    double withheldTax = (grosspay * TAX_RATE) + (grosspay * SS_W);
    double netpay = grosspay - withheldTax;

    //base number to offset space between data
    int i = 20;
    cout << "Employee id:" << setw(i-9) << emplid << endl;
    cout << "Name:" << setw(i+1) << name << endl;
    cout << "Wage:" << setw(i-4) << wage << endl;
    cout << "Hours:" << setw(i-6) << hours << endl;
    cout << "Gross Pay:" << setw(i-8) << grosspay << endl;
    cout << "Tax Withheld:" << setw(i-9) << withheldTax << endl;
    cout << "Net Pay:" << setw(i-4) << netpay << endl;

    return 0;
}

