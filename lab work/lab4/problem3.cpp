#include<iostream>
using namespace std;
#include<string>
int main(){
    int shapes,exit;
    float radius,length,width,base,height,area;
    bool flag=true;
     cout<<"Which shapes area do you want to find ?"<<endl;
        cout<<"1.Circle"<<endl;
        cout<<"2.Rectangle"<<endl;
        cout<<"3.Triangle"<<endl;
        cin>> shapes ;
    while(flag=true);
    switch(shapes) {
        case 1:           
            cout<<"Enter the radius of the circle:";
            cin>>radius;
            area=3.14*radius*radius;
            cout<<"Area of the circle is:"<<area;
            break;
        case 2:
            cout<<"Enter the length and width of the rectangle:";     
            cin>>length>>width;
            area=length*width;
            cout<<"Area of the rectangle is:"<<area;
            break;
        case 3:
            cout<<"Enter the base and height of the triangle:";
            cin>>base>>height;
            area=0.5*base*height;
            cout<<"Area of the triangle is:"<<area;
            break;
        case 4:
            flag=false;
               
            break;
        default:
            cout<<"Invalid Output";
            break;
        }
return  0;  
}
