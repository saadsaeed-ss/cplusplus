#include <iostream>
using namespace std;
int fib(int);

int main()

{
    int n,res;
    cout<<"Enter term to find : ";
    cin>>n;
    res=fib(n);
    cout<<"Result is "<<res<<endl;
    return 0;
}

int fib(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}
