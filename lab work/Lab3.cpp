#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    string product1,product2;
   int quantity1, quantity2;
   float price1, price2, Total1, Total2;
   cout <<"Enter 1st product name";
   cin >>product1;
   cout <<"Enter Quantity";
   cin >> quantity1;
   cout <<"Enter price";
   cin >> price1;
   cout <<"Enter 2nd product name";
   cin >> product2;
   cout <<"Enter quantity";
   cin >> quantity2;
   cout <<"Enter price" <<endl;
   cin >>price2;
   Total1= quantity1 * price1;
   	Total2 = quantity2 * price2;
   	cout <<"---------------------------------------------------------------------"<<endl;
   	cout << left << setw(15) << "Product" 
	   << right << setw(10) << "Quantity"  << setw(10) << "Price"  << setw(10) << "Total" <<endl;
   	cout << "--------------------------------------------------------------------"<<endl;
   	cout << left << setw(15) << product1
   	     << right << setw(10) << quantity1
   	     << setw(10) << fixed << setprecision(2) << price1
   	     << setw(10) << fixed << setprecision(2) << Total1 <<endl;
          	cout << left << setw(15) <<product2
	     << right << setw(10) <<quantity2
	     << setw(10) << fixed << setprecision(2) << price1
	     << setw(10) << fixed << setprecision(2) << Total2 <<endl;
	     return 0;
		  
   	return 0;
}

