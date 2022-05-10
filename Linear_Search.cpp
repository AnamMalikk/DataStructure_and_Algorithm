#include<iostream>
using namespace std;

template<class T>
int Linear(T arr[20],int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i+1;
        }
    }
    return -1;
}

int main(){

        int n,x,l,arr[20];
        cout<<"Enter the total number of elements you want"<<endl;
                     cin>>n;
                     cout<<"Enter the elements of array  ";
                     for(int i=0;i<n;i++)
                     {
                        cin>>arr[i];
                     } 
                     cout<<"Enter the element to be searched  "<<endl;
                     cin>>x;
                     l=Linear(arr,x,n);
                     if(l==-1)
                        cout<<"Element not found"<<endl;
                     else
                        cout<<"Element found at position "<<l<<endl;



    return 0;
}
