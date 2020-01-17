#include<iostream>
#include<algorithm>  //for inbuilt sort function
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
  	int flag=0,mid,index;
  	
	mid=(startIndex+lastIndex)/2;
	
	if(startIndex<=lastIndex)
	{
		if(array[mid]==element)
		{
			flag=1;	
			index=mid;
		}
		else if(array[mid]<element)
		{
			return binarySearchReacursive(array,mid+1,lastIndex,element);
		}
		else
		{
			return binarySearchReacursive(array,startIndex,mid-1,element);
		}
	 
	}
	    if(flag==0)
  	    {
  	   		cout<<"Recusrion  : "<<element<< "Not found!!!";
   			
   	   } 
      else
       {
   			cout<<"\nBinary search using recursion....... "<<element<<" is found at index "<<index;
       } 
	 
  return true;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int	mid=(startIndex+lastIndex)/2;
	
	int flag=0,index;
	
	while(startIndex<=lastIndex)
        {
             
            if(array[mid]==element)
            {
            	index=mid;
                flag=1;
                break;
            }
            else if(array[mid]<element)
                {
                    startIndex=mid+1;
                }
        	else
        	{
            	lastIndex=mid-1;
        	}	    
             
			mid=(startIndex+lastIndex)/2;
		}
             
        	if(flag==1)
        	{
        		cout<<"\nBinary search using iteration...... "<<element<<" is found at index "<<index;
			}
			else
			{
				cout<<"Iteration : "<<element<<" Not found!!\n";		
			}
			
	return true;
}
	
int main()
{	
	int size,ele;
	
	cout<<"Enter the size of array : ";
	cin>>size;
	
	int *a=new int[size];      //dynamic allocation of array
	
	cout<<"\nEnter elements of array : ";
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+size);  //sorting using inbuilt function
	
	cout<<"\nArray after sorting : ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\nEnter element you want to search : ";
	cin>>ele;
	
	binarySearchIterative(a,0,size-1,ele);
	binarySearchReacursive(a,0,size-1,ele);
  
  return 0;
}
