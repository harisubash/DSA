/**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 *  Author: Harikrishnan Subash
 *
 *  Date : September 28th ,2014
 *
 *  Start Time : 17:30
 *
 *   Menu driven Program to create a doubly linked list with dynamic functionality
 *
 *  NOTE: List numbering starts from 0.
 *
 *
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

class Node
{
 public:
 Node* next;
 Node* prev;
 int roll;
 char name[20];

};


class doublyll
{
    Node *head=NULL,*tail=NULL;
    public:
    void createList();
    bool isEmpty();
    void AppendNode(int pos);
    void deleteNode(int pos);
    void print_forward();
    void print_reverse();
//    void sort();
    int search(int key);
    int count();

};
int main()
{
    int choice,key,pos=-1;
    doublyll List,temp;
    while(1)
    {
        cout<<" \n Doubly Linked List Manipulation : Choose your command "<<endl;
        cout<<"1. Create a New Doubly Linked List"<<endl
            <<"2. Check if the list is empty"<<endl
            <<"3. Append a new Node into a particular position"<<endl
            <<"4. Delete a node from position"<<endl
            <<"5. Print the entire list in forward direction"<<endl
            <<"6. Print the entire list in the reverese order"<<endl
            <<"7. Search for a particular Node "<<endl
            <<"8. Sort the list in the increasing order based on key"<<endl
            <<"9. Count the number of elements in the list "<<endl
            <<"10. Swap two elements in the list "<<endl
            <<"11. Exit from the program"<<endl;
        cin>>choice;
        switch(choice)
        {
         case 1 : if(List.isEmpty())
                      List.createList();
                  else
                    cout<<"The List is NOT Empty"<<endl;
                  break;
         case 2 : if(List.isEmpty())
                    cout<<"The List is Empty"<<endl;
                  else
                    cout<<"The list is not Empty"<<endl;
                  break;
         case 3 : if(List.isEmpty())
                  {
                    cout<<"List is Empty. Creating a new List." <<endl;
                    List.createList();
                  }
                else{
                    cout<<"Enter the position into which you wish to append a node"<<endl;
                    cin>>key;
                    List.AppendNode(key);
                   }
                    break;
         case 4:  if(List.isEmpty())
                    {
                        cout<<"The List is Empty"<<endl;
                        break;
                    }
                   cout<<"Enter the position node of to be deleted"<<endl;
                   cin>>key;
                   List.deleteNode(key);
                  break;
         case 5:  if(List.isEmpty())
                  {
                    cout<<"The List is Empty"<<endl;
                    break;
                  }
                  List.print_forward();
                  break;
         case 6:  if(List.isEmpty())
                   {
                    cout<<"The List is Empty"<<endl;
                 break;
                   }
                  List.print_reverse();
                  break;
         case 7:  if(List.isEmpty())
                    {
                     cout<<"The List is Empty"<<endl;
                     break;
                    }
                  cout<<"Enter the key for searching :";
                  cin>>key;
                  cout<<endl;
                  pos=-1;
                  pos=List.search(key);
                  if(pos!=-1)
                   {
                    cout<<"Node found at Position : "<<pos<<endl;
                    }
                   else
                          cout<<"No such node "<<endl;
                    break;
//         case 8:  if(List.isEmpty())
//                   {
//                    cout<<"The List is Empty"<<endl;
//                    break;
//                   }
//                  temp=List;
//                  temp.sort();
//                  break;
         case 9:  if(List.isEmpty())
                  {
                   cout<<"The List is Empty"<<endl;
                   break;
                  }
                 cout<<"Numberof Elements in List : "<<List.count()<<endl;
                 break;

         case 10:  exit(0);
         default: cout<<"Invalid Response"<<endl<<"Enter your response again"<<endl<<endl;
        }
    }
  return 0;
}

void doublyll::createList()
{
    Node *ptr;
    ptr=new Node;
    ptr->prev=NULL;
    ptr->next=NULL;
    cout<<"Enter the name :";
    scanf("%s",(ptr->name));
    cout<<"Enter the Roll number :";
    cin>>ptr->roll;
    head=ptr;
    tail=ptr;
    cout<<" New List has been created.\n";
}

bool doublyll::isEmpty()
{
   if((head==NULL)&&(tail==NULL))
       return true;
   else
       return false;

}

void doublyll::AppendNode(int pos)
{

// While the position is being taken , even if it is far beyond the count of the list ,
// the program is written such that the elemnt is to be added at the last .
Node *ptr,*loc;
loc=head;
int i=0;
ptr=new Node;

cout<<"Enter the name:";
scanf("%s",(ptr->name));
cout<<"Enter the roll number :";
cin>>ptr->roll;
ptr->next=NULL;
ptr->prev=NULL;
int N=count();

if(pos<=0)
{
head->prev=ptr;
ptr->next=head;
ptr->prev=NULL;
head=ptr;
}
else if(pos>=N)
    {
    ptr->prev=tail;
    tail->next=ptr;
    ptr->next=NULL;
    tail=ptr;
    }
    else
    {
    loc=head;
    i=0;
    while((i<pos))
         {
            loc=loc->next;
            i++;
         }
   (loc->prev)->next=ptr;
    ptr->prev=loc->prev;
    loc->prev=ptr;
    ptr->next=loc;
    }
 cout<<"\n Node Appended "<<endl;
}

void doublyll::print_forward()
{
    Node *ptr;
    ptr=head;
    cout<<"NULL"<<"<==>";
    while(ptr!=NULL)
       {
         cout<<ptr->roll<<"<==>";
         ptr=ptr->next;
       }
       cout<<"NULL";
}



int doublyll::count()
{
    int cnt=0;
    Node *ptr;
    ptr=head;
    while(ptr!=NULL)
       {
         cnt++;
         ptr=ptr->next;
       }
 return cnt;
}


void doublyll::print_reverse()
{
    Node *ptr;
    ptr=tail;
    cout<<"NULL"<<"<==>";
    while(ptr!=NULL)
       {
         cout<<ptr->roll<<"<==>";
         ptr=ptr->prev;
       }
       cout<<"NULL";
}


void doublyll::deleteNode(int pos)
{
    int N=count();
    if((pos<0)||(pos>N-1))
    {
        cout<<"Invalid Position . "<<endl;
        return;
    }
    Node *ptr,*loc;
    int i=0;
    ptr=new Node;
    if(N==1)
    {
        loc=head;
        head=NULL;
        tail=NULL;
    }
    else if(pos==0)
    {
    loc=head;
    ptr=head->next;
    ptr->prev=NULL;
    head=ptr;
    }
    else if(pos==N-1)
        {
        loc=tail;
        ptr=tail->prev;
        ptr->next=NULL;
        tail=ptr;
        }
        else
        {
        loc=head;
        i=0;
        while((i<pos))
             {
                loc=loc->next;
                i++;
             }
        ptr=loc;
        (ptr->prev)->next=ptr->next;
        (ptr->next)->prev=ptr->prev;
       }
    cout<<"\n Node Deleted "<<endl;
    delete loc;
}


int doublyll::search(int key)
{
Node *ptr;
int pos=0;
ptr=head;
while(ptr!=NULL)
{
    if(ptr->roll==key)
       return pos;
    else
        ptr=ptr->next;
    pos++;
}
return -1;
}
