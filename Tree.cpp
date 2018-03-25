#include <iostream>
using namespace std;
class node
{
 public:
 int data;
 node *parent,*left,*right;
 node()
 {
  data=0;
  parent=NULL;
  left=NULL;
  right=NULL;
 }
};
class Tree
{
 public:
 node *root=NULL;
 void insert(node *v,int data)
 {
  node *temp=new node;
  temp->data=data;
  if(root==NULL)
  {
   root=temp;
  }
  else
  {
   if(data < v->data)
   {
    if(v->left != NULL)
    {
     insert(v->left,data);
    }
    else
    {
     v->left=temp;
    }
   }
   else
   {
    if(v->right != NULL)
    {
     insert(v->right,data);
    }
    else
    {
     v->right=temp;
    }
   }
 }
}
 void display(node *v)
 {
  if(v==NULL)
  return;
  display(v->left);
  cout<<v->data<<" ";
  display(v->right);
 }

};
int main()
{
 Tree obj;
 obj.insert(obj.root,7);
 obj.insert(obj.root,3);
 obj.insert(obj.root,4);
 obj.insert(obj.root,1);
 obj.insert(obj.root,8);
 obj.display(obj.root);
 return 0;
}

