Time : 0.00 || Mem : 14.9 || Result : 100% AC
// This Question is my favourite. I personally Recommend to do this!

// Link to the problem : https://www.codechef.com/MARCH20B/problems/ADASHOP2/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int r0,c0;
        cin>>r0>>c0;
        if(r0!=1||c0!=1)
        {
            int md=(r0+c0)/2;
            cout<<"20"<<endl;
            cout<<md<<" "<<md<<endl;
            cout<<"1 1\n";
        }
        else
        {
            cout<<"18"<<endl;
        }
        cout<<"8 8\n";
        cout<<"7 7\n";
        cout<<"8 6\n";
        cout<<"6 8\n";
        cout<<"5 7\n";
        cout<<"4 8\n";
        cout<<"8 4\n";
        cout<<"7 3\n";
        cout<<"8 2\n";
        cout<<"2 8\n";
        cout<<"1 7\n";
        cout<<"7 1\n";
        cout<<"6 2\n";
        cout<<"5 1\n";
        cout<<"1 5\n";
        cout<<"2 4\n";
        cout<<"1 3\n";
        cout<<"3 1\n";
    }
    return 0;
}
