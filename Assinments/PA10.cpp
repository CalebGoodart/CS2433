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

class StudentNode {
private:
    Student student;
    StudentNode *next;

public:
    StudentNode StudnetNode() {}
    StudentNode(Student d, StudentNode* n);
    Student getStudent();
    StudentNode* getNext();
    void setStudent(Student d);
    void setNext(StudentNode* n);
    void add(StudentNode* &head, Student student);
    void print(StudentNode* head);
};




int main(){

    StudentNode* head = NULL;

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

        Student student;
        student.setVariables(tokens[0], tokens[1], atoi(tokens[2].c_str()), tokens[3], strtod(tokens[4].c_str(), NULL));

        head->add(head, student);
    }

//first print
    head->print(head);

//new data insert
    int arr[9] = {1,2,3,5,7,11,13,17};


    for (int j = 0; j < 9; ++j) {

        StudentNode* temp = head;
        for (int i = 0; i < arr[j]; ++i) {

            temp = temp->getNext();
        }



        while(true){

        temp = temp->getNext();

        }
        temp->getStudent().setGPA(5.0);
        temp->getStudent().setMajor("Computer Science");

    }


//second print
    head->print(head);
    return 0;


}


//Student class deffs
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

//class StudentNode deffs

StudentNode::StudentNode(Student d, StudentNode* n) {

    student = d;
    next = n;
}

Student StudentNode::getStudent() {
    return student;
}

StudentNode* StudentNode::getNext() {
    return next;
}

void StudentNode::setStudent(Student d) {
    student = d;
}

void StudentNode::setNext(StudentNode* n) {
    next = n;
}

void StudentNode::add(StudentNode* &head, Student student) {

    StudentNode *current = head;

//Intitailizeing the list
    if (current == NULL) {
        head = new StudentNode(student, NULL);
        return;
    }

    StudentNode *newNode = new StudentNode(student, NULL);
    StudentNode *prev = head;
    current = current->getNext();

//test for the case 1: one node in list
    if (current == NULL) {

        prev->setNext(newNode);
        newNode->setNext(current);
        return;
    }

    while (current != NULL) {

// case 2: previous is less than the new node
        if (prev->getStudent().getID() < student.getID()) {

            newNode->setNext(prev);
            head = newNode;
            return;
        }
//case 3: current is less then the new node
        if (current->getStudent().getID() < student.getID()) {
            prev->setNext(newNode);
            newNode->setNext(current);
            return;
        }
//case 4: if the new node is the smallest in the list
        if (current->getNext() == NULL){

            current->setNext(newNode);
            return;
        }

//advances prev and current nodes to the next node
        prev = prev->getNext();
        current = current->getNext();
    }

}

void StudentNode::print(StudentNode* head) {

    StudentNode* current = head;

    while (current != NULL) {

        current->getStudent().printData();
        current = current->getNext();
    }

    std::cout << std::endl;
}