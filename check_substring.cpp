/*
 *  Program to find if the given second string is a substring of the first
 *
 *  Author : HKS
 *
 *  Date :
 *
 * */
#include <iostream>
#include<string.h>
using namespace std;

char s1[20],s2[20];
int l1,l2;

void readString()
{
    cout<<"Enter the two strings : " <<endl;
    cin>>s1>>s2;
}
int checkSubstring()
{
    int output=-1;
    for(int i=0;i<l1;i++)
    {
        if(s1[i]==s2[0])
        {
            if((i+l2)>l1)
            {
                output=-1;
                return output;
            }
            for(int j=0;j<l2;j++)
            {
                output=i;
                if(s1[i+j]!=s2[j])
                {
                    output=-1;
                    break;
                }
            }
          if(output!=-1)
            break;
        }
    }
    return output;
}


int main()
{
    int answer=-1;
    readString();
    l1=strlen(s1);
    l2=strlen(s2);
    answer=checkSubstring();
    if(answer==-1)
        cout<<"Substring not present"<<endl;
    else
        cout<<"Substring is present starting at index :"<<answer<<endl;

}


