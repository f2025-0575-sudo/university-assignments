#include<iostream>
using namespace std;
 void weather(){
    int  weatherarr[7][4];
    string days [7]={
        {"Monday"},
        {"Tuesday"},
        {"Wednesday"},
        {"Thursday"},
        {"Friday"},
        {"Saturday"},
        {"Sunday"}
    };
    string timings [4]={
        {"7am"},
        {"1pm"},
        {"5pm"},
        {"12am"}
    };
   for(int i=0; i<7; i++){
      cout<<"Enter Temperature For"<<endl<< days [i];
    for(int j=0; j<4; j++){
        cout<<timings[j];
       cin>>weatherarr[i][j]; 
    }
   }
 }
 int highesttemp(){
    for(int i=0; i<7; i++){
      for(int j=0; j<4; j++){
        if(j)
      }
    }
 }

int main(){
 weather();

 

}