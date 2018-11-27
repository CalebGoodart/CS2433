/*
Caleb Goodart
CS2433
PA12
*/

#include <string>
#include <iostream>


double fibRecur(int);

//array to keep track of fib nums
double mem[51];

int main(){

    for (int i = 1; i <= 50; ++i) {
        std::cout << fibRecur(i) << std::endl;
    }
}

double fibRecur(int n){

    if ( n <= 1 ){
        return 1;

        //checks if fib num is in memory, if so returns the num in mem
    }else if (mem[n] != 0) {
        return mem[n];
    }else{

        //if the fib is not in mem, it gets added and returns the num in mem
        mem[n] = fibRecur(n - 1) + fibRecur( n - 2);
        return mem[n];
    }

}