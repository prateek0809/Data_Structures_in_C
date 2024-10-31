#include<iostream>
using namespace std;

void linear(int a[],int size,int num)
{
	int f=1;
	for(int i=0;i<=size;i++)
	{
		if(a[i] == num)
		{
		f=0;
    	cout<<"The number is Present at index "<<i-1<<endl;
		break;
	    }
	}
	if(f==1)
	cout<<"The number is not Present"<<endl;
}


void binary(int a[], int size, int num)
{
    int beg = 0, end = size - 1;
    int mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == num)
        {
            cout<<"The number is present at index "<<mid<<endl;
            return;
        }
        else if (a[mid] < num)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << "The number is not present at any index" << endl;
}



int main()
{
	int n, choice;
	cout<<"Choose the algorithm you want to use for searching...."<<endl;
	cout<<"Press '1' for Linear search algorithm"<<endl;
	cout<<"Press '2' for Binary search algorithm"<<endl;
	cin>>choice;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	if(choice == 1)
	{
		cout<<"Initialize the array elements"<<endl;
    }
    else if(choice == 2)
    {
    	cout<<"Initialize the sorted array elements"<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int search;
	cout<<"Enter the number you want to search"<<endl;
	cin>>search;
	if(choice == 1)
	{
		linear(arr,n,search);
    }
    else if(choice == 2)
    {
    	binary(arr,n,search);
	}
	else
	{
		cout<<"You enter wrong choice"<<endl;
	}
	return 0;
}
