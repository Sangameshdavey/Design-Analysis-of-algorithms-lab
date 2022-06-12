#include<bits/stdc++.h>
using namespace std;
void search(char pat[],char txt[],int q)
{
    int h=1;
    int m=strlen(pat);
    int n=strlen(txt);
    int d=256;
    h=pow(d,m-1);
    h=h%q;
    int p=0;
    int t=0;
    int i,j;
    
    
    for(int i=0;i<m;i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
        
        
    }
    
    for(int i=0;i<n-m;i++)
    {
        if(p==t)
        {
            for( j=0;j<m;j++)
            {
                if(pat[j]!=txt[i+j])
                break;
            }
            if(j==m)
            {
                cout<<"found at"<<i;
            }
        }
        
        if(i<n-m)
        {
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            
            if(t<0)
            {
                t=t+q;
            }
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
       
      //we mod to avoid overflowing of value but we should take as big q as possible to avoid the collison
    int q =INT_MAX;
     
      // Function Call
      search(pat, txt, q);
    return 0;
}