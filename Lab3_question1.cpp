#include <iostream>
using namespace std;
class node	//creates a class which tells the computer what a node is
{
 public:
 int data;
 node *prev,*next;
};
class linkedList	//creates a linked list
{
 private:
 node *head,*tail;
 public:
 linkedList()	//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void insert(int data)
 {
  node *temp=new node;
  temp->data=data;
  temp->prev=NULL;
  temp->next=NULL;
  if(head==NULL)
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   temp->prev=tail;
   tail=temp;
  }
 }
 void insertAt(int pos, int data)
 {
  node *temp=new node;
  temp->data=data;
  temp->prev=NULL;
  temp->next=NULL;
  node *t1=new node;
  t1=head;
  int c=0;
  while(t1!=NULL)
  {
   t1=t1->next;
   c++;
  }
  if(pos>c
  )
  {
   cout<<"The linked list does not have that many elements\n";
  }
  else
  {
   node *t=new node;
   t=head;
   for(int i=1;i<pos-1;i++)
   {
    t=t->next;
   }
   if(t==tail)
   {
    t->next=temp;
    temp->prev=t;
    tail=temp;
   }
   else
   {
    temp->prev=t;
    temp->next=t->next;
    t->next->prev=temp;
    t->next=temp;
   }
  }
 }
 void deleteN()
 {
  node *temp=new node;
  temp=head;
  while(temp!=tail)
  {
   temp=temp->next;
  }
  temp->prev->next=NULL;
  tail=temp->prev;
  delete temp;
 }
 void deleteAt(int pos)
 {
  node *temp=new node;
  temp=head;
  for(int i=1;i<pos;i++)
  {
   temp=temp->next;
  }
  if(temp==tail)
  {
   temp->prev->next=NULL;
   tail=temp->prev;
  }
  else
  {
   temp->next->prev=temp->prev;
   temp->prev->next=temp->next;
  }
  delete temp;
 }
 int countItems()
 {
  node *temp=new node;
  temp=head;
  int c=0;
  while(temp!=NULL)
  {
   temp=temp->next;
   c++;
  }
  return c;
 }
 void display()
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL) 
  {
   if(temp!=tail)
   cout<<temp->data<<"->";
   else
   cout<<temp->data<<"->NULL\n";
   temp=temp->next;
  }
 }
};
int main()
{
 int n,pos,data;
 linkedList obj;
 cout<<"Enter the no. of entries you want to make\n";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter the data\n";
  cin>>data;
  obj.insert(data);
 }
 obj.display();
 cout<<"Enter the data which you want to insert\n";
 cin>>data;
 cout<<"Enter the position where you want to insert\n";
 cin>>pos;
 obj.insertAt(pos,data);
 obj.display();
 cout<<"The linked list after deleting the last node is\n";
 obj.deleteN();
 obj.display();
 cout<<"Enter the node which you want to delete\n";
 cin>>pos;
 obj.deleteAt(pos);
 obj.display();
 cout<<"The no. of elements\n"<<obj.countItems()<<"\n";
}
