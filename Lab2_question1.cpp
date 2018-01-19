#include <iostream>
using namespace std;
class node	//creates a class node which defines a particular user-defined data-type
{
 public:	//makes the variables public
 int data;	
 node *next;	//declaring pointer of node type
};		//node is a data-type which consists of a data and an address
class linkedList	//creates a linkedList
{
 private:	//makes 'head' and 'tail' private
 node *head;	//stores the address of the first node
 node *tail;	//stores the address of the last node
 public:
 linkedList()	//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void insert(int data)	//takes data as input from the user and adds a node at the end
 {
  node *temp=new node;	//creates a new pointer of node type
  temp->data=data;	//stores the input in the data section of a node to which 'temp' points
  temp->next=NULL;	//the next pointer of the new node points to NULL
  if(head==NULL)	//checking if head is NULL
  {
   head=temp;	//no element in linkList, so making the new node as both head and tail
   tail=temp;
  }
  else
  {
   tail->next=temp;	//the last node points to the new node
   tail=temp;	//the new node becomes the last node
  }
 }
 void insertAt(int pos,int data)	//inserts the entered data in the given position
 {
  node *p=new node();	//pointer used to count the number of nodes
  int c=1;	
  p=head;
  while(p!=tail)	//counts the number of nodes
  {
   p=p->next;
   c++;
  }
  if(pos<=c)	//checks if the entry is a valid entry
  {
   node *temp=new node;	
   temp->data=data;
   temp->next=NULL;
   node *t=head;
   node *t1;
   for(int i=1;i<pos-1;i++)	//goes upto the previous node
   {
    t=t->next;
   }
   t1=t->next;
   t->next=temp;
   temp->next=t1;
  }
  else
  {
   cout<<"Linked List does not have that many elements";
  }
 }
 void deleteN()		//deletes the last node
 {
  node *t=head;
  node *t1;
  while(t->next!=tail)		//goes upto the previous node
  {
   t=t->next;
  }
  t->next=NULL;
  t1=tail;
  tail=t;
  delete t1;
 }
 void deleteAt(int pos)		//deletes the node at given position
 {
  node *temp=new node();
  node *t=new node();
  node *t1=new node();
  temp=head;
  for(int i=1;i<pos;i++)	//goes upto the given node and stores the address of the next node
  {
   temp=temp->next;
  }
  t=temp->next;
  t1=temp;
  temp=head;
  for(int i=1;i<pos-1;i++)		//goes upto the previous node and links it to the node after the given node
  {
   temp=temp->next;
  }
  temp->next=t;
  delete t1;	//deletes the given node
 }
 int countItems()		//counts the number of elements in the linked list
 {
  node *temp=new node();
  int c=1;
  temp=head;
  while(temp!=tail)		//counts the number of elements
  {
   temp=temp->next;
   c++;
  }
  return c;
 }
 void display()
 {
  node *t;	//creates a new pointer of node type
  t=head;	//t points to the node which head was pointing
  while(t!=NULL)	//it runs till we reach the last node
  {
   //used to print in the given format
   if(t==tail)
   cout<<t->data<<"\n";	 //displays the elements of the list
   else 
   cout<<t->data<<"->";	
   t=t->next;	//moves the pointer to the next node
  }
 }
};
int main()
{
 int data,d,p,pos;	
 linkedList obj;       //creates an object of class linkedList
 for(int i=1;i<=5;i++)
 {
  cout<<"Enter the data to be added\n";
  cin>>data;	//takes the input in data
  obj.insert(data);	//calls the insert function and passes data as value	
 }
 //function calling and displaying one after another
 cout<<"The linked list is \n";
 obj.display();
 cout<<"Enter the data you want to insert\n";
 cin>>d;
 cout<<"Enter the position\n";
 cin>>p; 
 obj.insertAt(p,d);
 cout<<"The linked list after inserting the element\n";
 obj.display();	//calls the display function
 cout<<"The linked list after deleting the last node\n";
 obj.deleteN();
 obj.display();
 cout<<"Enter the nth node to be deleted\n";
 cin>>pos;
 cout<<"The linked list after deleting the nth node \n";
 obj.deleteAt(pos);
 obj.display();
 cout<<"The number of elements in linked list is\n";
 cout<<obj.countItems();
}

