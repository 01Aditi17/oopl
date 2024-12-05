#include<iostream>
using namespace std;

class student
{
	int rno;
protected:
	string prn,name;
public:
	void accept();
	void display();
};

class test:virtual public student
{
	int c1,c2,c3,e1,e2,e3;
protected:
	string s1,s2,s3;
public:
	void acceptT();
	void displayT();
};

class sports:virtual public student
{
	int sg;
protected:	
	string sn;
public:
	void acceptS();
	void displayS();
};

class result:public test,public sports
{
public:
	void displayR()
	{
		cout<<"\nroll.no\t\tprn\t\tname"<<endl;
		display();
		cout<<"\n";
		displayT();
		cout<<"\nsport"<<"\t\tgrade"<<endl;
		displayS();
	}
};

void student::accept()
{
	cout<<"\nEnter the roll no of the student:";
	cin>>rno;
	cout<<"Enter the prn of the student:";
	cin>>prn;
	cout<<"Enter the name of the student:";
	cin>>name;
	
}

void student::display()
{
	cout<<"\n"<<rno<<"\t\t"<<prn<<"\t\t"<<name<<endl;
}

void test::acceptT()
{
	cout<<"\nEnter the names of the subjects s1,s2,s3 respectively:";
	cin>>s1>>s2>>s3;
	cout<<"\nEnter the c1,c2,c3,e1,e2,e3 of the subjects s1,s2,s3 respectively:";
	cin>>c1>>c2>>c3>>e1>>e2>>e3;
}

void test::displayT()
{
	int percentage;
	percentage = (c1+c2+c3+e1+e2+e3)/3;
	cout<<"Percentage of the student is:"<<percentage<<endl;
}

void sports::acceptS()
{
	cout<<"\nEnter the name of the sport in which student participated:";
	cin>>sn;
	cout<<"Enter the grade of student in sport:";
	cin>>sg;
}

void sports::displayS()
{
	cout<<sn<<"\t\t"<<sg<<endl;
}

	

int main()
{
	result b;
	int ch;
	
	do
	{
		cout<<"\n1.Accept\n2.Display\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b.accept();
				b.acceptT();
				b.acceptS();
				break;
			
			case 2:
				b.displayR();
				break;
				
			default:cout<<"Invalid choice.";
			
		}
	}while(ch!=0);
	return 0;
}
