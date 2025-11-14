#include<iostream>
using namespace std; 
 int primenumber(int n);



 int main(){
 int num;
cout <<"Enter a number"<<endl;
cin>>num;
bool answer =primenumber(num);
cout<<endl;
cout<<answer;
return 0; 
}







 bool primenumber(int n){
    if (n%2==0){
     return true;
    }
    else 
    {
      return false;
    }
 
      
}