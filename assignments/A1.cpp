#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    float x,y,Sum,Difference,Product,Quotient;

    // input 
    cout <<"Enter first number";
    cin >>x;
    cout <<"Enter second number";
    cin >>y;

    //formulas for calculations
     Sum = (x+y);
     Difference = (x-y);
     Product = (x*y);
     Quotient = (x/y);

    // setting decimal places
    cout << fixed << setprecision(3);
   
    // results
    cout << "Sum =" << Sum << endl;
    cout << "Difference =" << Difference << endl;
    cout << "Product =" << Product << endl;
    cout << "Quotient =" << Quotient << endl;
    // Output is displayed with same data type and upto excatly 3 decimal places 

    //Explicit type casting will be done to convert the output from float data type to integer data type and display output in "int" data type
    cout << endl;
    int Sum1 = (int)x + (int)y;
    int Difference1 = (int)x - (int)y;
    int Product1 = (int)x * (int)y;
    int Quotient1  = (int)x / (int)y;

    //output after casting
    cout<<endl;
    cout << " The Sum of the two numbers after type casting is =" << Sum1 << endl;
    cout << " The Difference of the two numbers after type casting is =" << Difference1 << endl;
    cout << "The Product of the two numbers after type casting is =" << Product1 << endl;
    cout << "The Quotient of the two numbers after type casting is =" << Quotient1 << endl;
    //All the calculations have been performed 
    
    return 0;     
}  
