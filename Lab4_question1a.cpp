#include <iostream>
using namespace std;
class node		//creating a class that tells the computer what a node is
{
 public:
 int data;
 node *next;
};
class StackLL		//creating a stack
{
 private:
 node *head;
 public:
 StackLL()		//constructor to initialize
 {
  head=NULL;
 }
 void push(int data)		//pushes element to the stack
 {
  node *temp=new node;		//pointer that points to the new node created
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//checking if the stack is empty
  {
   head=temp;
  }
  else
  {
   temp->next=head;
   head=temp;
  }
 }
 int pop()		//returns the top element
 {
  int p=head->data;
  head=head->next;
  return p;
 }
 void display()		//displays the stack
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL)		//goes upto the last element
  {
   cout<<temp->data<<"\n";
   temp=temp->next;
  }
 }
};
int main()
{
 int data,n;
 //object creation and functions calling
 StackLL obj;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj.push(data);
 }
 cout<<"The stack is\n";
 obj.display();
 cout<<"Enter the data you want to push\n";
 cin>>data;
 obj.push(data);
 cout<<"After implementing push\n";
 obj.display();
 cout<<"Popping out the last element\n"<<obj.pop()<<"\n";
 cout<<"After implementing pop\n";
 obj.display();
}
                                                      
