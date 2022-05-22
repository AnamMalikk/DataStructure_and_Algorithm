#include<iostream>
using namespace std;

const int MAX=6;

template<class T>
class StackType{
    int top;
    T s[MAX];
    public:
    void push (T);
    T pop();
    int isEmpty();
    int isFull();
    void display();

    StackType()
    {
        top = -1;
    }
};

template<class T>void StackType<T> :: push(T p)
{
    top++;
    s[top]=p;
}

template<class T>T StackType<T> :: pop()
{
    T del;
    del=s[top];
    top--;
    return del;
}

template<class T>int StackType<T> :: isEmpty()
{
    if(top == -1)
         return 1;
    else
         return -1;     
}

template<class T>int StackType<T> :: isFull() 
{
    if(top == MAX-1)
         return 1;
    else
         return -1;     
}

template<class T>void StackType<T> :: display()
{
    int e = isEmpty();
    if(e == -1)
    {
        cout<<"\nContents of Stack are: ";
        for(int i=top ; i>=0 ; i--)
        {
            cout<<s[i]<<"\t";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"\nStack is Empty!!!";
    }
}

int main()
{
    StackType<int> stack;
    int choice,f,e,d,a;
    char ch;
    do{
    cout<<"\nMain Menu";
    cout<<"\n1. To Push";
    cout<<"\n2. To Pop";
    cout<<"\n3. To check if Empty";
    cout<<"\n4. To check if Full";
    cout<<"\n5. Display";
    cout<<"\nEnter your Choice[1-5] : ";
    cin>>choice;
    switch(choice)
    {
        case 1 : f = stack.isFull();
                 if(f==1)
                 {
                     cout<<"\nOverflow!! Stack is Full";
                     break;
                 }
                 else
                 {
                     cout<<"\nEnter an Integer value : ";
                     cin>>a;
                     stack.push(a);
                     stack.display();
                 }
                 break;
        case 2 : e = stack.isEmpty();
                 if(e==1)
                 {
                     cout<<"\nUnderflow!! Stack is Empty";
                     break;
                 }
                 else
                 {
                     d = stack.pop();
                     cout<<d<<" has been Deleted";
                     stack.display();
                 }
                 break; 
        case 3 : e = stack.isEmpty();
                 if(e==1)
                 {
                     cout<<"\nStack is Empty";
                 }
                 else
                 {
                     cout<<"\nStack is not Empty";
                 }
                 break;      
        case 4 : f = stack.isFull();
                 if(f==1)
                 {
                     cout<<"\nStack is Full";
                 }
                 else
                 {
                     cout<<"\nStack is not full";
                 }
                 break;      
        case 5 : stack.display();
                 break;
        default: cout<<"\nError in Input";   
                 break;                              
    }

cout<<"\n Do you want to continue (y/n) : ";
cin>>ch;
}while(ch == 'y' || ch == 'Y');
return 0;
}

