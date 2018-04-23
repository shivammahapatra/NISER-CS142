#include <iostream>
#include <time.h>
using namespace std;
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
 void timeBA(int size)
 {
  int a[size];
  for(int i=0;i<size;i++)
  {
   a[i]=rand();
  }
  clock_t t;
  t=clock();
  sortArray(a,size);
  t=clock()-t;
  cout<<"The time taken for implementing bubble sort in an array for "<<size<<" inputs="<<(float)t/CLOCKS_PER_SEC;
 }
 void timeBLL(int size)
 {
  linkedList obj;
  for(int i=1;i<size;i++)
  {
   obj.addNode(rand());
  }
  clock_t t;
  t=clock();
  sortLL(obj.head,obj.tail,obj.size);
  t=clock()-t;
  cout<<"The time taken for implementing bubble sort in a linked list for "<<size<<" inputs="<<(float)t/CLOCKS_PER_SEC;  
 }
};
class QuickSort		//implements quick sort
{
 public:
 int* quickSortArray(int a[],int low,int high)		//quick sort in array
 {
  int t,key=0;
  if(low<high)		//goes till the array consists of a single element
  {
   int pivot=high;
   for(int i=0;i<=high;i++)
   {
    if(a[i]>a[pivot])
    {
   	 for(int j=i;j<=high;j++)
   	 {
   	  if(a[i]>a[j])		//swapping the entries
   	  {
   	   t=a[i];
	   a[i]=a[j];
	   a[j]=t;	 	
	  }
     }
    }
   }
   for(int i=low;i<=high;i++)		//to find the exact position where the pivot should be
   {
    if(a[i]>a[pivot])
    {
   	 key=i;
   	 break;
    }
   }
   if(key!=0)		//shifting the pivot to its actual position
   {
    t=a[pivot];
    a[pivot]=a[key];
    a[key]=t;
   }
  }
  if(key!=0)
  {
   quickSortArray(a,low,(key-1));		//calling the elements less than the pivot for sorting
   quickSortArray(a,(key+1),high);		//calling the elements greater than the pivot for sorting
  } 
  return a;		//returns the sorted array
 }
 void QuickSortLL(node *head,node *tail,int low,int high)		//quick sort in linked list
 {
  int t,key=0;
  node *temp;
  if(low<high)		//goes till it contains a single node
  {
   node *pivot=tail;
   temp=head; 
   for(int i=low;i<=high;i++)
   { 
    if(temp->data > pivot->data)		//swapping
    {
   	 for(int j=i;j<=high;j++)
   	 {
   	  node *t1=temp;
   	  if(temp->data > t1->data)
   	  {
   	   t=temp->data;
	   temp->data=t1->data;
	   t1->data=t;	 	
	  }
	  t1=t1->next;
     }
    }
   }	
   temp=head;
   for(int i=low;i<=high;i++)		//finding the actual position of the pivot
   {
    if(temp->next->data > pivot->data)
    {
   	 key=i;
   	 break;
    }
    temp=temp->next;
   }
   if(key!=0)		//moving the pivot to its actual position
   {
    t=pivot->data;
    pivot->data=temp->next->data;
    temp->next->data=t;
   }
  }
  if(key!=0)
  {
   QuickSortLL(head,temp,low,(key-1));		//calling the elements less than the pivot
   QuickSortLL(temp->next->next,tail,(key+1),high);		//calling the elements greater than the pivot
  } 
 }
 void timeQA(int size)
 {
  int a[size];
  for(int i=0;i<size;i++)
  {
   a[i]=rand();
  }
  clock_t t;
  t=clock();
  quickSortArray(a,0,(size-1));
  t=clock()-t;
  cout<<"The time for implementing quick sort in an array for "<<size<<" inputs="<<(float)t/CLOCKS_PER_SEC;
 }
 void timeQLL(int size)
 {
  linkedList obj;
  for(int i=1;i<size;i++)
  {
   obj.addNode(rand());
  }
  clock_t t;
  t=clock();
  QuickSortLL(obj.head,obj.tail,1,obj.size);
  t=clock()-t;
  cout<<"The time taken for implementing bubble sort in a linked list for "<<size<<" inputs="<<(float)t/CLOCKS_PER_SEC;  
 }
};
int main()
{
 BubbleSort obj1;
 QuickSort obj2;
 obj1.timeBA(100);
 obj1.timeBLL(100);
 obj2.timeQA(100);
 obj2.timeQLL(100);
}
