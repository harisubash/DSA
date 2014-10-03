#include <iostream>

using namespace std;

int main()
{
    int **array;
    int i,j,R,C;
    cout<<"Enter the number of rows and columns :";
    cin>>R>>C;
    array =new int *[R];
    for(i=0;i<R;i++)
    {
        array[i]=new int[C];
    }
    cout<<"Enter the elements :"<<endl;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            cin>>array[i][j];
        }
    }
    cout<<"\nEntered array "<<endl;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}

