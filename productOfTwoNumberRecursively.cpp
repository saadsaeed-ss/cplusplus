#include <iostream>
using namespace std;
int multiply(int,int);
int main()
{
    int a,b,res;
    cout<<"Enter number to multiply : ";
    cin>>a;
    cout<<"Enter number to multiply with : ";
    cin>>b;
    res=multiply(a,b);
    cout<<"\nResult is "<<res;
}

int multiply(int a,int b)
{
    if(b==1)
        return a;
    else
        return a+multiply(a,b-1);
}

