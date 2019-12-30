#include<iostream>
using namespace std;

const int MAX=06;
class mergesort
{
private:
    int arr[MAX];
public:
    mergesort(int a[])
    {
        for(int i=0;i<MAX;i++)
            arr[i]=a[i];
    }
    void sorting()
    {
        int aux[MAX];
        recmergesort(aux,0,MAX-1);
    }
    void recmergesort(int aux[],int lower,int upper)
    {
        if(lower==upper)
            return ;
        int mid=(lower+upper)/2;
        recmergesort(aux,lower,mid);
        recmergesort(aux,mid+1,upper);
        Merge(aux,lower,mid+1,upper);
    }

    void Merge(int aux[],int low,int high,int ub)
    {
        int j=0;
        int lb=low;
        int mid=high-1;
        int no=ub-lb+1;
        while(low<=mid && high<=ub)
            if(arr[low]<arr[high])
                aux[j++]=arr[low++];
            else
                aux[j++]=arr[high++];
        while(low<=mid)
            aux[j++]=arr[low++];
        while(high<=ub)
            aux[j++]=arr[high++];

        for(j=0;j<no;j++)
            arr[lb+j]=aux[j];
    }

    void display()
    {
        for(int i=0;i<MAX;i++)
            cout<<arr[i]<<"\t";
            cout<<endl;
    }
};

int main()
{
    int arr[]={2,6,5,1,4,3};
    mergesort ms(arr);
    ms.display();
    ms.sorting();
    ms.display();
    return 0;
}
