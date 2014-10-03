/*
 *
 * Program to load an array dynamically and then to display the elements in a spiral
 *
 *
 * Author : Harikrishnan Subash
 *
 * Date : August 30th , 2014
 *
 *
 *
 * */
#include<iostream>
using namespace std;

void spiralPrint()
{

// Algorithm Test Case
//    int m=0,n=0,M=4,N=1,i,j;
//    int array[4][1]={1,2,3,4};


    int **array;
    int i,j,M,N,m,n;
    cout<<"Enter the number of rows and columns :";
    cin>>M>>N;
    array =new int *[M];
    for(i=0;i<M;i++)
    {
        array[i]=new int[N];
    }

    cout<<"Enter the elements :"<<endl;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>array[i][j];
        }
    }

    cout<<"\nEntered Matrix "<<endl;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"\n -------------- SPIRAL ---------------------\n";
    m=0;
    n=0;
    while(m<M && n<N)
    {
        for(i=n;i<N;i++)
        {
            cout<<array[m][i]<<" ";
        }
        m++;
        for(i=m;i<M;i++)
        {
            cout<<array[i][N-1]<<" ";
        }
        N--;
        if(m<M)
        {
            for(i=N-1;i>=n;i--)
            {
                cout<<array[M-1][i]<<" ";
            }
            M--;

        }
        if(n<N)
        {
            for(i=M-1;i>=m;i--)
            {
                cout<<array[i][n]<<" ";
            }
            n++;
        }
    };
}

int main()
{
  spiralPrint();
  return 0;
}
