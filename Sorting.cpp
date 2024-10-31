#include<iostream>
using namespace std;

int selection(int arr[],int num)
{
	int temp;
	for(int i=0;i<num-1;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(arr[j]<arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout<<"The sorted array using Selection Sort"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<endl;
}

int bubble(int arr[],int num)
{
	int temp,i;
	for(i=0;i<num-1;i++)
	{
		for(int j=0;j<num-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout<<"The array after using Bubble Sort"<<endl;
	for(int i=0;i<num;i++)
	cout<<arr[i]<<"  ";
	cout<<"\n"<<endl;
}

int insertion(int arr[],int num)
{
	for(int i=1;i<num;i++)
	{
		int temp = arr[i];
		int j=i-1;
		while(arr[j]>temp && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	cout<<"The array after using Insertion Sort"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<endl;
}

int main()
{
	int n, choice;


	while(choice != 0)
	{
		cout<<"Choose the algorithm you want to use for Sorting...."<<endl;
		cout<<"Press '1' for Selection Sort algorithm"<<endl;
		cout<<"Press '2' for Bubble Sort algorithm"<<endl;
		cout<<"Press '3' for Insertion Sort algorithm"<<endl;
 		cout<<"Press '0' to exit..."<<endl;
		cin>>choice;
		
		if(choice == 0)
		{
			cout<<"Exiting...."<<endl;
			break;
		}
		else
		{
			cout<<"Enter the size of array"<<endl;
			cin>>n;
			int arr[n];
	
			cout<<"Initialize the array elements"<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}

			if(choice == 1)
			{
				selection(arr,n);
    		}
    		else if(choice == 2)
    		{
    			bubble(arr,n);
			}
			else if(choice == 3)
			{
				insertion(arr, n);
			}
			else
			{
				cout<<"You enter wrong choice"<<endl;
			}
		}
	}
}
