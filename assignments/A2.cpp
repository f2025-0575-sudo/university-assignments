#include<iostream>
// this library helps with input and output like cout and cin
#include<iomanip>
// this one helps with formatting the output nicely
using namespace std;
int main()
{
    int sub1,sub2,sub3,sub4,sub5;
    // made variables to hold marks for 5 subjects
    cout<<"Enter marks of subject 1:";
    cin>>sub1;
    cout<<"Enter marks of subject 2:";
    cin>>sub2;
    cout<<"Enter marks of subject 3:";
    cin>>sub3;
    cout<<"Enter marks of subject 4:";
    cin>>sub4;
    cout<<"Enter marks of subject 5:";
    cin>>sub5;
    // asking user to type in the marks for each subject

    if(sub1>100 || sub2>100||sub3>100||sub4>100||sub5>100)
    cout<<"invalid inputs";
    // this checks if any marks are more than 100 which isn’t allowed

    else
    {
        float percentage,sum;
       
        sum=sub1+sub2+sub3+sub4+sub5;
        percentage=sum/5;
        // adding all marks and dividing by 5 to get percentage

        string grade;
        // this one is used for storing the grade like A, B, etc.

        if(percentage>=90)
            grade="A+";
        else if (percentage >=80)
            grade="A";
        else if (percentage>=70)
            grade="B";
        else if (percentage>=60)
            grade="C";
        else if (percentage>=50)
            grade="D";
        else
            grade="F";
        // checking what grade you got according to the percentage 

        cout<<left<<setw(15)<<"Subject"<<right<<setw(15)<<"Marks"<<right<<setw(15)<<"Total Marks"<<right<<setw(20)<<"Marks Obtained"<<right<<setw(15)<<"Percentage"<<right<<setw(15)<<"Grade"<<endl;
        // prints out the headers for the table
     cout <<left<<setw(15)<<"\nsubject 1:"<<right<<setw(16)<<sub1<<right<<setw(15)<<"500"<<right<<setw(15)<<sum<<right<<setw(15)<<percentage<<right<<setw(15)<<grade<<endl;
        cout<<left<<setw(15)<<"subject 2:"<<right<<setw(15)<<sub2<<endl;
        cout<<left<<setw(15)<<"subject 3:"<<right<<setw(15)<<sub3<<endl;
        cout<<left<<setw(15)<<"subject 4:"<<right<<setw(15)<<sub4<<endl;
        cout<<left<<setw(15)<<"subject 5:"<<right<<setw(15)<<sub5<<endl;
        // prints out each subject and its marks in a neat format
        cout<<left<<setw(15)<<"Total:"<<right<<setw(15)<<sum<<endl;
       // prints out a neat table showing all marks, total, percentage, and grade


        string status = (percentage >= 50) ? "Pass" : "Fail";
        cout <<status<<endl;
        // uses a shortcut (ternary operator) to check if you passed or failed
    }

    return 0;
}
