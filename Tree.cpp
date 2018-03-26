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
     temp->parent=v;
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
     temp->parent=v;
    }
   }
  }
 }
 void deleteN(int key)
 {
  node *p=bsearch(root,key);
  if(p->left == NULL && p->right == NULL)
  {
   if(p->parent->left == p)
   p->parent->left=NULL;
   else
   p->parent->right=NULL;
  }
  else if(p->left == NULL)
  {
   if(p->parent->left == p)
   p->parent->left=p->right;
   else
   p->parent->right=p->right;
  }
  else if(p->right == NULL)
  {
   if(p->parent->left == p)
   p->parent->left=p->left;
   else
   p->parent->right=p->left;
  }
  else
  {
   node *temp=p->left;
   while(temp->right != NULL)
   {
    temp=temp->right;
   }
   if(temp->left != NULL)
   {
    temp->parent->right=temp->left;
    p->data=temp->data;
   }
   else
   {
    temp->parent->right=NULL;
    p->data=temp->data;
   }
  }
 }
 node *bsearch(node *v,int data)
 {
  node *temp=v,*p;
  if(v==NULL)
  {
   cout<<"Not Found\n";
   return NULL;
  }
  else
  {
   if(data < temp->data)
   p=bsearch(temp->left,data);
   else if(data > temp->data)
   p=bsearch(temp->right,data);
   else
   {
    cout<<"Found\n";
    return temp;
   }
   return p;
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
 int n,data;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj.insert(obj.root,data);
 }
 obj.display(obj.root);
 cout<<"\n";
 cout<<"Enter the data you want to search\n";
 cin>>data;
 obj.bsearch(obj.root,data);
 cout<<"Enter the data you want to delete\n";
 cin>>data;
 cout<<"Lets find your data\n";
 obj.deleteN(data);
 cout<<"After deleting it...\n";
 obj.display(obj.root);
 cout<<"\n"; 
 return 0;
}

