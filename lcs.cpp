#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int lcsdp(char X[],char Y[],int m,int n)
{
    if(m==0 || n==0)
    {
        return 0;
        
    }
    if(X[m-1]==Y[n-1])
    {
        dp[m][n]=1+lcsdp(X,Y,m-1,n-1);
        return dp[m][n];
    }
    if(dp[m][n] !=-1)
    {
        return dp[m][n];
    }
    dp[m][n]=max(lcsdp(X,Y,m-1,n),lcsdp(X,Y,m,n-1));
    return dp[m][n];
    
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
    
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
 
    int m = strlen(X);
    int n = strlen(Y);
    cout<<lcsdp(X,Y,m,n);
    
}