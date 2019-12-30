#include <iostream>
using namespace std;

int Swap(int arr[],int mini,int i)
{   int temp;
    temp=arr[mini];
    arr[mini]=arr[i];
    arr[i]=temp;
}

void SelectionSort(int arr[],int n)
{
    int i,j,min_index;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_index])
                min_index=j;
        Swap(arr,min_index,i);
    }
}

int main()
{
    int arr[]={11,12,10,5,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    SelectionSort(arr,n);
    for(int i=0; i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;

}
