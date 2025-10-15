#include<iostream>
using namespace std;
int main()
{
    int x,y;
    //declared two variables.
    cout<<"Enter first number: ";
    cin>>x;
    cout<<"Enter second number:";
    cin>>y;
    //taking input from user.
    x=x+y;
    y=x-y;
    x=x-y;
    //using operators to swap values of two variables.
    cout<<"First Number= "<<x<<endl<<"Second Number= "<<y;
    return 0;
}