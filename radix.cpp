/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;


void countingsort(int *arr,int n,int expa)
{
    int k=9;
    int c[k+1]={0};
    
    
    int b[n];
    for(int j=0;j<n;j++)
    {
        c[(arr[j]/expa)%10]++;
        
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int j=n;j>=0;j--)
    {
        b[c[(arr[j]/expa)%10]-1]=arr[j];
        c[(arr[j]/expa)%10]--;
        
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
    
    
    
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixSort(int arr[],int n)
{
    int m=getMax(arr,n);
    for(int expa=1;m/expa>0;expa*=10)
    {
        countingsort(arr,n,expa);
    }
    //sort(arr,arr+n);
}
int main()
{
    cout<<"Hello World";

    int arr[]={500,4432,3111,21,1};
    int k=5;
    radixSort(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
   
}