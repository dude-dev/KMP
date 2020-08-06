#include<iostream>
#include<fstream>
using namespace std;
class KMP
{
    char *p, *t;
    int m, n,*f;
    int **delta;
   public:
   KMP()
   {
	ifstream fp;
	fp.open("string.txt");
	if(fp.fail())
	{
	    exit(1);
	    cout<<"fail";
	}
	fp>>n;
	fp>>m;
	p=new char[m];
	t=new char[n];
	for(int i=0;i<n;i++)
		fp>>t[i];
	for(int i=0;i<m;i++)
		fp>>p[i];
	f=new int[m+1];
	kmp();
   }
   void failureFunction()
   {
   	f[0]=0;
   	int j=0,i=1;
   	while(i<m)
   	{
   		if(p[i] == p[j])
   		{
   			f[i]=j+1;
   			i++;
   			j++;
   			
   		}
   		else if(j>0)
   		{
   			j=f[j-1];
   			
   		}
   		else
   		{
   			f[i]=0;
   			i++;
   			
   		}
   	}
   	
   }
   void kmp()
   {
   	failureFunction();
   	int i=0,j=0;
   	while(i<n)
   	{
   		if(t[i]==p[j])
   		{
   			if(j == m-1)
   			{
   				cout<<"pattern found at "<<i-j<<endl;
   				j=f[j-1];
   				
   			}
   			else
   			{
   				i++;
   				j++;
   			}
   		}
   		else
   		{
   			if(j>0)
   				j=f[j-1];
   			else
   				i++;
   		}
   	}
   }
};
int main()
{
	KMP k;
	return 0;
}
