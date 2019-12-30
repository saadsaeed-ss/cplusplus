#include <iostream>
using namespace std;
 int rev(int n,int temp)
 {
     if(n==0)
        return temp; //base case
     else
        {
            temp=(temp*10)+(n%10);
            return rev(n/10,temp);
        }
 }

 int main()
 {
     int n,res;
     cout<<"Enter the palidrome number : ";
     cin>>n;
     res=rev(n,0);
     if(res==n)
        cout<<"Number is palidrome"<<endl;
    else
        cout<<"Number is not palidrome"<<endl;
 }

