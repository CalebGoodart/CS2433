/*
Caleb Goodart
CS2433
PA2
*/

#include <iostream>
#include <cmath>



using namespace std;

double PermCircle(double);
double PermSqurare(double);
double SACube(double);
double AreaCircle(double);
double AreaSquare(double x);
double VolSphere(double );
double VolCube(double);
double InToCm(double);

int main(){

    double n = 17.3;


    cout << "Circumference of Circle in Centimetres: " << PermCircle(n) << endl;
    cout << "Area of Circle in Centimetres: " << AreaCircle(n) << endl;
    cout << "Circumference of Circle in Inches: " << PermCircle(InToCm(n)) << endl;
    cout << "Area of Circle in Inches: " << AreaCircle(InToCm(n)) << endl;
    cout << "Volume of Sphere in Centimetres: " << VolSphere(n) << endl;
    cout << "Volume of Sphere in Inches: " << VolSphere(InToCm(n)) << endl;
    cout << "Perimeter of a Square in Centimetres: " << PermSqurare(n) << endl;
    cout << "Area of a Square in Centimetres: " << AreaSquare(n) << endl;
    cout << "Perimeter of a Square in Inches: " << PermSqurare(InToCm(n)) << endl;
    cout << "Area of a Square in Inches: " << AreaSquare(InToCm(n)) << endl;
    cout << "Surface area of Cube in Centimetres: " << SACube(n) << endl;
    cout << "Volume of Cube in Centimetres: " << VolCube(n) << endl;
    cout << "Surface area of Cube in Inches: " << SACube(InToCm(n)) << endl;
    cout << "Volume of Cube in Inches: " << VolCube(InToCm(n)) << endl;


    return 0;
}

double PermCircle(double x){
    return 2 * M_PI * x;
}

double PermSqurare(double x){
    return x * 4;
}

double SACube(double x){
    return 6 * AreaSquare(x);
}
double AreaCircle(double x){
    return M_PI * pow(x, 2);
}

double AreaSquare(double x){
    return pow(x,2);
}

double VolSphere(double x){
    return (4/3) * M_PI * pow(x, 3);
}

double VolCube(double x){
    return pow(x, 3);
}

double InToCm(double x){
    return x/2.54;
}