// C++ program to merge two sorted arrays/
#include<iostream>
using namespace std;
void mergeArrays(int arr1[], int arr2[],int arr3[],int n1,
                             int n2,int n3)
{
    int i = 0, j = 0, k = 0;
    for(i=0;i<n1;i++)
    {
        arr3[i]=arr1[i];
    }
    for(i=0,j=n1;(i<n2 && j<n3);i++,j++)
    {
        arr3[j]=arr2[i];
    }
}

int main()
{   int n1,n2,n3;
    cout<<"Enter size of first array : ";
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++)
    {
        cout<<"\nEnter the value of index "<<i<<" : ";
        cin>>arr1[i];
    }
    cout<<"Enter size of 2nd array : ";
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n1;i++)
    {
        cout<<"\nEnter the value of index "<<i<<" : ";
        cin>>arr2[i];
    }
    n3=n1+n2;
    int arr3[n3];

    mergeArrays(arr1, arr2, arr3, n1, n2, n3);

    cout << "Array after merging" <<endl;
    for (int i=0; i < n3; i++)
        cout << arr3[i] << " ";

    return 0;
}
