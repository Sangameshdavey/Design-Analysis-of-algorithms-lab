#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int matrixdp(int arr[],int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j]=min(dp[i][j],matrixdp(arr,i,k)+matrixdp(arr,k+1,j)+(arr[i-1]*arr[j]*arr[k]));
    }
    return dp[i][j];
}
int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    int arr[]={1,2,3,4};
    cout<<matrixdp(arr,1,3);
    
}