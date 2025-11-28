#include<iostream>
using namespace std;
int attemptwithdraw(int balance,int amount){
 if(balance>amount){
    balance=balance-amount;
}
 else{
    cout<<"Error! Insufficient funds"<<endl;
 }
   return balance;
}
 int main(){
  int amount,balance,remainingbalance;
   cout<<"Enter balance:"<<endl;
   cin>>balance;
 do{
   cout<<"Enter withdraw amount"<<endl;
   cin>>amount;
   remainingbalance=attemptwithdraw(balance,amount);
   cout<<"Remaining Balance is = "<<remainingbalance<<endl;
   cout<<"Original Balance is = "<<balance<<endl;  
   if(remainingbalance>=0){
   }
 }while(remainingbalance>0);
 cout<<"No Balance Remaining";
  return 0;
 }