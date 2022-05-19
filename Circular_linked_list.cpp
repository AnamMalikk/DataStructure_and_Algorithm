#include <iostream>
using namespace std;
template <class t>
class cnode
{
public:
 t info;
 cnode* next;
 cnode(t x, cnode* n=NULL)
 {
 info=x;
 next=n;
 }
};

template <class t>
class cllist
{
 cnode<t> *cursor;
public:
 cllist()
 {
 cursor=NULL;
}
 void input();
 int isempty()
 {
 if(cursor==NULL)
 return 1;
 else
 return 0;
 }
 void addtofront(t x);
 void addtobackofy(t x,t y);
 void addtoback(t x);
 t deletefromfront();
 t deletefromback();
 void deletenode(t x);
 int countelements();
 void display();
 cnode<t>* isinlist(t x);
 cllist<t> operator +(cllist<t> l1);
};

template <class t>
void cllist<t>::input()
{
 int n;
 cout<<"Enter number of nodes"<<endl;
 cin>>n;
 t x;
 for(int i=1;i<=n;i++)
 {
cout<<"Enter info part"<<endl;
 cin>>x;
 addtoback(x);
 }
}

template <class t>
void cllist<t>::addtofront(t x)
{
 cnode<t>* temp=new cnode<t>(x);
 if(isempty())
 {
 cursor=temp;
 temp->next=cursor;
 }
 else
 {
 temp->next=cursor->next;
 cursor->next=temp;
 }
}

template <class t>
void cllist<t>::addtoback(t x)
{
 cnode<t>* temp=new cnode<t>(x);
 if(isempty())
 {
 cursor=temp;
 temp->next=cursor;
}
 else
 {
 temp->next=cursor->next;
 cursor->next=temp;
 cursor=temp;
 }
}

template <class t>
void cllist<t>::addtobackofy(t x, t y)
{
 cnode<t>* n=new cnode<t>(x);
 cnode<t>* temp;
 temp=cursor->next;
 if(y==cursor->next->info)
 addtofront(x);
 else if(y==cursor->info)
 addtoback(x);
 else
 {
 do
 {
 if(y==temp->info)
 break;
 }
 while(temp!=cursor->next);
 if(temp==cursor->next)
 cout<<y<<" is not present in list. Insertion not possible!!"<<endl;
else
{
 n->next=temp->next;
 temp->next=n;
 }
 }
}

template <class t>
t cllist<t>::deletefromfront()
{
 cnode<t>* temp;
 t x;
 x=cursor->next->info;
 if(cursor==cursor->next)
 {
 delete cursor;
 cursor=NULL;
 }
 else
 {
 temp=cursor->next;
 cursor->next=temp->next;
 delete temp;
 }
 return x;
}

template <class t>
t cllist<t>::deletefromback()
{
 cnode<t>* temp;
t x=cursor->info;
 if(cursor==cursor->next)
 {
 delete cursor;
 cursor=NULL;
 }
 else
 {
 temp=cursor->next;
 while(temp->next!=cursor)
 {
 temp=temp->next;
 }
 temp->next=cursor->next;
 delete cursor;
 cursor=temp;
 }
 return x;
}

template <class t>
void cllist<t>::deletenode(t x)
{
 t z;
 cnode<t>* previous;
 cnode<t>* current;
 if(cursor->next==cursor&&cursor->info==x)
 {
 delete cursor;
 cursor=NULL;
}
 else if(cursor->next->info==x)
 {
 z=deletefromfront();
 }
 else
 {
 previous=cursor->next;
 current=previous->next;
 while(current!=cursor&&current->info!=x)
 {
 previous=current;
 current=current->next;
 }
 if(current!=cursor->next)
 {
 previous->next=current->next;
 if(current==cursor)
 {
 cursor=previous;
 delete current;
 }
 else
 cout<<"Element not found"<<endl;
 }
 }
}

