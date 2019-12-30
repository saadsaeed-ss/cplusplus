#include <iostream>
using namespace std;
void toh(int,char,char,char);

int main()
{
    int n;
    cout<<"Enter the number of disks : ";
    cin>>n;
    toh(n,'A','B','C');
    cout<<"\nJob is done."<<endl;
    return 0;
}


void toh(int n,char src,char aux,char dest)
{
    if(n>1)
    {
        toh(n-1,src,dest,aux);
        toh(1,src,aux,dest);
        toh(n-1,aux,src,dest);
    }
    else
        cout<<"move top dist from "<<src<<" to "<<dest<<endl;
}
