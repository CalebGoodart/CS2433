/*
Caleb Goodart
CS2433
PA6
*/


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(){

    ifstream input;
    input.open("indata2.txt");

    float max = 0;
    float min = 0;
    float avg;
    float sum = 0;
    int count = 0;

    while (!(input.eof())){

        string temp;
        getline(input,temp);
        float grade = strtof(temp.c_str(), NULL);

        if ( grade != -1){

            count++;
            sum += grade;

            if (grade > max){
                max = grade;
            }
            if (grade > min){
                min = grade;
            }
        } else{

            grade = sum / count;
            cout << "Lowest Score: " << min << endl;
            cout << "Largest Score: " << max << endl;
            cout << "Average grade: ";
        }


        if ( grade >= 90){
            cout << "A- " << grade << endl;

        }else if ( grade >= 80){
            cout << "B - " << grade << endl;

        }else if (grade >= 70){
            cout << "C - " << grade << endl;

        }else if (grade >= 60){
            cout << "D - " << grade << endl;

        }else{
            cout << "F - " << grade << endl;
        }
    }

 return 0;
}