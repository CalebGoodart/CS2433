/*
Caleb Goodart
CS2433
PA12
*/

#include <string>
#include <iostream>


double fibRecur(int);

//array to keep track of fib nums
double mem[50];

int main(){
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;


    for (int i = 0; i <= 50; ++i) {
        std::cout << fibRecur(i) << std::endl;
        if (i == 50){
            std::cout << fibRecur(i) << " is the 50th term" << std::endl;
        }
    }
}

double fibRecur(int n){


    if(n == 0){
        mem[n] = 0;
    }else if(n == 1 || n == 2){
        mem[n] = 1;
    }else if (mem[n] != 0) {
        return mem[n];
    }else{

        //if the fib is not in mem, it gets added and returns the num in mem
        mem[n] = fibRecur(n - 1) + fibRecur( n - 2);
        return mem[n];
    }

}