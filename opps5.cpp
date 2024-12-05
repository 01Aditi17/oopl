#include<iostream>
#include<cstring>

using namespace std;

class Person
{
public:
	int id,salary;
	string name,designation;
	
	virtual void accept()=0;
	virtual void display()=0;
};

class Doctor:public Person
{
public:
	void accept()
	{
		cout<<"\nEnter the id, name and designation:";
		cin>>id>>name>>designation;
	}
	
	void display()
	{
		cout<<id<<"\t"<<name<<"\t"<<designation<<endl;
	}
};

class Nurse:public Person
{
public:
	void accept()
	{
		cout<<"\nEnter the id, name, designation, salary:";
		cin>>id>>name>>designation>>salary;
	}
	
	void display()
	{
		cout<<id<<"\t"<<name<<"\t"<<designation<<"\t"<<salary<<endl;
	}
};

class Staff:public Person
{
public:
	void accept()
	{
		cout<<"\nEnter the id, name, designation, salary:";
		cin>>id>>name>>designation>>salary;
	}
	
	void display()
	{
		cout<<id<<"\t"<<name<<"\t"<<designation<<"\t"<<salary<<endl;
	}
};

int main()
{
	Doctor D;
	Nurse N[10];
	Staff S[5];
	int ch,choice,n,m;
	
	do
	{
		cout<<"\nMenu\n1.Enter the data of Doctor.\n2.Enter the data of Nurse.\n3.Enter the data of administrative staff.\n4.Display the data.\nEnter the choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				D.accept();
				break;
				
			case 2:
				cout<<"how many nurse's data you want to enter:";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					N[i].accept();
				}
				break;
			
			case 3:
				cout<<"how many staff's data you want to enter:";
				cin>>m;
				for(int i=0;i<m;i++)
				{
					S[i].accept();
				}
				break;
	
			case 4:
				cout<<"\nId\tName\tDesignation"<<endl;
				D.display();
				cout<<"\nId\tName\tDesignation\tSalary"<<endl;
				for(int i=0;i<n;i++)
				{
					N[i].display();
				}
				for(int i=0;i<m;i++)
				{
					S[i].display();
				}
				break;
			
			default:
				cout<<"Invalid choice.";
			
			
		}
		cout<<"Do you want to continue(1/0):";
		cin>>choice;
		
	}while(choice=1);
	return 0;
}

