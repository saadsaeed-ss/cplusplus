#include <iostream>
using namespace std;
int sum(int [],int);
int main()
{
    int arr[]={5,10,12,14,24};
    int res;
    res=sum(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"\nresult is "<<res;
    return 0;
}

int sum(int a[],int n)
{
    if(n<=0)
        return 0;
    else
        return a[n-1]+sum(a,n-1);
}
