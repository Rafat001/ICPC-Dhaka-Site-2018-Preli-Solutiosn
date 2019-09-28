#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
//#include <bits/stdc++.h>

using namespace std;

#define HI              printf("HI\n")
#define sf              scanf
#define pf              printf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define sf4ll(a,b,c,d)    scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define pb              push_back
#define ppb             pop_back
#define ppf             push_front
#define popf            pop_front
#define ll              long long int
#define ui              unsigned int
#define ull             unsigned long long
#define fs              first
#define sc              second
#define clr( a, b )     memset((a),b,sizeof(a))
#define jora            pair<int, int>
#define jora_d          pair<double, double>
#define jora_ll         pair<long long int, long long int>
#define mp              make_pair
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define PI              acos(-1.0)
#define ps              pf("PASS\n")
#define popc(a)         (__builtin_popcount(a))

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

/// <---------------------------  For Bitmasking  -------------------------------->
//int on( int n, int pos ){
//    return n = n|( 1<<pos );
//}
//bool check( int n, int pos ){
//    return (bool)( n&( 1<<pos ) );
//}
//int off( int n, int pos ){
//    return n = n&~( 1<<pos );
//}
//int toggle( int n, int pos ){
//    return n = n^(1<<pos);
//}
//int count_bit( int n ){
//    return __builtin_popcount( n );
//}
/// <---------------------------  End of Bitmasking  -------------------------------->


/// <--------------------------- For B - Base Number System ----------------------------------->
//int base;
//int pw[10];
//void calPow(int b){
//    base = b;
//    pw[0] = 1;
//    for( int i = 1; i<10; i++ ){
//        pw[i] = pw[i-1]*base;
//    }
//}
//int getV(int mask, int pos){
//    mask /= pw[pos];
//    return ( mask%base );
//}
//int setV(int mask, int v, int pos){
//    int rem = mask%pw[pos];
//    mask /= pw[pos+1];
//    mask = ( mask*base ) + v;
//    mask = ( mask*pw[pos] ) + rem;
//    return mask;
//}
/// <--------------------------- End B - Base Number System ----------------------------------->


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//double Expo(double n, int p) {
//	if (p == 0)return 1;
//	double x = Expo(n, p >> 1);
//	x = (x * x);
//	return ((p & 1) ? (x * n) : x);
//}

//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MXN 50
#define MXE
#define MXQ
#define SZE 3000000
#define MOD
#define EPS
#define INF 1000000000
#define MX  300000
#define inf 100000000


char str[MX];
int trie[MX][26],tr2[MX][26],tr3[MX][26];
int vis[MX][26],casio=1,id,id2,id3;
int sm[MX],val[MX],ans[MX];
vector<int>my[MX];
vector<string>vc;
int main()
{

    int i,j,k,l,m,n,ts,cs=1;
    scanf("%d",&ts);
    while(ts--){
    vc.clear();
    for(int i=0;i<=id;i++)
    {
        for(int j=0;j<26;j++)trie[i][j]=0;
    }
    for(int i=0;i<=id2;i++)
    {
        my[i].clear();
        for(int j=0;j<26;j++)tr2[i][j]=0;
    }
    id=0,id2=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&sm[i]);
    for(int p=0; p<n; p++)
    {
        scanf("%s",str);
        int cur=0;
        for(int i=0; str[i]; i++)
        {
            int c=str[i]-97;
            if(trie[cur][c]==0)trie[cur][c]=++id;
            cur=trie[cur][c];
        }
        vc.pb(str);
        string s;
        s+=str;
        sort(s.begin(),s.end());
        int root=0;
        for(int i=0; s[i]; i++)
        {
            int c=s[i]-97;
            if(tr2[root][c]==0)tr2[root][c]=++id2;
            root=tr2[root][c];
        }
        my[root].pb(p);
    }
    int q;
    scanf("%d",&q);
    for(int p=0; p<q; p++)
    {
        scanf("%s",str);
        int ln=0,cur=0;
        for(int i=0; str[i]; i++)
        {
            int c=str[i]-97;
            if(trie[cur][c]==0)break;
            ln++;
            cur=trie[cur][c];
        }
        vc.pb(str);
        ans[p]=ln;
        string s;
        s+=str;
        sort(s.begin(),s.end());
        int root=0;
        for(i=0; s[i]; i++)
        {
            int c=s[i]-97;
            if(tr2[root][c]==0)break;
            root=tr2[root][c];
        }
        if(i==s.size())my[root].pb(p+n);
    }
    for(int i=1; i<=id2; i++)
    {
        id3=0;
        casio++;
        val[0]=0;
        for(j=0; j<my[i].size(); j++)
        {
            if(my[i][j]>=n)break;
            int cur=0;
            int l=my[i][j];
            val[0]=max(val[0],sm[l]);
            string s=vc[l];

            for(int p=0; s[p]; p++)
            {
                int c=s[p]-97;
                if(vis[cur][c]!=casio)
                {
                    vis[cur][c]=casio;
                    tr3[cur][c]=++id3;
                    val[id3]=sm[l];
                }
                cur=tr3[cur][c];
                val[cur]=max(val[cur],sm[l]);
            }
        }
        for(k=j;k<my[i].size();k++)
        {
            int l=my[i][k];
            string s=vc[l];
            ans[l-n]=max(ans[l-n],val[0]);
            int ln=0;
            int cur=0;
            for(int p=0;s[p];p++)
            {
                int c=s[p]-97;
                if(vis[cur][c]!=casio)break;
                cur=tr3[cur][c];
                ln++;
                ans[l-n]=max(ans[l-n],ln+val[cur]);
            }
        }
    }
   // printf("Case %d:\n",cs++);
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
}


}
