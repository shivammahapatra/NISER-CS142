#include <iostream>
using namespace std;
/*Write a class for Bubble sort. It should include:
Function that takes an array as input along with the size of the array. It must return the sorted array using Bubble sort.
Function that takes an linked list as input. It must return the sorted linked list using Bubble sort.*/
class node		//defining a node
{
 public:
 int data;
 node *next;
};
class linkedList		//defining a linked list
{
 public:
 int size=0;
 node *head,*tail;
 linkedList()		//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void addNode(int data)		//adds element to the list
 {
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//checking the list is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
  size++;
 }
 void display()		//displays the list
 {
  node *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
 }
};
class BubbleSort		//implementing bubble sort
{
 public:
 int* sortArray(int a[],int size)		//bubble sort in array
 {
  int t;	
  for(int i=0;i<size;i++)
  {
   for(int j=i;j<size;j++)		//swapping
   {
	if(a[i]>a[j])
	{
   	 	t=a[j];
   		a[j]=a[i];
   		a[i]=t;
	}
   }
  }
  return a;		//returns array
 }
 node* sortLL(node* head,node* tail,int size)		//bubble sort in linked list
 {
  int t;
  node *temp=head;	
  for(int i=0;i<size;i++)
  {
   temp=head;
   while(temp!=tail)
   {
   	if(temp->data>temp->next->data)		//swapping 
   	{
   	 t=temp->data;
   	 temp->data=temp->next->data;
   	 temp->next->data=t;
	}
	temp=temp->next;
   }
  }
  return head;		//returns the address to the first node
 }
};
int main()
{
 //implements the sorting functions
 BubbleSort obj1;
 int a[5]={5,3,6,1,2};
 obj1.sortArray(a,5);
 for(int i=0;i<5;i++)
 {
  	cout<<a[i]<<" ";
 }
 cout<<"\n";
 linkedList obj2;
 obj2.addNode(5);
 obj2.addNode(3);
 obj2.addNode(6);
 obj2.addNode(1);
 obj2.addNode(2);
 obj2.display();
 cout<<"\n";
 node *head=obj1.sortLL(obj2.head,obj2.tail,obj2.size);
 cout<<"The address of the linked list starts from this head "<<head<<"\nThe data in this node is "<<head->data<<"\nThe sorted linked list is\n";
 obj2.display();
}
