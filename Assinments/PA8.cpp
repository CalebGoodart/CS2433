//
// Created by cgoodart on 10/25/18.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <cstdlib>

int main(){

    std::ifstream input;
    std::ofstream output;

    input.open("indata8.txt");
    output.open("outdata8.txt");

    std::stack <int> stack;

    //get input from input file and puts it into a stack
    while(!(input.eof())){

        std::string temp;
        getline(input, temp);
        int num = std::atoi(temp.c_str());
        stack.push(num);
    }


    // converts stack into array of size of stack
    int arr[stack.size()];
    int a = stack.size();

    for (int i = 0; i < a; i++){

        arr[i] = stack.top();
        stack.pop();
    }

    //insertion sort
    int temp1, x, j;
    for (x = 1; x < a; x++){

        temp1 = arr[x];
        j = x-1;

        while(j >= 0 && arr[j] < temp1){

         arr[j+1] = arr[j];
         j = j-1;
        }
        arr[j+1] = temp1;
    }

    //testing for the number 13 and printing all results
    bool has13 = false;
    for (int i =0; i < a; i++){
        if (arr[i] == 13){
            has13 = true;
        }
        std::cout << arr[i] << std::endl;
        output << arr[i] << std::endl;
    }

    if (has13){

        std::cout << "This array does contain the number 13" << std::endl;
        output << "This array does contain the number 13" << std::endl;
    }else{

        std::cout << "This array does not contain the number 13" << std::endl;
        output << "This array does not contain the number 13" << std::endl;
    }

    return 0;
}