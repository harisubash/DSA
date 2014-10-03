#include<iostream>
using namespace std;
class ratio
{
    int num,den;

    public:
   ratio()
    {
        num=0;
        den=1;
        cout<<"Base class object created."<<endl;
    }
   ~ratio()
    {

    }
    virtual void disp();
    friend ratio multiratio(ratio a,ratio b);
    virtual void set_ratio(int a,int b);

};

void ratio::disp()
    {
        cout<<num<<"/"<<den;
        cout<<"\nBase class \n"<<endl;
    }

 void ratio::set_ratio(int a,int b)
{
    num=a;
    den=b;
}
ratio multiratio(ratio a,ratio b)
    {
      ratio prod;
      prod.num=a.num*b.num;
      prod.den=a.den*b.den;
      return prod;
    }
class real_ratio:public ratio
{
    int num,den;
public:
    real_ratio()
    {
       num=0;
       den=1;
        cout<<"Derived class object is created ."<<endl;
    }
    ~real_ratio()
    {
    }
  void disp()
    {
        cout<<num<<"/"<<den;
        cout<<"\nDerived class \n"<<endl;

    }
    virtual void set_ratio(int a,int b)
    {
        num=a;
        den=b;
    }
};

int main()
{
    ratio numb1,numb2,numb3;
    real_ratio numb4;
    numb1.set_ratio(2,3);
    numb2.set_ratio(4,5);
    numb3=multiratio(numb1,numb2);
    cout<<"product : ";
    numb3.disp();
    numb4.set_ratio(2,3);
    cout<<"Derived Test"<<endl;
    numb4.disp();

return 0;
}
