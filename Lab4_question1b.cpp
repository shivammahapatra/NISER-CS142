#include <iostream>
using namespace std;
class node		//creates a class and tells the computer what a node is
{
 public:
 int data;
 node *next;
};
class QueuesLL		//creates a queue using linked list
{
 private:
 node *head,*tail;
 public:
 QueuesLL()		//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void enqueue(int data)		//adds element to the queue
 {
  node *temp=new node;		//pointer that points to the new node
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//checking if the queue is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
 }
 int dequeue()		//returns the last element
 {
  int p=head->data;
  head=head->next;
  return p;
 }
 void display()		//displays the queue
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL)		//goes upto the last element
  {
   if(temp==tail)
   cout<<temp->data<<"\n";
   else
   cout<<temp->data<<"->";
   temp=temp->next;
  }
 }
};
int main()
{ 
 int data,n;
 //object creation and functions calling
 QueuesLL obj;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj.enqueue(data);
 }
 cout<<"The Queue is\n";
 obj.display();
 cout<<"Enter the data you want to enqueue\n";
 cin>>data;
 obj.enqueue(data);
 cout<<"After adding to the queue\n";
 obj.display();
 cout<<"Dequeueing\n"<<obj.dequeue()<<"\n";
 cout<<"After dequeueing\n";
 obj.display();
}
