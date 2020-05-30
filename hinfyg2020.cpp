HACKWITHINFYQ ROUND2 Warmup Question1

RESULT : AC || TIME : 1.31 sec 

Question : Galactic Cataclysm 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void fsr(long long int arr[],long long int n,vector<long long int>&r)
{
    stack<pair<long long int,long long int>>s1;
    for(long long int i=n-1;i>=0;i--)
    {
        if(s1.size()==0)
        {
            r.push_back(n);
        }
        else if(s1.size()>0 && s1.top().first<arr[i])
        {
            r.push_back(s1.top().second);
        }
        else if(s1.top().first>=arr[i] && s1.size()>0)
        {
            while(s1.size()>0 && s1.top().first>=arr[i])
            {
                s1.pop();
            }
            if(s1.size()!=0)
            {
                r.push_back(s1.top().second);
            }
            else
            {
                r.push_back(n);
            }
        }
        s1.push({arr[i],i});
    }
}
long long int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<long long int>l,r;
        stack<pair<long long int,long long int>>s;
        for(long long int i=0;i<n;i++)
        {
            if(s.size()==0)
            {
                 l.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<arr[i])
            {
                l.push_back(s.top().second);
            }
            else if(s.top().first>=arr[i] && s.size()>0)
            {
                while(s.size()>0 && s.top().first>=arr[i])
                {
                    s.pop();
                }
                if(s.size()!=0)
                {
                    l.push_back(s.top().second);
                }
                else
                {
                    l.push_back(-1);
                }
            }
            s.push({arr[i],i});
        }
        fsr(arr,n,r);
        reverse(r.begin(),r.end());
        long long int maxi=INT_MIN;
        for(long long int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]*((r[i]-l[i])-1));
        }
        cout<<maxi<<endl;
    }
    return 0;
}
