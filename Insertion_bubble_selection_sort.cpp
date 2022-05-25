#include <iostream>
using namespace std;
const int MAX=50;
template<class T>
class Sort
{
public:
    T arr[MAX];
    int n;
    void input();
    void insertionsort();
    void bubblesort();
    void selectionsort();
    void display();
};
template<class T>
void Sort<T>::input()
{
    cout<<"Enter the number of elements in array :";
    cin>>n;
    if(n>MAX)
    {
        cout<<"\nError!! Exceeding MAX value";
        exit(0);
    }
    cout<<"\nEnter the elements in array : \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
template<class T>
void Sort<T>::display()
{
    cout<<"Elements in array are : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
template<class T>
void Sort<T>::insertionsort()
{
    T key;
    int i,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
template<class T>
void Sort<T>::bubblesort()
{
    T temp;
    char Switch='T';
    for(int i=0;i<n-1 && Switch=='T';i++)
    {
        Switch='F';
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                Switch='T';
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
template<class T>
void Sort<T>::selectionsort()
{
    T small,temp;
    int pos;
    for(int i=0;i<n-1 ;i++)
    {
        small=arr[i];
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<small)
            {
                small=arr[j];
                pos=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
}
int main()
{
    Sort<int>s1;
    char ch='y';
    int choice;
    while(ch=='y'||ch=='Y')
    {
        cout<<"\n******** Main Module *******\n";
        cout<<"1.Input the Array\n";
        cout<<"2.Insertion Sort\n";
        cout<<"3.Bubble Sort\n";
        cout<<"4.Selection Sort\n";
        cout<<"Enter the choice[1-4] : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:s1.input();
                   s1.display();
                   break;
            case 2:s1.insertionsort();
                   s1.display();
                   break;
            case 3:s1.bubblesort();
                   s1.display();
                   break;
            case 4:s1.selectionsort();
                   s1.display();
                   break;
            default:cout<<"Error in Input\n";
                    break;
        }
        cout<<"Do you want to continue : ";
        cin>>ch;
    }
    return 0;
}

