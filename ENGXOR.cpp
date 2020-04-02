Time : 0.47 || Mem : 15.7 || Result : 100%AC


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
        int set;
        int odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            set=__builtin_popcount(v[i]);
            if(set%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        int p;
        for(int i=0;i<q;i++)
        {
            cin>>p;
            set=__builtin_popcount(p);
            if(set%2==0)
            {
                cout<<even<<" "<<odd<<"\n";
                continue;
            }
            else
            {
                cout<<odd<<" "<<even<<"\n";
                continue;
            }
        }
    }
    return 0;
}
