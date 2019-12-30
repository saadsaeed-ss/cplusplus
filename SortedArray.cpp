//Inserting, finding and deleting values in sorted array
#include <iostream>
using namespace std;
 class sortedarray
 {
private:
    int arr[10];
    int count;
public:
    sortedarray()
    {
        count=0;
    }
    int size_arr()
    {
        return count;
    }
    void insertion(int val)
    {
        int i,j;
        for(i=0;i<count;i++)
            if(arr[i]>val)
                break;
        for(j=count;j>i;j--)
            arr[j]=arr[j-1];
            arr[i]=val;
            count++;
    }
    int finding(int sval)
    {
        int lb,ub,loc;
        lb=0;ub=count-1;
        while(true)
        {
            loc=(lb+ub)/2;
            if(arr[loc]==sval)
                return loc;
            else if(lb>ub)
                return count;
            else
            {
                if(arr[loc]<sval)
                    lb=loc+1;
                else
                    ub=loc-1;
            }
        }
    }
    bool deletion(int dval)
    {
        int i=finding(dval);
        if(i==count)
            return false;
        else
            for(int j=i;j<count;j++)
            arr[j]=arr[j+1];
            count--;
            return true;
    }
    void display()
    {
        int i;
        for(i=0;i<count;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
 };

 int main()
 {
     sortedarray sa;
     sa.insertion(25);
     sa.insertion(26);
     sa.insertion(20);
     sa.display();
     int counter;
     counter=sa.size_arr();
     cout<<"counter : "<<counter<<endl;
     int loc;
     loc=sa.finding(11);
     if(loc!=sa.size_arr())
        cout<<"found out location : "<<loc<<endl;
     else
        cout<<"location not found"<<endl;
        cout<<"\n***  Deleting a value    ***"<<endl;
    if(sa.deletion(26))
        cout<<"value deleted"<<endl;
    else
        cout<<"Value does not exist"<<endl;
    sa.display();
     return 0;
 }
