#include <iostream>
using namespace std;
void swaping(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void reverseArray(int arry []){
    int left = 0, right = 5;
    while(left < right){
        swaping(arry[left], arry[right]);
        left++;
        right--;
    }
}
int main(){
    int arry [6];
    cout << "Enter 6 number of elements: " << endl;
    for (int i = 0; i < 6; i++){
        cin >> arry [i];
    }
    cout << endl;

    for (int j = 0; j < 6; j++){
        cout << arry [j] << " ";
    }
    cout << endl;
    reverseArray(arry);
    for (int k = 0; k < 6; k++){
        cout << arry [k] << " ";
    }

    return 0;
}