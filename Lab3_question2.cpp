#include <iostream>
using namespace std;
class node	//creates a class node and tells the computer what a node data-type is
{
 public:
 int data;
 node *next;
};
class linkedList	//creates a linked list
{
 private:
 node *head;
 public:
 linkedList()	//constructor to initialize the variables
 {
  head=NULL;
 }
 void insert(int data)	//inserts the entered data at the end 
 {
  node *temp=new node;	//creates a temporary node and stores the entered data
  temp->data=data;	//stores the data in the data section of the node
  temp->next=NULL;	//points to NULL
  if(head==NULL)	//checking if the list is empty 
  {
   head=temp;	
   temp->next=head;
  }
  else
  {
   node *t=new node;
   t=head;
   while(t->next!=head)	//going upto the last node
   {
   	t=t->next;
   }
   //adding a node at the end
   t->next=temp;
   temp->next=head;
  }
 }
 void insertAt(int pos, int data)	//inserts the entered data in the desired position
 {
  node *temp=new node;	//creates a temporary node and stores the entered data
  temp->data=data;
  temp->next=NULL;
  node *t1=new node;
  t1=head;
  int c=1;
  while(t1->next!=head)
  {
   t1=t1->next;
   c++;
  }
  if(pos>c)	//checking if it exceeds the number of elements
  cout<<"The linked list does not contain that many elements\n";
  else
  {
   node *t=new node;
   t=head;
   for(int i=1;i<pos-1;i++)	//going upto the previous node
   {
    t=t->next;
   }
   if(t->next==head)	//if it is the last node
   {
    t->next=temp;
    temp->next=head;
   }
   else
   {
    temp->next=t->next;
    t->next=temp;
   }
  }
}
 void deleteN()	//deletes the last node
 {
  node *temp=new node;
  node *t=new node;	//stores the address of the node which the user wants to delete
  temp=head;
  while(temp->next->next!=head)	//goes upto the previous node
  {
   temp=temp->next;
  }
  t=temp->next;
  temp->next=head;
  delete t;
 }
 void deleteAt(int pos)	//deletes the desired node
 {
  node *temp=new node;
  node *t=new node;	//stores the address of the node which the user wants to delete
  temp=head;
  for(int i=1;i<pos-1;i++)	//goes upto the previous node
  {
   temp=temp->next;
  }
  if(temp->next->next==head)	//checking if the node which is to be deleted is the last node
  {
   t=temp->next;
   temp->next=head;
  }
  else
  {
   t=temp->next;
   temp->next=temp->next->next;
  }
  delete t;
 }
 int countItems()	//counts the number of elements in the list
 {
  node *temp=new node;
  temp=head;
  int c=0;	//stores the number of elements
  while(temp->next!=head)	//goes to the last node
  {
   temp=temp->next;
   c++;
  }
  return c+1;
 }
 void display()	//displays the linked list
 {
  node *temp=new node;
  temp=head;
  cout<<temp->data<<"->";
  temp=temp->next;
  while(temp->next!=head->next) 	//goes through all the nodes
  {
   if(temp->next!=head)
   cout<<temp->data<<"->";
   else
   cout<<temp->data<<"\n";
   temp=temp->next;
  }
 }
};
int main()
{
 int n,pos,data;
 linkedList obj;	//creates an object of class linkedList
 //function calling and displaying
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
