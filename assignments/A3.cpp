
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    //declared three variables.
    cout<<"Enter Three Numbers"<<endl;
    cin>>a>>b>>c;
    //taking input from user.
    if(a>b && a>c)
        cout<<"The Largest Number is "<<a<<endl;
    else if(b>a && b>c)
        cout<<"The Largest Number is "<<b<<endl;
    else if(c>a && c>b)
        cout<<"The Largest Number is "<<c<<endl;
    else
         cout<<"All Numbers Are Equal"<<endl;
    if(a<b && a<c)
        cout<<"The Smallest Number is "<<a<<endl;
    else if(b<a && b<c)
        cout<<"The Smallest Number is "<<b<<endl;
    else if(c<a && c<b)
        cout<<"The Smallest Number is "<<c<<endl;
        if(a!=b && a!=c && b!=c)
            cout<<"All Numbers Are Different"<<endl;
        else
            cout<<"All Numbers Are Equal"<<endl;
    //used condition to determine the largest and smallest number among three numbers or whether all are equal.
        return 0;
}
