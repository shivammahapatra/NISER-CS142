/*Implement Binary search function. Include
Function that takes in array, size of array and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. 
Function that takes in linked list and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. */
#include <iostream>
using namespace std;
//creating a class node and defining what a node is
class node
{
 public:
 int data;
 node *next;
};
//creating a linked list
class linkedList
{
 public:
 int size=0;
 node *head,*tail;
 linkedList()		//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void addNode(int data)		//adds element to the linked list 
 {
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//checking if the list is empty
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
 void display()		//displays the linked list
 {
  node *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
 }
};
int bsearchArray(int a[],int lsize, int rsize, int key)		//function to implement binary search in array
{
 int mid=(lsize+rsize)/2;
 if(key<=a[rsize] && key>=a[lsize])		//checking if the key is within the array
 {
  if(a[mid]==key)
  {
   cout<<"\nFound at index ";
   return mid;
  }
  else
  {
   if(a[mid]<key)
   {
	bsearchArray(a,mid+1,rsize,key);		//calling to the right part of mid
   }
   else
   {
	bsearchArray(a,lsize,mid-1,key);		//calling to the left part of mid
   }
  }
 }
 else
 {
  cout<<"\nNot found ";
  return -1;
 }
}
int bsearchLL(node *head,node *tail,int key,int lsize,int rsize)		//function to implement binary search in linked list
{
 int mid=(lsize+rsize)/2;
 node *temp=head;
 for(int i=1;i<mid-1;i++)		//goes upto the previous node of mid
 {
  temp=temp->next;
 }
 if(key<=tail->data && key>=head->data)		//checking if the key is within the linked list
 {
  if(key==temp->next->data)
  {
   cout<<"\nFound at node no ";
   return mid;
  }
  else
  {
   if(key<temp->next->data)
   {
   	bsearchLL(head,temp,key,lsize,(mid-1));		//calling to the nodes to the left of the middle node
   }
   else
   {
   	bsearchLL(temp->next->next,tail,key,(mid+1),rsize);		//calling to the nodes to the right of the middle node
   }
  }
 }
 else
 {
  cout<<"\nNot found ";
  return -1;
 }
}
int main()
{
 //creates an array and a linked list and implements binary search in both by object creation and function calling
 int a[]={1,2,3,4,5};
 int key=3;
 int size=5;
 cout<<"The array is\n";
 for(int i=0;i<size;i++)
 {
  cout<<a[i]<<" ";
 }	
 cout<<"\nThe key is "<<key;	
 cout<<bsearchArray(a,0,size-1,key)<<"\n";
 linkedList obj1;
 obj1.addNode(1);
 obj1.addNode(2);
 obj1.addNode(3);
 obj1.addNode(4);
 obj1.addNode(5);
 cout<<"The linked list is\n";
 obj1.display();
 cout<<"\nThe key is "<<key;
 cout<<bsearchLL(obj1.head,obj1.tail,key,1,obj1.size);
 return 0;
}
