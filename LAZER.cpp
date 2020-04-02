Time : 0.06 || Mem : 14.9 || Result : 30% AC



#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        long long int x1,x2,y,count;
        for(int i=0;i<q;i++)
        {
            count=0;
            cin>>x1>>x2>>y;
            x1--;
            x2--;
            for(long long int j=x1;j<x2;j++)
            {
                if((v[j]>y) && (v[j+1]<=y))
                {
                    count++;
                }
                else if((v[j]<y) && (v[j+1]>=y))
                {
                    count++;
                }
                else if(y==v[j])
                {
                    if(y==v[j+1])
                    {
                        count+=2;
                    }
                    else
                    {
                        count++;
                    }
                }
            }
            cout<<count<<"\n";
        }
    }
    return 0;
}
