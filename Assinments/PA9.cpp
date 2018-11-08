/*
Caleb Goodart
CS2433
PA91
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>


struct student{
    std::string firstName;
    std::string lastName;
    std::string hometown;
    std::string state;
    std::string year;
    std::string major;

};

bool test(student, student);

int main(){

    int arrSize = 18;
    student students[arrSize];

    std::ifstream input;
    std::ofstream output;
    std::string word;

    input.open("indata9.txt");
    output.open("outdata9.txt");



    for (int i = 0; !(input.eof()); ++i) {


        getline(input, word);
        std::stringstream ss(word);
        std::string temp;
        std::vector<std::string> tokens;

        //brakes the line into strings by spaces and puts them into a vector
        while(getline(ss, temp, ' ')){

            tokens.push_back(temp);
        }

            students[i].firstName = tokens[0];
            students[i].lastName = tokens[1];
            students[i].hometown = tokens[2];
            students[i].state = tokens[3];
            students[i].year = tokens[4];
            students[i].major = tokens[5];

    }

    //sort

    std::string string1, string2;
    int  x, j;

    student temp1, temp2;

    for (x = 1; x < arrSize; x++){

        temp1 = students[x];
        j = x-1;

        while(j >= 0 && test(temp1, students[j])){

            students[j+1] = students[j];
            j = j-1;
        }
        students[j+1] = temp1;
    }

    //print
    for (int k = 0; k < 18; ++k) {

        std::cout << students[k].firstName + ' ';
        std::cout << students[k].lastName + ' ';
        std::cout << students[k].hometown + ' ';
        std::cout << students[k].state + ' ';
        std::cout << students[k].year + ' ';
        std::cout << students[k].major;
        std::cout << std::endl;

        output << students[k].firstName + ' ';
        output << students[k].lastName + ' ';
        output << students[k].hometown + ' ';
        output << students[k].state + ' ';
        output  << students[k].year + ' ';
        output << students[k].major;
        output << std::endl;

    }

    input.close();
    output.close();
}

// test which name is alphabetically first by first testing if the last names are the same, then testing char by char
bool test(student student1, student student2) {

    std::string string1, string2;

    string1 = student1.lastName;
    string2 = student2.lastName;
    if (string1 == string2){

        string1 = student1.firstName;
        string2 = student2.firstName;
    }

    for (int i = 0; i < string1.size() && i < string2.size(); ++i) {

        int one = toupper(string1[i]);
        int two = toupper(string2[i]);

        if (one < two){
            return true;

        } else if ( two < one) {
            return false;
        }
    }
}

