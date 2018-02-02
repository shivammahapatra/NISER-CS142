#include <iostream>
using namespace std;
class node		//creates a class and tells the computer what a node is
{
 public:
 int data;
 node *prev,*next;
};
class StackLL		//creates a queue from two stacks using linked list
{
 private:
 node *head,*tail;
 public:
 StackLL()		//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void push(int data)		//adds element to the list
 {
  node *temp=new node;
  temp->data=data;
  temp->prev=NULL;
  temp->next=NULL;
  if(head==NULL)		//checking if the list is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   head->prev=temp;
   temp->next=head;
   head=temp;
  }
 }
 int pop()		//returns the last element
 {
  int p=head->data;
  head=head->next;
  head->prev=NULL;
  return p;
 }
 void display1()	//displays the two stacks
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL) 	//goes upto the last node
  {
   cout<<temp->data<<"\n";
   temp=temp->next;
  }
 }
 //displaying after converting into queue
 void display2()	//displays the 1st stack
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<"->";
   temp=temp->next;
  }
 }
 void display3()	//displays the 2nd stack
 {
  node *temp=new node;
  temp=tail;
  while(temp!=NULL)
  {
   if(temp==head)
   cout<<temp->data<<"\n";
   else
   cout<<temp->data<<"->";
   temp=temp->prev;
  }
 } 
};
int main()
{
 int data,n;
 //objects creation and functions calling
 StackLL obj1,obj2;
 cout<<"Enter the number of entries you want to make in the 1st stack\n";
 cin>>n;
 cout<<"For 1st stack\n";
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj1.push(data);
 }
 cout<<"The 1st stack is\n";
 obj1.display1();
 cout<<"Enter the number of entries you want to make in the 2nd stack\n";
 cin>>n;
 cout<<"For 2nd stack\n";
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj2.push(data);
 }
 cout<<"The 2nd stack is\n";
 obj2.display1();
 cout<<"Now implementing queue using two stacks\n";
 cout<<"Enter the data you want to push\n";
 cin>>data;
 obj1.push(data);
 cout<<"After implementing push\n";
 obj1.display2();
 obj2.display3();
 cout<<"Popping out the last element\n"<<obj2.pop()<<"\n";
 cout<<"After implementing pop\n";
 obj1.display2();
 obj2.display3();
}


