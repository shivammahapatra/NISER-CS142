#include <iostream>
using namespace std;
class maxHeap		//class to create a max heap using array
{
    public:
    int a[100],size=0,q=0;
    void insert(int data)		//inserts data in the array
    {
	a[size]=data;		//insert data at the last index
        q=size;	
	int parent=(q-1)/2;
        while(a[q] > a[parent])		//if greater than parent
	{
	    //swapping and move the index to the parent
            int t=a[q];
	    a[q]=a[parent];
	    a[parent]=t;
 	    q=parent;
	    parent=(q-1)/2;
	}
	//the data goes to its right position
	size++;
    }
    int maxVal(int a,int b)		//returns the maximum of two values
    {
        if(a>b)
        return a;
        else
        return b;
    }
    void remove()		//removes the root
    {
        int l=size-1,i=0,max=0;
        a[i]=a[l];
        size--;
        int lchild,rchild;
        lchild=2*i+1;
        rchild=2*i+2;
        while(a[i] < a[lchild] || a[i] < a[rchild])		//till the parent is less than any of its child
	{
            if(lchild < size && rchild < size)		//if both the indexes are within the size limit
            {
                max=maxVal(a[lchild],a[rchild]);		//gets the maximum of both children
                //swapping with the maximum of both children
		if(a[lchild]==max)
                {
	            int t=a[i];
                    a[i]=a[lchild];
                    a[lchild]=t;
                    i=2*i+1;
                }
                else
                {
	            int t=a[i];
		    a[i]=a[rchild];
		    a[rchild]=t;
                    i=2*i+2;
	        }
            }
	    else if(lchild < size)
            {
                int t=a[i];
                a[i]=a[lchild];
                a[lchild]=t;
                i=2*i+1;
            }
	    else
            break;
	    //updating the indexes
            lchild=2*i+1;
            rchild=2*i+2;
        }    
    }
    void display()		//displays the heap
    {
        for(int i=0;i<size;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
};
int main()
{
    //object creation and fnctions calling
    maxHeap obj;
    int n,data;
    cout<<"Enter the number of elements\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter data\n";
 	cin>>data;
	obj.insert(data);
    }
    obj.display();
    cout<<"Removing the root...\n";
    obj.remove();
    obj.display();
}
        
   
