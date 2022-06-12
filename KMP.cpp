#include <bits/stdc++.h>
using namespace std;

void computeLPS(char *pat,int m,int *lps)
{
    
    int len=0;
    
    lps[0]=0;
    
    int i=1;
    
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
             if(len!=0)
            {
                len=lps[len-1];//mug
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
       
    }
}

void KMP(char *pat,char *text)
{
    int m=strlen(pat);
    int n=strlen(text);
    
    int lps[m];
    
    computeLPS(pat,m,lps);
    
    int i=0;int j=0;
    while(i<n)
    {
        if(pat[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"found at: "<<i-j;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
                
            }
            else
            {
                i++;
            }
        }
    }
    
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMP(pat,txt);
    return 0;
    
}