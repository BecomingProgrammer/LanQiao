#include<iostream>
using namespace std;
int a22[22]={61,46, 47,2,5, 9, 11, 16 ,17, 19, 21, 22, 24, 26, 30, 31, 33, 35, 36,
 41, 50, 52};
int weizhi[154][154];
int a22_choose[22]; 
int n=3;
int wx=0,wy=0,wlen=0;

void find(int x)
{
	int flag=0;
	wlen=0;
    for(int i=x;i<154;i++)
	{
		for(int j=0;j<154;j++)
		{
			if(flag==0&&weizhi[i][j]==0)
			{
				wx=i;
				wy=j;
				flag=1;
				
			}
			if(flag==1&&(weizhi[i][j]))
			{
				return ;
			} 
			if(flag==1&&j==153)
			{
				wlen++;
				return;
			}
			if(flag==1)
			wlen++;
		}
	}	
}

void fill(int x,int y,int flag,int len)
{
	for(int i=x;i<x+len;i++)
	{
		for(int j=y;j<y+len;j++)
		{
			weizhi[i][j]=flag;
		}
	}
}

void f(int n,int x,int y,int len)
{
	if(n==22)
	{
		for(int i=0;i<153;i++)
		cout<<weizhi[153][i];
	}
	else
	{
		for(int i=3;i<22;i++)
		{
			if(a22_choose[i]==0&&len>=a22[i])
			{
				a22_choose[i]=1;
				fill(x,y,a22[i],a22[i]);
				find(x);
				f(n+1,wx,wy,wlen);
				fill(x,y,0,a22[i]);
				a22_choose[i]=0;
			}
		}
	}
}

int main()
{
	fill(0,0,47,47);
	fill(0,47,46,46);
	fill(0,93,61,61);
	a22_choose[0]=a22_choose[1]=a22_choose[2]=1;
	f(3,46,47,46);
}
