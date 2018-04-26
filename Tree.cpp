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
    void deleteN(int key)
    {
        node *p=bsearch(root,key);		//calls bsearch function to get the position of the key
        if(p->left == NULL && p->right == NULL)		//checking for a leaf node
        {
            if(p->parent->left == p)		//if it is the left child
            p->parent->left=NULL;		//make the left pointer of the parent NULL
            else
            p->parent->right=NULL;		//make the right pointer of the parent NULL
            delete p;		//deletes the node
        }
        else if(p->left == NULL || p->right == NULL)		//if it has only one child
        {
            if(p==root)		//if it is root
            {
   	            if(p->left!=NULL)		//has only left child
   	            root=p->left;		//make the left child the root
   	            else
   	            root=p->right;		//make the right child the root
            }
            else		//not root
            {
                if(p->left == NULL)		//has only right child
                {
                    if(p->parent->left == p)		//is the left child of its parent
                    p->parent->left=p->right;		//links the left pointer of the parent with the right child of the node
                    else
                    p->parent->right=p->right;		//links the right pointer of the parent with the right child of the node
                    delete p;		//deletes the node
                }
                else 
                {
                    if(p->parent->left == p)		//is the left child of its parent
                    p->parent->left=p->left;		//links the left pointer of the parent with the left child of the node
                    else
                    p->parent->right=p->left;		//links the right pointer of the parent with the left child of the node
                    delete p;		//deletes the node
                }
            }
        }
        else		//if it has two children
        {
	    //taking the largest smaller element	
            node *temp=p->left;		
            if(temp==NULL)
            while(temp->right != NULL)
            {
                temp=temp->right;
            }
	    //now temp is at the largest smaller element	
            if(temp->left != NULL)		//it has left child		
            {
                p->data=temp->data;		//puts the temp's data in the node  
                if(temp->parent->left == temp)		//if it is the left child
                temp->parent->left=temp->left;		//links the left pointer of the parent with the left child of the node
                else
                temp->parent->right=temp->left;		//links the right pointer of the parent with the left child of the node
                delete temp;
            }
            else
            {
                p->data=temp->data;		//puts the temp's data in the node
                if(temp->parent->left == temp)		//if it is the left child
                {
                    temp->parent->left=NULL;		//makes the left child of the parent NULL
                    delete temp->parent->left;		//deletes the node
                }
                else
                {
	                temp->parent->right=NULL;		//makes the right child of the parent NULL
	                delete temp->parent->right;		//deletes the node
                }
            }
        }
    }
    node *bsearch(node *v,int data)		//returns the address of the key value
    {
        node *temp=v,*p;
        if(v==NULL)		//if not found
        {
            cout<<"Not Found\n";
            return NULL;
        }
        else
        {
            if(data < temp->data)		
            p=bsearch(temp->left,data);		//searches to the left of the node
            else if(data > temp->data)
            p=bsearch(temp->right,data);		//searches to the right of the node
            else
            {
                cout<<"Found\n";
                return temp;		//returns the address of the key value
            }
            return p;
        }
    }
    void rSearch(node *v,int l,int r)		//find all the values between a given range
    {
        if(v==NULL)
        return;
        rSearch(v->left,l,r);
        if(v->data >= l && v->data <= r)
        cout<<v->data<<" ";
        rSearch(v->right,l,r);
    }
    void display(node *v)		//displays the tree by in-order traversal method
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
    //objects creation and functions calling
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
    cout<<"Enter the lower limit\n";
    cin>>l;
    cout<<"Enter the upper limit\n";
    cin>>r;
    obj.rSearch(obj.root,l,r);
    cout<<"\n";
    return 0;
}

