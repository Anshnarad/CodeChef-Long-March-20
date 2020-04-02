Time : 3.34 || Mem : 782 || Result : 100%AC


#include <bits/stdc++.h>
using namespace std;
const long msize = 100001;
vector<long>arr1(msize);
long p1;
vector<long>arr2(msize);
long brr1[10001][10001];
vector<long>arr3(msize);
vector<long>arr4(msize);
vector<long>arr5(msize);
vector<long>arr6(msize);
vector<bool>arr7(msize);

void hcf_1(long num1,long num2,long &p2,long &p3)
{
    if(num2==1)
    {
        hcf_1(num2,num1%num2,p2,p3);
    }
    else
    {
        p2=1;
        p3=0;
        return;
    }
}

long hcf_2(long num1,long num2)
{
    if(num2==0)
    {
        return num1;
    }
    else
    {
        return hcf_2(num2,num1%num2);
    }
}

struct dta
{
    long id;
    long ll;
    long rr;
    friend bool operator < (const dta& num1,const dta& num2)
    {
        if(arr3[num1.ll] != arr3[num2.ll])
        {
            return arr3[num1.ll] < arr3[num2.ll];
        }
        else
        {
            return num1.rr < num2.rr;
        }
    }
}

dta[msize];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    arr1[0] = 1;
    for(int i=0;i<10001;i++)
    {
        brr1[0][i] = 0;
        brr1[i][0] = 1;
    }
    for(int i=1;i<msize;i++)
    {
        long z=arr1[i-1];
        arr1[i] = (z*i) % 998244353;
    }
    for(int i=1;i<10001;i++)
    {
        for(int j=1;j<=i;j++)
        {
            long zx=brr1[i-1][j];
            long zy=brr1[i-1][j-1];
            brr1[i][j] = (zx+zy) % 998244353;
        }
    }
    vector<long long>vectrr;
    for(long long rep=1;rep<1000;rep++)
    {
        vectrr.push_back(rep*10);
    }
    long t, n, q, ll, rr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        unordered_map<long, long> mapp;
        long sq = sqrt(n);
        for(long i=1;i<=n;i++)
        {
            cin>>arr2[i];
            long trev=(i-1);
            arr3[i] = (trev/sq)+1;
        }
        for(long i=1;i<=n;i++)
        {
            if(mapp.find(arr2[i])==mapp.end())
            {
                mapp[arr2[i]] = mapp.size();
            }
            arr2[i] = mapp[arr2[i]];
        }
        cin>>q;
        for(long i=1;i<=q;i++)
        {
            cin>>dta[i].ll>>dta[i].rr;
            dta[i].id = i;
        }
        for(long k=0;k<msize;k++)
        {
            arr5[k]=0;
        }
        for(long k=0;k<msize;k++)
        {
            arr4[k]=0;
        }
        for(long k=0;k<msize;k++)
        {
            arr7[k]=0;
        }
        for(long k=0;k<msize;k++)
        {
            arr6[k]=0;
        }
        p1 = 0;
        sort(dta+1, dta+q+1);
        long left = 1, right = 0;
        vector<long> arr_result(q+1);
        for(int i=1;i<=q;i++)
        {
            while(right<dta[i].rr)
            {
                long p2=arr2[right+1];
                ++arr5[++arr6[p2]];
                arr4[++p1]=arr6[p2];
                --arr5[arr6[p2]-1];
                right++;
            }
            
            while(right>dta[i].rr)
            {
                long p2=arr2[right];
                ++arr5[--arr6[p2]];
                arr4[++p1]=arr6[p2];
                --arr5[arr6[p2]+1];
                right--;
            }
            
            while(left<dta[i].ll)
            {
                long p2=arr2[left];
                ++arr5[--arr6[p2]];
                arr4[++p1]=arr6[p2];
                --arr5[arr6[p2]+1];
                left++;
            }
            
            while(left>dta[i].ll)
            {
                long p2=arr2[left-1];
                ++arr5[++arr6[p2]];
                arr4[++p1]=arr6[p2];
                --arr5[arr6[p2]-1];
                left--;
            }
            long k = 0,result = 0;
            vector<long> v;
            for(long j=1;j <= p1;j++)
            {
                if((arr5[arr4[j]]>=1))
                {
                    if(!arr7[arr4[j]])
                    {
                        v.push_back(arr4[j]);
                        arr4[++k]=arr4[j];
                        arr7[arr4[j]]=true;
                    }
                }
            }
            p1=k;
            for(int j=1;j<=k;j++)
            {
                arr7[arr4[j]] = false;
            }
            long sum = 0;
            for(long i: v)
            {
                if(arr5[i]%2)
                {
                    sum^=0;
                    sum=sum^i;
                }
            }
            if(sum==0)
            {
                arr_result[dta[i].id] = 0;
                continue;
            }
            else
            {
                long ans, temp1;
                for(long i: v)
                {
                    if(arr5[i]>=1)
                    {
                        ans = sum^i;
                        if(ans >= i+1)
                        {
                            continue;
                        }
                        long n=i;
                        long m=n-ans;
                        if(n<10001)
                        {
                            temp1=brr1[n][m];
                        }
                        else if(m>n)
                        {
                            temp1=0;
                        }
                        else if(m==1 || m==n-1)
                        {
                            temp1=n;
                        }
                        else if(n==m)
                        {
                            temp1=1;
                        }
                        else
                        {
                            long p2,p3,num3,num4,dist;
                            num3=arr1[n];
                            num4=(arr1[m]*arr1[n-m]);
                            num4%=998244353;
                            dist=hcf_2(num3,num4);
                            dist^=0;
                            num3/=dist;
                            num3^=0;
                            num4/=dist;
                            num4^=0;
                            hcf_1(num4,998244353,p2,p3);
                            p2=(p2+998244353)%998244353;
                            p2%=998244353;
                            temp1=(p2*num3)%998244353;
                            temp1%=998244353;
                        }
                        temp1 = (temp1*arr5[i])%998244353;
                        temp1%=998244353;
                        result =(result+temp1)%998244353;
                        result%=998244353;
                    }
                }
            }
            arr_result[dta[i].id] = result;
        }
        for(int i=1;i<=q;i++)
        {
            cout<<arr_result[i]<<endl;
        }
    }
    return 0;
}
