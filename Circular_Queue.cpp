#include<iostream>
using namespace std;
const int SIZE=6;
template<class t>
class circular_queue
{
	public:
	t cq[SIZE];
	int f,r;
	circular_queue()
	{
		f=r=-1;
	}
	void insert(t);
	t remove();
	int isempty();
	int isfull();
	void display();
	t frontmost();
	t rearmost();
	int count();
	void clear();
};

template<class t>
void circular_queue<t> :: insert(t x)
{
	if(r==-1)
	{
		f=r=0;
		cq[r]=x;
	}
	else if(r==SIZE-1)
	{
		r=0;
		cq[r]=x;
	}
	else
	{
		r++;
		cq[r]=x;
	}
}

template<class t>
t circular_queue<t> :: remove()
{
	t rem;
	if(f==r)
	{
		rem=cq[f];
		f=r=-1;
	}
	else if(f==SIZE-1)
	{
		rem=cq[f];
		f=0;
	}
	else
	{
		rem=cq[f];
		f++;
	}
	return rem;
}

template<class t>
int circular_queue<t> :: isempty()
{
	if(f==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class t>
int circular_queue<t> :: isfull()
{
	if((f==0) && (r==SIZE-1))
	{
		return 1;
	}
	else if(f==r+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class t>
void circular_queue<t> :: display()
{
	if(f==-1)
	{
		cout<<"Queue is Empty!"<<endl;
	}
	else if(f<=r)
	{
		cout<<"The Contents of Q are : ";
		for(int i=0;i<f;i++)
			cout<<"_"<<"\t";
		for(int i=f;i<=r;i++)
			cout<<cq[i]<<"\t";
		for(int i=r+1;i<SIZE-1;i++)
			cout<<"_"<<endl;		
	}
	else
	{
		cout<<"The Contents of Q are : ";
		for(int i=0;i<r;i++)
			cout<<cq[i]<<"\t";
		for(int i=r+1;i<f;i++)
			cout<<"_"<<"\t";
		for(int i=f;i<SIZE-1;i++)
			cout<<cq[i]<<endl;	
	}
}

template<class t>
t circular_queue<t> :: frontmost()
{
	t front_var;
	front_var=cq[f];
	return front_var;
}

template<class t>
t circular_queue<t> :: rearmost()
{
	t rear_var;
	rear_var=cq[r];
	return rear_var;
}

template<class t>
void circular_queue<t> :: clear()
{
	f=r=-1;
}

template<class t>
int circular_queue<t> :: count()
{
	int c=0;
	if(f==-1)
	{
		return 0;
	}
	else if(f<=r)
	{
		for(int i=f;i<=r;i++)
			c++;
		return c;	
	}
	else
	{
		for(int i=0;i<r;i++)
			c++;
		for(int i=r+1;i<f;i++);
		for(int i=f;i<SIZE-1;i++)
			c++;
		return c;		
	}
}

int main()
{
	circular_queue<int> cqueue;
	int e,choice,full,empty,f,r,cnt,rem;
	char ch='y';
	system("cls");
	cout<<"\t\t -----------------------IT IS A CIRCULAR QUEUE PROGRAM-------------------------"<<endl;
	while(ch=='y'||ch=='Y')
	{
		cout<<"Main Menu"<<endl;
		cout<<"1. To Insert a new Element"<<endl;
		cout<<"2. To Remove an Element"<<endl;
		cout<<"3. To Check if Queue is Empty"<<endl;
		cout<<"4. To Check if Queue is Full"<<endl;
		cout<<"5. To Display the Contents of Queue"<<endl;
		cout<<"6. To Display the Foremost Element of Queue"<<endl;
		cout<<"7. To Display the Raremost Element of Queue"<<endl;
		cout<<"8. To Count the number of Elements in a Queue"<<endl;
		cout<<"9. To Clear the Queue"<<endl;				
		cout<<" Enter Your Choice [1-9] : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : full=cqueue.isfull();
			         if(full==1)
			         	cout<<"Queue is Full! Element can't be Inserted"<<endl;
			         else
					 {
					 	cout<<"Enter the element you want to Insert : ";
					 	cin>>e;
					 	cqueue.insert(e);
					 	cqueue.display();
					 }
					 break;
			case 2 : empty=cqueue.isempty();
			         if(empty==1)
			         	cout<<"Queue is Empty! Deletion not Possible"<<endl;
			         else
					 {
					 	rem=cqueue.remove();
					 	cout<<"Element "<<rem<<" has been deleted"<<endl;
					 	cqueue.display();
					 }
					 break;	
			case 3 : empty=cqueue.isempty();
			         if(empty==1)
			         	cout<<"Queue is Empty"<<endl;
			         else
					 {
					 	cout<<"Queue is not Empty"<<endl;
					  }
					 break;		
			case 4 : full=cqueue.isfull();
			         if(full==1)
			         	cout<<"Queue is Full"<<endl;
			         else
					 {
					 	cout<<"Queue is not Full"<<endl;
					 }
					 break;	
			case 5 : cqueue.display();
					 break;	
			case 6 : empty=cqueue.isempty();
			         if(empty==1)
			         	cout<<"Queue is Empty"<<endl;
			         else
					 {
					 	f=cqueue.frontmost();
			            cout<<"Frontmost element of Queue is : "<<f<<endl;
					 }	
					 break;	
		    case 7 : empty=cqueue.isempty();
			         if(empty==1)
			         	cout<<"Queue is Empty"<<endl;
			         else
					 {
					 	r=cqueue.rearmost();
			            cout<<"Raremost element of Queue is : "<<r<<endl;
					 }	
					 break;	
			case 8 : empty=cqueue.isempty();
			         if(empty==1)
			         	cout<<"Queue is Empty"<<endl;
			         else
					 {
					 	cnt=cqueue.count();
					 	cout<<"There are "<<cnt<<" elements in the Queue"<<endl;
					 }	
					 break;	
			case 9 : cqueue.clear();
			         cqueue.display();
			         break;
			default: cout<<"Error in Input"<<endl;
					 break;		 		 		 	 	 	  	 	
		}
		cout<<"\nDo You Want to Continue(y/n) : ";
		cin>>ch;
	}
	return 0;
}
