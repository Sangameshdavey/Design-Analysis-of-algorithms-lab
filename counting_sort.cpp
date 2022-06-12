/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;


void countingsort(int *arr,int k,int n)
{
    int c[k+1]={0};
    
    
    int b[n];
    for(int j=0;j<n;j++)
    {
        c[arr[j]]=c[arr[j]]+1;
        
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int j=n-1;j>=0;j--)
    {
        b[c[arr[j]]-1]=arr[j];
        c[arr[j]]=c[arr[j]]-1;
        
    }
    for(int i=0;i<n;i++)
    {
    	cout<<b[i];
	}
	
    
    
    
}
int main()
{
    cout<<"Hello World";

    int arr[]={5,4,3,2,1};
    int k=5;
    countingsort(arr,k,5);
    
}
