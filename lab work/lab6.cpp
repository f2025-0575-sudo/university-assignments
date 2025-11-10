#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    do  {
     cout<<"Enter password";
     cin>>password;
    if (password == "Python123") {
      cout<<"Password is correct";
       break;
     }
    else {
      cout<<"Incorrect password. Try Again" <<endl;
    }
    }while (password != "Python123");
  return 0;
 }