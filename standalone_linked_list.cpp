#include <iostream>
using namespace std;
template<class Type>
struct node
{
    int info;
    node<Type>*next;
};
template<class Type>
class singly_linkedtype
{
    node<Type>*start;
public:
    singly_linkedtype()
    {
        start=NULL;
    }

    node<Type>*createnewnode(Type);
    void createnewlist(node<Type>*);
    void addatend(node<Type>*);
    void addatbeg(node<Type>*);
    void addati(node<Type>*,int);
    Type removefromend();
    int Count();
    void Search(Type);
    singly_linkedtype<Type> concat(singly_linkedtype<Type> l1);
    void display();
};
template<class Type>
singly_linkedtype<Type> 
singly_linkedtype<Type>::concat(singly_linkedtype<Type> l1)
{
 node <Type>*tmp = new node<Type>;
 tmp=(*this).start;
 while(tmp->next!=NULL)
 tmp=tmp->next;
 tmp->next=l1.start;

return *this;
}

template<class Type>
node<Type>*singly_linkedtype<Type>::createnewnode(Type x)
{
    node<Type>*nptr;
    nptr=new node<Type>;
    nptr->info=x;
    nptr->next=NULL;
    return(nptr);
}
template<class Type>
void singly_linkedtype<Type>::createnewlist(node<Type>*nptr)
{
    node<Type>*temp;
    temp=start;
    start=nptr;
    nptr->next=temp;
}

template<class Type>
void singly_linkedtype<Type>::addatend(node<Type>*nptr)
{
    node<Type>*temp;
    if(start==NULL)
    {
        start=nptr;
        return;
    }
    for(temp=start;temp->next!=NULL;temp=temp->next)
        {

        }
    temp->next=nptr;
}
template<class Type>
void singly_linkedtype<Type>::addatbeg(node<Type>*nptr)
{
    if(start==NULL)
        start=nptr;
    else
    {
        nptr->next=start;
        start=nptr;
    }
    return;
}
template<class Type>
void singly_linkedtype<Type>::addati(node<Type>*nptr,int i)
{
    if(i>(*this).Count()+1||i<1)
    {
        cout<<" Invalid position.... ERROR!!!!!\n";
        return;
    }
    else if(i==1)
    {
        addatbeg(nptr);
        return;
    }
    else if(i==Count()+1)
    {
        addatend(nptr);
        return;
    }
    else
    {
        node<Type>*temp=start;
        for(int j=1;j<i-1;j++)
        {
            temp=temp->next;
        }
        nptr->next=temp->next;
        temp->next=nptr;
        return;
    }
}

template<class Type>
int singly_linkedtype<Type>::Count()
{
    int ct=0;
    node<Type>*temp;
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        ct++;
    }
    return ct;
}
template<class Type>
void singly_linkedtype<Type>::display()
{
    node<Type>*temp;
    if(start==NULL)
    {
        cout<<"Linked list is empty!!! Nothing to Display\n";
    }
    else
        {
            cout<<"Linked list is: \n";
            for(temp=start;temp!=NULL;temp=temp->next)
            {
                cout<<temp->info<<"  ";
            }
            cout<<endl;
        }
}
template<class Type>
void singly_linkedtype<Type>::Search(Type x)
{
    int i=0;
    node<Type>*temp;
    if(start==NULL)
    {
        cout<<"Linked list is empty!!! Nothing to Display\n";
    }
    else
        {
            for(temp=start;temp!=NULL;temp=temp->next)
            {
                if(temp->info==x)
                {
                    cout<<"Element found at"<<i+1<<"th position";
                    return;
                }
                i++;
            }
            cout<<"Element not found!"<<endl;
        }
        return;
}
template<class Type>
Type singly_linkedtype<Type>::removefromend()
{
    int p=0;
    node<Type>*temp;
    node<Type>*x;
    for(temp=start;temp->next->next!=NULL;temp=temp->next)
    {
    }
    p=temp->next->info;
    temp->next=NULL;
    return(p);

}

int main()
{
    singly_linkedtype<int>l1,l2,l3;
    int choice,n,m,ct,pos;
    node<int>*nptr;
    cout<<"Creating new linked list \nList1:--------- \nEnter number of nodes in list 1:\n";
    cin>>n;
    cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<"Enter the info part of node "<<i+1<<"  ";
        cin>>m;
        nptr=l1.createnewnode(m);
        if(nptr==NULL)
        {
            cout<<"Compiler out of memory.. Error!!\n";
            exit(0);
        }
        else
            l1.createnewlist(nptr);
    }
    cout<<"\nCreating new linked list \nList2:--------- \nEnter number of nodes in list2: \n";
    cin>>n;
    for(int i=n-1;i>=0;i--)
    {
        cout<<"Enter the info part of node "<<i+1<<"  ";
        cin>>m;
        nptr=l2.createnewnode(m);
        if(nptr==NULL)
        {
            cout<<"Compiler out of memory.. Error!!\n";
            exit(0);
        }
        else
            l2.createnewlist(nptr);
    }
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"\nMain menu\n";

        cout<<"1.Add at ith position\n";
        cout<<"2.Delete at End\n";
        cout<<"3.Search for an element x\n";
        cout<<"4.Concatenate\n";
        cout<<"5.Display\n";
        cout<<"Note ****list2 is used for concatenation only,no other operations can be performed on it!!"<<endl;


        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {

            case 1:cout<<"Enter the position at which node is to be added\n";
                   cin>>pos;
                   cout<<"Enter info part of Node to be added at ith position\n";
                   cin>>n;
                   nptr=l1.createnewnode(n);
                   if(nptr==NULL)
                   {
                       cout<<"Error!!\n";
                   }
                   else
                   {
                       l1.addati(nptr,pos);
                       l1.display();
                   }
                   break;
            case 2:m=l1.removefromend();
                   cout<<m<<" has been deleted from the list\n";
                   l1.display();
                   break;
                    case 6:l1.display();
                   break;

            case 3:cout<<"Enter the info part of element to search\n";
                    cin>>m;
                    l1.Search(m);
                    break;
            case 4:l3=l1.concat(l2);
                           l3.display();
                           break;
            case 5:l1.display();
                   break;
            default:cout<<"Error in Input\n";
                   break;
        }
        cout<<"\nDo you want to continue\n";
        cin>>ch;
    }
    return 0;
}
