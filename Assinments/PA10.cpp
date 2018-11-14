/*
Caleb Goodart
CS2433
PA10
*/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

const int arrSize = 18;// the size of the student array

class Student{
private:
    std::string lastName;
    std::string firstName;
    std::string major;
    int studentid;
    double gpa;
public:
    void setVariables(std::string, std::string, int, std::string, double);
    void setMajor(std::string);
    int getID();
    void setGPA(double gpa);
    void clearAllData();
    void printData();


}students[arrSize];

int main(){

    std::ifstream input;
    std::ofstream output;
    std::string word;

    input.open("indata10.txt");
    output.open("outdata10.txt");

//data input
    for (int i = 0; !(input.eof()); ++i) {

        getline(input, word);
        std::stringstream ss(word);
        std::string temp;
        std::vector<std::string> tokens;
        //brakes the line into strings by spaces and puts them into a vector
        while(getline(ss, temp, ' ')){

            tokens.push_back(temp);
        }
        students[i].setVariables(tokens[0], tokens[1], atoi(tokens[2].c_str()), tokens[3], strtod(tokens[4].c_str(), NULL));
    }


    //sort by studentid
    int  x, j;
    Student temp1;

    for (x = 1; x < arrSize; x++){

        temp1 = students[x];
        j = x-1;

        while(j >= 0 && students[j].getID() < temp1.getID()){

            students[j+1] = students[j];
            j = j-1;
        }
        students[j+1] = temp1;
    }

    //frist print
    for (int i = 0; i < arrSize; i++){

        students[i].printData();
    }

    std::cout << "\n" << std::endl;
    int arr[8] = {1,2,3,5,7,11,13,17};   //what number in the array to change student data

            //changeing data for major and gpa
    for (int k = 0; k < 8; k++){
        students[arr[k]].setGPA(4.0);
        students[arr[k]].setMajor("CS");

    }

    // second print
    for (int i = 0; i < arrSize; i++){

        students[i].printData();
    }

    return 0;
}


//functions
// functions do as named
void Student::setVariables(std::string first, std::string last, int studentid, std::string major, double gpa){
    this->firstName = first;
    this->lastName = last;
    this->major = major;
    this->studentid = studentid;
    this->gpa = gpa;
}

void Student::clearAllData() {
    this->firstName = "";
    this->lastName = "";
    this->major = "";
    this->studentid = 0;
    this->gpa = 0;
}

void Student::setGPA(double gpa){

    this->gpa = gpa;
}

void Student::setMajor(std::string major) {

    this->major = major;
}

void Student::printData() {

    std::cout << this->firstName << " ";
    std::cout << this->lastName << " ";
    std::cout << this->studentid << " ";
    std::cout << this->major << " ";
    std::cout << this->gpa;
    std::cout << std::endl;
}

int Student::getID() {
    return this->studentid;
}
