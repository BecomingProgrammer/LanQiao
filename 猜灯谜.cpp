#include<iostream>
using namespace std;
int main()
{
	int sum1,sum2;
	int a,b,c,d,e,f;
	for( a=1;a<=9;a++)
	for(b=0;b<10;b++ )
	for(c=0;c<10;c++)
	for(d=0;d<10;d++)
	for(e=0;e<10;e++)
	for(f=0;f<10;f++)
	{
		sum1=a*100+b*10+c;
		sum2=a*100000+d*10000+e*1000+f*100+d*10+b;
		if(sum1*sum1==sum2)
		cout<<sum1;
	}
} 
