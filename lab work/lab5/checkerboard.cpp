#include<iostream>
using namespace std;
int main() {
    int rows,cols;
    cout<<"enter number of rows and columns: ";
    cin>>rows;
    cin>>cols;
      for(int i =1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            if((i+j) %2==0)
                cout<<"*";
            else
                cout<<" ";  
        }
        cout<<endl;
    }
    return 0;
}
