Time : 0.00 || Mem : 14.9 || Result : 100% AC

#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>f(n);
        vector<int>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back(make_pair(f[i],p[i]));
        }
        sort(vp.begin(),vp.end());
        vector<int>sum;
        int summer=vp[0].second;
        for(int i=0;i<vp.size()-1;i++)
        {
            if((vp[i].first)==(vp[i+1].first))
            {
                summer+=vp[i+1].second;
            }
            else
            {
                sum.push_back(summer);
                summer=vp[i+1].second;
            }
        }
        sum.push_back(summer);
        sort(sum.begin(),sum.end());
        cout<<sum[0]<<endl;
    }
    return 0;
}
