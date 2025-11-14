#include<iostream>
using namespace std;
int main() {
    int books; 
    int Totalfine;
    cout<<"Enter the number of books";
    cin>>books;
       for(int i=1; i<=books;i++){
         int numberofdays;
         int fine=5;
         cout<<"Enter number of days the book" << i << " is submitted late";
         cin>>numberofdays;
       for(int j=2;j<=numberofdays;j++){
          fine = fine*2;
          if(fine>1000){
             fine=1000;
          }
          else{
            continue;
          }
       }
          cout<<"Fine for book" << i << "is" <<fine<<endl;
          Totalfine=Totalfine + fine;
    }

         cout<<"Total fine for books is"<<Totalfine<<endl;
}