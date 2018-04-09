#include <iostream>
using namespace std;
class node		//defines what a node is
{
    public:
    int data;
    node *parent,*left,*right;
    node()		//constructor to initialize the variables
    {
        data=0;
        parent=NULL;
        left=NULL;
        right=NULL;
    }
};
class Tree		//creating a binary tree
{
    public:
    node *root=NULL;
    int totalN=0,internalN=0,leafN=0,c=0;
    void insert(node *v,int data)		//inserts elements in the tree
    {
        node *temp=new node;
        temp->data=data;
        if(root==NULL)		//checking if the tree is empty
        {
            root=temp;
        }
        else
        {
            if(data < v->data)		//if entry data is less than node's data, then it goes to its left child
            {
                if(v->left != NULL)		//if there is some data in that node, then it again compares its data with the entry data
                {
                    insert(v->left,data);		//recursion call
                }
                else		//if there is no data in that node, then it inserts the entry data there
                {
                    v->left=temp;
                    temp->parent=v;
                }
            }
            else			//if entry data is greater than node's data, then it goes to its right child 
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
    void countN(node *v)
    {
        if(v==NULL)
        return;
        countN(v->left);
        if(v->left == NULL && v->right == NULL)
        leafN++;
        else 
        internalN++;
        countN(v->right);
        totalN++;
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
            delete p;
        }
        else if(p->left == NULL || p->right == NULL)
        {
            if(p==root)
            {
   	            if(p->left!=NULL)
   	            root=p->left;
   	            else
   	            root=p->right;
            }
            else
            {
                if(p->left == NULL)
                {
                    if(p->parent->left == p)
                    p->parent->left=p->right;
                    else
                    p->parent->right=p->right;
                    delete p;
                }
                else 
                {
                    if(p->parent->left == p)
                    p->parent->left=p->left;
                    else
                    p->parent->right=p->left;
                    delete p;
                }
            }
        }
        else
        {
            node *temp=p->left;
            if(temp==NULL)
            while(temp->right != NULL)
            {
                temp=temp->right;
            }
            if(temp->left != NULL)
            {
                p->data=temp->data;
                if(temp->parent->left == temp)
                temp->parent->left=temp->left;
                else
                temp->parent->right=temp->left;
                delete temp;
            }
            else
            {
                p->data=temp->data;
                if(temp->parent->left == temp)
                {
                    temp->parent->left=NULL;
                    delete temp->parent->left;
                }
                else
                {
	                temp->parent->right=NULL;
	                delete temp->parent->right;
                }
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
    void rSearch(node *v,int l,int r)
    {
        if(v==NULL)
        return;
        rSearch(v->left,l,r);
        if(v->data >= l && v->data <= r)
        {
            cout<<v->data<<" ";
            c++;
        }
        rSearch(v->right,l,r);
    }
    void rSearch1(node *v,int l,int r)
    {
        node *temp=v;
        if(v==NULL)
        return;
        else
        {
            if(temp->data >= l && temp->data <= r)
            {
 	  	if(temp->data > l)  
                rSearch1(temp->left,l,r);
                cout<<temp->data<<" ";
                c++;
                if(temp->data < r)
                rSearch1(temp->right,l,r);
            }
            else if(temp->data > l)
            rSearch1(temp->left,l,r);
            else if(temp->data < r)
            rSearch1(temp->right,l,r);
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
    int n,data,l,r;
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
    obj.countN(obj.root);
    cout<<"The total number of nodes\n"<<obj.totalN<<"\n";
    cout<<"The number of internal nodes\n"<<obj.internalN<<"\n";
    cout<<"The number of leaf nodes\n"<<obj.leafN<<"\n";     
    cout<<"Enter the lower limit\n";
    cin>>l;
    cout<<"Enter the upper limit\n";
    cin>>r;
    obj.rSearch1(obj.root,l,r);
    cout<<"\nThe number of such elements within this range\n"<<obj.c<<"\n";
    return 0;
}

