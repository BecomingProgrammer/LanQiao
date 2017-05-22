#include<iostream>
#include<algorithm>
using namespace std;
long long sum[100];
long long w[100][100];
int n,k;
int main()
{
	cin>>n>>k;
	long long  temp;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;

	    	sum[i]=sum[i-1]+temp;
	   
	}
	for(int i=1;i<=n;i++)
	w[i][0]=sum[i];
	for(int i=2;i<=n;i++)
	{
		int m=min(i-1,k);
		for(int j=1;j<=m;j++)
		{
			for(int t=2;t<=i;t++)
			{
				int s=sum[i]-sum[t-1];
				w[i][j]=max(w[t-1][j-1]*s,w[i][j]);
			}
		}
	}
	cout<<w[n][k];
	return 0;
} 
