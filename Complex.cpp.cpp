#include<iostream>
using namespace std;


class complex
{
  float r, img;

  public: 

          complex()
          {
          r=0;
          img=0;
        }

        complex(float rr, float im)
        {
          r=rr;
          img=im;
        }

        void display()
        {
          cout<<r<<" + "<<img<<"i"<<endl;

        }

        complex operator +(complex );
        friend complex operator -(complex , complex );
        complex operator *(complex );
        complex operator /(complex );

}c1,c2,c3;

complex complex::operator +(complex c2)
{
  complex c3;
  c3.r = r+c2.r;
  c3.img = img+c2.img;
  return c3;
}

complex operator -(complex c1 , complex c2)
{
   complex c3;
   c3.r = c1.r-c2.r;
   c3.img = c1.img-c2.img;
   return c3;
}

complex complex::operator *(complex c2)
{
  complex c3;
  c3.r = r * c2.r - img * c2.img;
  c3.img = r * c2.img + img * c2.r;
  return c3;
}

complex complex::operator /(complex c2)
{
  complex c3;
  float denominator = c2.r * c2.r + c2.img * c2.img;
  c3.r = (r * c2.r + img * c2.img) / denominator;
  c3.img = (img * c2.r - r * c2.img) / denominator;
  return c3;
}




int main()
{
  int ch;
  float rr, im;

  cout<<"\nEnter the first complex no.: ";
  cin>>rr>>im;
  complex c1(rr,im);
  cout<<"The first complex no is: "<<rr<<" + "<<im<<"i"<<endl;

  cout<<"\nEnter the second complex no.: ";
  cin>>rr>>im;
  complex c2(rr,im);
  cout<<"The second complex no is: "<<rr<<" + "<<im<<"i"<<endl;

  while(true)
  {
    cout<<"\nMenu.\n1.Addition.\n2.Subtraction.\n3.Multiplication.\n4.Division.\n5.Exit.";
    cout<<"\nEnter your choice: ";
    cin>>ch;

    switch(ch)
    {
      case 1:
            c3=c1+c2;
                  cout<<"\nThe addition of two complex no is: ";
              c3.display();
              break;

      case 2:
            c3=c1-c2;
            cout<<"\nThe subtraction of two complex no is: ";
              c3.display();
              break;

      case 3:
            c3=c1*c2;
            cout<<"\nThe multiplication of two complex no is: ";
              c3.display();
              break;

      case 4:
            c3=c1/c2;
            cout<<"\nThe division of two complex no is: ";
              c3.display();
              break;

      case 5:
            return 0;

        default:
            cout << "Wrong choice";
    }
  }

  return 0;
}