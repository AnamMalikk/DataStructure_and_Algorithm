#include<iostream>
using namespace std;


template<class T>
int Binary(T arr[20],int x,int n)
{
    
    int high,mid,low;
    high=n-1;
    low=0;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(x==arr[mid])
        {
            return mid+1;
        }
        else if(x>arr[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main(){

        int n,x,b,arr[20];
        cout<<"Enter the total number of elements you want"<<endl;
                     cin>>n;
                     cout<<"Enter the elements of array  ";
                     for(int i=0;i<n;i++)
                     {
                        cin>>arr[i];
                     } 
                     cout<<"Enter the element to be searched  "<<endl;
                     cin>>x;
                      b=Binary(arr,x,n);
                     if(b==-1)
                        cout<<"Element not found"<<endl;
                     else
                        cout<<"Element found at position "<<b<<endl;

                    
    return 0;

}
