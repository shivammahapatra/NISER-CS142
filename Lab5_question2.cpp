#include <iostream>
using namespace std;
//defining a node
class node
{
 public:
 int data;
 node *next;
};
//defining a linked list
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
 void addNode(int data)		//adds a node to the list
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
class quickSort		//implements quick sort
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
};
int main()
{
 //implementing the quick sort functions
 quickSort obj;
 int a[]={2,7,8,3,6,9,4,5,1};
 cout<<"The array is\n";
 for(int i=0;i<9;i++)
 {
  cout<<a[i]<<" ";
 }
 cout<<"\nThe sorted array is\n";
 obj.quickSortArray(a,0,8);
 for(int i=0;i<9;i++)
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
 obj2.addNode(7);
 obj2.addNode(9);
 obj2.addNode(8);
 obj2.addNode(4);
 cout<<"The linked list is\n";
 obj2.display();
 cout<<"\n";
 obj.QuickSortLL(obj2.head,obj2.tail,1,obj2.size);
 obj2.display();
}
