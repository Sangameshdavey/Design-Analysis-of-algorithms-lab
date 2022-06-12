#include<bits/stdc++.h>
using namespace std;


int crossing_sum(int arr[],int l,int m,int h)
{
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=l;i<=m;i++)
    {
        sum+=arr[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }
    int sum1=0;
    int right_sum=INT_MIN;
    for(int i=m+1;i<=h;i++)
    {
        sum1+=arr[i];
        if(sum1>right_sum)
        {
            right_sum=sum1;
        }
    }
    
    return(max(left_sum,max(right_sum,right_sum+left_sum)));
}
int maxsubarray(int arr[],int l,int h)

{
    if(l==h)
    {
        return arr[l];
    }
    int m=(l+h)/2;
    return max(maxsubarray(arr,l,m),max(maxsubarray(arr,m+1,h),crossing_sum(arr,l,m,h)));
}
int main()
{
    int arr[]={1,2,3,4,5};
    int ans=maxsubarray(arr,0,4);
    
   std::cout << ans << std::endl;
    
    
    
}