#include<iostream>
using namespace std;
class Complex 
{
  public:
  int real;
  int imag;
  Complex()
  {
     real=0;
     imag=0;
   } 
   void input()
   {
      cout<<"\nEnter value of real part:\t";
      cin>>real;
      cout<<"\nEnter value of imaginary part:\t";
      cin>>imag;
   } 
   void display()
   {
      cout<<"\nComplex number:\t"<<real<<"+"<<imag<<"i"<<endl;
   }
    Complex operator+(Complex &a)
   {
       Complex temp;
       temp.real=real+a.real;
       temp.imag=imag+a.imag;
       return temp; 
    }
    Complex operator-(Complex &a)
   {
       Complex temp;
       temp.real=real-a.real;
       temp.imag=imag-a.imag;
       return temp; 
    }
    Complex operator*(Complex &a)
   {
       Complex temp;
       temp.real=real*a.real-imag*a.imag;
       temp.imag=real*a.imag+imag*a.real;
       return temp; 
    }

   Complex operator/(Complex &a)
   {
       Complex temp;
       temp.real=(real*a.real+imag*a.imag)/(a.real*a.real+a.imag*a.imag);
       temp.imag=(imag*a.real+real*a.imag)/(a.real*a.real+a.imag*a.imag);
       return temp; 
    }

};
int main()
{
   Complex obj1,obj2,obj3;
   int choice,ch;
   cout<<"\n1.";
   obj1.input();
   cout<<"\n2.";
   obj2.input();
   do
   {
      cout<<"\nEnter your choice:\t";
      cout<<"\n1.Addition";
      cout<<"\n2.Substraction";
      cout<<"\n3.Multiplication";
      cout<<"\n4.Division";
      cout<<"\n5.Exit";
      cin>>choice;
      switch(choice)
      {
         case 1:
              cout<<"\nAddition:\t";
              obj3=obj1+obj2;
              obj3.display();
              break;
         case 2:
              cout<<"\nSubstraction:\t";
              obj3=obj1-obj2;
              obj3.display();
              break;
         case 3:
              cout<<"\nMultiplication:\t";
              obj3=obj1*obj2;
              obj3.display();
              break;
         case 4:
              cout<<"\nDivision:\t";
              obj3=obj1/obj2;
              obj3.display();
              break;
         case 5:
              cout<<"\nExiting......!\n";
              break; 
         default:
          cout<<"\nInvalide choice.....!";
          cout<<"\nYou want to continue?(1/5):";
          cin>>choice;
      }
   } while (choice!=5);
   
    
   return 0;
}