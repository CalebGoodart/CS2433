/*
Caleb Goodart
CS2433
PA12
*/

#include <string>
#include <iostream>


double fibRecur(double);

int main(){

   int arr[50];

    for (int i = 1; i <= 50; ++i) {
        std::cout << fibRecur(i) << std::endl;


    }
}

double fibRecur(double n){


    if ( n == 1 || n == 2 ){
        return 1;
    }else{
        return fibRecur(n - 1) + fibRecur( n - 2);
    }

}