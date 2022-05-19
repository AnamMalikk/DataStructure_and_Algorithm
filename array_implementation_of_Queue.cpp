#include<iostream>
using namespace std;

const int MAX=6;
template <class T>
class queuetype
{
	int f,r;
	int q[MAX];
	public:
		queuetype()
		{
			f=r=-1;
		}
	void addition(T);
	T deletion();
	int isempty();
	int isfull();
	void display();
	int count();	
};
template <class T>void queuetype<T> :: addition(T n)
{
	if(f==-1)
    	f=r=0;
    else
		r++;
		q[r]=n;	
}
template <class T>T queuetype<T> :: deletion()
{
	if(f==-1)
		cout<<"The Queue is empty!! Deletion not possible";
	else
	{
		T temp;
		if(f==r)
		{
			temp=q[f];
			f=r=-1;
		}
		else
		{
			temp=q[f];
			f++;
		}
		return temp;
	}   	
}
template <class T>int queuetype<T> :: isempty()
{
	if(f==-1)
		return 1;
	else
	    return -1;	
}
template <class T>int queuetype<T> :: isfull()
{
	if(r==(MAX-1))
		return 1;
	else
	    return -1;	
}
template <class T>void queuetype<T> :: display()
{
	if(f==-1)
	{
		cout<<"\n Oops!!! Queue is empty";
	}
	else
	{
		cout<<"\nContents of Queue are: ";
		for(int i=f;i<=r;i++)
			cout<<q[i]<<" ";
	}
}
template <class T>int queuetype<T> :: count()
{
	int ct;
	if(f==-1)
		return 0;
	else
	{
		for(int i=f;i<=r;i++)
			ct++;
		return ct;	
	}
}

int main()
{
	queuetype<int> q;
	int choice,f,e,d,cnt,element;
	char ch='y';
	cout<<"\nMain Menu:";
	cout<<"\n1. Addition";
	cout<<"\n2. Deletion";
	cout<<"\n3. IsEmpty";
	cout<<"\n4. IsFull";
	cout<<"\n5. Display";
	cout<<"\n6. Count";
	while(ch=='y' || ch=='Y')
	{
		cout<<"\nEnter your choice[1-6] : ";
		cin>>choice;
		switch(choice)
		{
			case 1: f=q.isfull();
			       if(f==1)
			       {
			       	cout<<"\nQueue is full!! You can't add element";
			       	break;
				   }
				   else
				   {
				   	cout<<"\nEnter the element which you want to add in Queue : ";
				   	cin>>element;
				   	q.addition(element);
				   }
				   break;
			case 2: e=q.isempty();
			       if(e==1)
				   {
				   	cout<<"\nQueue is Empty!! You can't delete element";
				   	break;
				   }
				   else
				   {
				   	d=q.deletion();
				   	cout<<d<<" has been deleted";
				   }	  
				   break;
			case 3: e=q.isempty();
			       if(e==1)
				   {
				   	cout<<"\nQueue is Empty";
				   }  
				   else
				   {
				   	cout<<"\nQueue is not Empty";
					}  
				    break; 
			case 4: f=q.isfull();
			       if(f==1)
				   {
				   	cout<<"\nQueue is Full";
				   }  
				   else
				   {
				   	cout<<"\nQueue is not Full";
					}  
				    break; 
			case 5: q.display();
			       break; 
			case 6: cnt=(q.count());
			       cout<<"\nThere are "<<cnt<<" elements in Queue";
				   break;
			default: cout<<"Error!!";	   	      
		}
		cout<<"\nDo you want to continue : ";
		cin>>ch;
	}
}
