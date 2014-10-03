/* To find the number of pairs X^Y > Y^X in the given sequence
 *
 * where X = array[j] and Y=array[i] for all j<i;
 *
 *
 * Author : Harikrishnan Subash
 *
 *Date : September 1 , 2014
 *
 *  Test Case 1
 *
 *  10
 *  1 5 2 3 8 7 8 7 1 2
 *
 *  O/P =21
 *
 *
 *  Test Case 2
 *
 *  15
 *  0 5 2 3 0 8 7 8 0 7 1 2 4 5 3
 *
 *  O/P=35
 *
 *  Test Case 3
 *
 *  10
 *  8 5 2 3 8 7 8 7 7 8
 *
 * O/P= 22
 *
 * */

#include <iostream>


using namespace std;

int * array ;
void ReadSeq(int N)
{
    int i;
    array=new int[N];
    for(i=0;i<N;i++)
    {
        cin>>array[i];
    }

//    cout<<"Elements entered successfully "<<endl<<endl;
//    cout<<"Entered Elements are : ";
//    for(i=0;i<N;i++)
//    {
//        cout<<" "<<array[i];
//    }
//    cout<<endl<<endl;


}
int Power(int x,int y)
{
    int pwr=1;
   for(int i=0;i<y;i++)
   {
       pwr=pwr*x;
   }
   return pwr;
}

int CheckCondn(int N)
{
    int count=0;
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
           if((Power(array[j],array[i])>Power(array[i],array[j])))
           {
               count++;
           }
        }
    }
    return count;
}

int main()
{
    int *array,N;
    int result=0;
//  cout<<"Enter the number of elements :";
    cin>>N;
//  cout<<"\n Enter the elements :"<<endl;
    ReadSeq(N);
    result=CheckCondn(N);
//  cout<<"The no of pairs of elements that satisfy the condition :";
    cout<<result<<endl;
    delete [] array;
    return 0;
}
