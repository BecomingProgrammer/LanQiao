#include<iostream>
#include<cmath> 
using namespace std;
int shi[10];
int num=0;
int sum=0;
int count(long  long a)
{
	if(a==0)
	{
		if(shi[a]==1)
		return -1;
		else
		{
			shi[0]=1;
			num++;
			return 0; 
		} 
	}
 
	else
	{
		int count1=num;
		int temp[10];
		for(int i=0;i<10;i++)
		temp[i]=shi[i];
		while(a!=0)
		{
			if(temp[a%10]==1)
			return -1;
			else
			{
				count1++;
				temp[a%10]=1;
				a/=10;
			}
		}
		num=count1;
		for(int i=0;i<10;i++)
		shi[i]=temp[i];
		return 0;
	}
}
 
void reset(long  long a)
{
	if(a==0)
	{
		num--;
		shi[0]=0;
	}
	else
	{
		while(a!=0)
		{
			shi[a%10]=0;
			num--;
			a/=10;
		}
	}
}
int main()
{
	int n=sqrt(9876543210);
	long  long  a[n+10];
 
	for(int i=0;i<=n;i++)
	{
		a[i]=i*i;
	} 
	int first=0;
	int i=0;
	while(first<=n)
	{
		if(num==10)
		{
			sum++;
			reset(a[i-1]);
		}
		if(i>n)
		{
			first++;
			i=first;
			if(first>n)
			break;
		}
		if(count(a[i])==0)
		{
			i++; 
		} 
		else
		{
			i++;
		}
	}
	cout<<sum;
	return 0;
} 
