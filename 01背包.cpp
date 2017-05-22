#include<iostream>
int max(int a,int b)
{
	return a>b?a:b;
}
using namespace std;
int w[10000];
int weight[10000];
int value[10000];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
		cin>>value[i]; 
	} 
	int total;
	for(int i=0;i<n;i++)
	{
		total=m;
		for(int j=total;j>=weight[i];j--)
		w[j]=max(w[j-weight[i]]+value[i],w[j]);
	}
	cout<<w[m];
	return 0;
} 
