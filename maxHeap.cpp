#include <iostream>
using namespace std;
class maxHeap
{
    public:
    int a[100],size=0,q=0;
    void insert(int data)
    {
	a[size]=data;
        q=size;	
	int parent=(q-1)/2;
        while(a[q] > a[parent])
	{
            int t=a[q];
	    a[q]=a[parent];
	    a[parent]=t;
 	    q=parent;
	    parent=(q-1)/2;
	}
	size++;
    }
    int maxVal(int a,int b)
    {
        if(a>b)
        return a;
        else
        return b;
    }
    void remove()
    {
        int l=size-1,i=0,max=0;
        a[i]=a[l];
        size--;
        int lchild,rchild;
        lchild=2*i+1;
        rchild=2*i+2;
        while(a[i] < a[lchild] || a[i] < a[rchild])
	{
            if(lchild < size && rchild < size)
            {
                max=maxVal(a[lchild],a[rchild]);
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
            lchild=2*i+1;
            rchild=2*i+2;
        }    
    }
    void display()
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
        
   
