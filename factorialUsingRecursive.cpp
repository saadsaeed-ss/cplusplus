#include <iostream>
using namespace std;
int factorial(int);
int main()
{
    int fact,res;
    cout<<"Enter number to find factorial : ";
    cin>>fact;
    res=factorial(fact);
    cout<<"\nFactorial of "<<fact<<" is "<<res;
}

int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
