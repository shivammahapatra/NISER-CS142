#include <iostream>
using namespace std;
class StackArrays		//creates a stack using arrays
{
 public:
 int i=0;
 int a[10000];
 void push(int data)	//adds element to the stack
 {
  a[i]=data;
  i++;
 }
 int pop()		//returns the top element
 {
  int p=a[i-1];
  i--;
  return p;
 }
 void display()		//displays the stack
 {
  for(int k=i-1;k>=0;k--)
  {
   cout<<a[k]<<"\n";
  }
 }
}; 
int main()
{
 int n,data;
 //object creation and functions calling
 StackArrays obj;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=0;i<n;i++)
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
 cout<<"Popping\n"<<obj.pop();
 cout<<"\nAfter implementing pop\n";
 obj.display();
}
  
