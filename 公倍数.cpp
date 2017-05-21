#include<iostream>
using namespace std;
int zhishu[101];
int a[100];
int chushu[1000];
int count=0;
int n;
int biga[1000];
int bigb[1000];
int carry=0;
void fun()
{
	bigb[999]=1;
	int num;
	for(int i=0;i<count;i++)
	{
	    num=chushu[i];
		for(int j=0;j<num;j++)
		{
			carry=0;
			for(int j1=999;j1>=0;j1--)
			{
				biga[j1]=bigb[j1]+carry+biga[j1];
				if(biga[j1]>=10)
				{
					carry=biga[j1]/10;
					biga[j1]=biga[j1]%10;
					
				}
				else
				{
					carry=0;
				}
			}
		}
		for(int j1=0;j1<1000;j1++)
		{
			bigb[j1]=biga[j1];
			biga[j1]=0;
		}
		
	}
	int flag=0;
	for(int j=0;j<1000;j++)
	{
		if(bigb[j]!=0&&flag==0)
		flag=1;
		if(flag)
		cout<<bigb[j];
	}
}
int main()
{
   int chushu1;
   cin>>n;
   for(int i=2;i<101;i++)
   {
   	for(int j=i*2;j<101;j+=i)
   	{
   		zhishu[j]=1;
   	}
   }
   for(int i=0;i<n;i++)
   {
   	a[i]=i+1;
   }
   for(int i=0;i<n;)
   {
   	if(a[i]!=1)
   	{
   		for(int j=2;j<100;j++)
   		{
   			if(zhishu[j]==0&&a[i]%j==0)
   			{
   				chushu1=j;
   				break;
   			}
   		}
   		chushu[count++]=chushu1; 
   		for(int j=0;j<n;j++)
   		{
   			if(a[j]%chushu1==0)
   			{
   				a[j]=a[j]/chushu1;
   			}
   		}
   	}
   	else
   	{
   		i++;
   	}
   }
  fun();
	return 0;
} 
