#include <iostream>
using namespace std;
class QueuesArrays		//creates a queue using arrays
{
 public:
 int i=0,r=0;
 int a[10000];
 void enqueue(int data)		//adds element to the queue
 {
  a[i]=data;
  i++;
 }
 int dequeue()		//returns the last element
 {
  return a[0];
 }
 void display(int n,int p)		//displays the queue
 {
  r=p;
  for(int k=r;k<n;k++)
  {
   cout<<a[k]<<" ";
  }
 }
};
int main()
{
 int n,data;
 //object creation and functions calling
 QueuesArrays obj;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj.enqueue(data);
 }
 cout<<"Your Queue is\n";
 obj.display(n,0);
 cout<<"\nEnter the data you want to push\n";
 cin>>data;
 obj.enqueue(data);
 cout<<"After enqueueing\n";
 obj.display((n+1),0);
 cout<<"\nDequeueing\n"<<obj.dequeue()<<"\n";
 cout<<"After dequeueing\n";
 obj.display((n+1),1);
}
