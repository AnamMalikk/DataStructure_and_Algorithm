#include<iostream>
using namespace std;
void selectionSort(float *arr, int size) 
{  
    float small,temp; 
    int pos; 
    for(int i=0;i<size-1 ;i++) 
    { 
        small=arr[i]; 
        pos=i; 
        for(int j=i+1;j<size;j++) 
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
void display(float *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main()
{
	int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n];           //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
 } 
