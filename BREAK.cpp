Time : 0.34 || Mem : 16.7 || Result : 50% AC

// Link to the problem : https://www.codechef.com/MARCH20B/problems/BREAK/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s;
    cin>>t>>s;
    while(t--)
    {
        int n,f=0;
        cin>>n;
        vector<long long int>v1(n);
        vector<long long int>v2(n);
        vector<long long int>t;
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<n;i++)
        {
            cin>>v2[i];
        }
        sort(v2.begin(),v2.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]>=v2[i])
            {
                cout<<"NO"<<endl;
                f=1;
                break;
            }
        }
        if(f==1)
        {
            continue;
        }
        else
        {
            f=0;
            int cont=0;
            for(int i=0;i<n-1;i++)
            {
                t.push_back(v1[i]);
                t.push_back(v2[i]);
                count++;
                for(int j=0;j<t.size();j++)
                {
                    if(v1[i+1]==t[j])
                    {
                        cont=1;
                        break;
                    }
                    if((j==t.size()-1) && (v1[i+1]!=t[j]))
                    {
                        cout<<"NO"<<endl;
                        f=1;
                        break;
                    }
                }
                if(f==1)
                {
                    break;
                }
            }
            if(f==1)
            {
                continue;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
}
