#include<iostream>
using namespace std;
int main(){
    int arr1[2][2]={{6,3},{9,5}};
     for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<" X";
     cout<<endl;
    
     int arr2[2][2]={{4,5},{7,8}};
      for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
      }
    int resultarr[2][2];
    cout<<endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            resultarr[i][j]=0;
            for(int k=0; k<2; k++){
                resultarr[i][j]+= arr1[i][k]*arr2[k][j];
            }
        }
    }
    cout<<endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<resultarr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