template <class t>
cnode<t>* cllist<t>::isinlist(t x)
{
 cnode<t>* temp;
 temp=cursor->next;
 do
 {
 if(temp->info==x)
 return temp;
 temp=temp->next;
 }
 while(temp->next!=cursor);
 return NULL;
}
template <class t>
cllist<t> cllist<t>::operator +(cllist<t> l1)
{
 cllist<t> l3;
 cnode<t>* temp;
 if(!(*this).isempty())
 {
 temp=(*this).cursor->next;
 do
 {
 l3.addtoback(temp->info);
 temp=temp->next;
 }while(temp!=(*this).cursor->next);
 }
 return l3;
}
template <class t>
int cllist<t>::countelements()
{
 int c=0;
 cnode<t>* temp;
 temp=cursor->next;
 do
 {
 c++;
 temp=temp->next;
 }
 while(temp!=cursor->next);
 return c;
}
template <class t>
void cllist<t>::display()
{
 if(isempty())
 {
 cout<<"List is empty"<<endl;
 }
 else
 {
 cnode<t>* temp;
 temp=cursor->next;
 cout<<"Contents of the list is :";
 do
 {
 cout<<"\t"<<temp->info;
 temp=temp->next;
}
 while(temp!=cursor->next);
 cout<<endl;
 }
}
int main()
{
 int e,isem, y, del, cunt;
 cnode<int>* t;//pointer of delete node
 cllist<int> l1,l2,l3;
 cout<<"Enter element in second list"<<endl;
 l2.input();
 int choice=0;
 char ch='y';
 while(ch=='y')
 {
 cout<<"Main menu"<<endl;
 cout<<"1.Input"<<endl;
 cout<<"2.Add to front"<<endl;
 cout<<"3.Add to back"<<endl;
 cout<<"4.Add after some given element"<<endl;
 cout<<"5.Delete from front"<<endl;
 cout<<"6.Delete from back"<<endl;
 cout<<"7.Delete node by specifying its info part"<<endl;
 cout<<"8.To check if an element is present in list"<<endl;
 cout<<"9.Add two lists"<<endl;
 cout<<"10.Count number of elements in list"<<endl;
 cout<<"11.Display"<<endl;
 cout<<"Enter your choice"<<endl;
cin>>choice;
 switch(choice)
 {
 case 1:
 l1.input();
 l1.display();
 break;
 case 2:
 cout<<"Enter element to be inserted"<<endl;
 cin>>e;
 l1.addtofront(e);
 l1.display();
 break;
 case 3:
 cout<<"Enter element to be inserted"<<endl;
 cin>>e;
 l1.addtoback(e);
 l1.display();
 break;
 case 4:
 cout<<"Enter element to be inserted"<<endl;
 cin>>e;
 cout<<"Enter after which element you want to insert"<<endl;
 cin>>y;
 l1.addtobackofy(e,y);
 l1.display();
 break;
 case 5:
 del=l1.deletefromfront();
cout<<del<<" Has been deleted"<<endl;
 l1.display();
 break;
 case 6:
 del=l1.deletefromback();
 cout<<del<<" Has been deleted"<<endl;
 l1.display();
 break;
 case 7:
 cout<<"Enter the info part of node which is tto be deleted"<<endl;
 cin>>e;
 l1.deletenode(e);
 l1.display();
 break;
 case 8:
 cout<<"Enter the element"<<endl;
 cin>>e;
 t=l1.isinlist(e);
 if(t==NULL)
 cout<<e<<" is not present in the list"<<endl;
 else
 cout<<e<<" is present and its pointer is "<<t<<endl;
 break;
 case 9:
 l3=l1+l2;
 l3.display();
 break;
 case 10:
 cunt=l1.countelements();
if(cunt==0)
 cout<<"List is empty. No elements are present"<<endl;
 else
 cout<<cunt<<" elements are present"<<endl;
 break;
 case 11:
 l1.display();
 break;
 default:
 cout<<"Error in input"<<endl;
 }
 cout<<"Do you want to continue(y/n) : "<<endl;
 cin>>ch;
 }
 return 0;
}

