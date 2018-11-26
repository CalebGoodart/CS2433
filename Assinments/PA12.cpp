/*
Caleb Goodart
CS2433
PA12
*/

#include <string>
#include <iostream>


int fibRecur(int);
long int fibIter(long int);

int main(){

    std::cout << fibIter(50) << std::endl;
}

int fibRecur(int n){


    if ( n == 1){
        return 1;
    }else if (n == 2){
        return 1;
    }else{

        if (n-1 != 2 && n-2 != 1){
            std::cout << n - 1 <<std::endl;
        }

        return fibRecur(n - 1) + fibRecur( n - 2);
    }

}

long int fibIter(long int n){
    long int fibs[n + 1];

    fibs[1] = 1;
    fibs[2] = 1;

    for (int i = 3; i < n + 1; i++){
        fibs[i] = ( fibs[i - 1] + fibs[i -2]);
    }

    for (int i = 1; i < n; i++){

        std::cout << fibs[i] << std::endl;
    }
    return fibs[n];
}