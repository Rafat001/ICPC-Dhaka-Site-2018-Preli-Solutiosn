
#include <bits/stdc++.h>

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
int dx[]= {1,1,2,2,-1,-1,-2,-2}; /*night move*/
int dy[]= {2,-2,1,-1,2,-2,1,-1}; /*night move*/

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

#define MXK 10000000
#define MXE
#define MXQ
#define SZE
#define MOD
#define EPS
#define INF 1000000000
#define MX  3000000
#define inf 100000000
#define mod 1000000007


struct state
{
    int len, link;
    map<char,int>nexto;
};
int sz,last;

state st[MX];
ll pr[MX],dp[MX];
int line[MX];
void sa_init()
{
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    st[0].nexto.clear();
    ++sz;
}
void ini(int v)
{
    assert(v < MX);
    st[v].len = 0;
    st[v].link = 0;
    st[v].nexto.clear();
}
void sa_extend (char c)
{
    int cur = sz++;
    ini(sz-1);

    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].nexto.count(c); p=st[p].link)
        st[p].nexto[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].nexto[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else
        {
            int clone = sz++;
            ini(sz-1);
            st[clone].len = st[p].len + 1;
            st[clone].nexto = st[q].nexto;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].nexto[c]==q; p=st[p].link)
                st[p].nexto[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
char str[3000000];

void pre()
{
     pr[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        pr[i]=(pr[i-1]*26)%mod;
        dp[i]=dp[i-1]+pr[i];
        dp[i]%=mod;
    }
}

int main()
{
    pre();
    int ts,casio=1;
    cin>>ts;
    while(ts--){
    scanf("%s",str);
    sa_init();
    int n=strlen(str);
    for(int i=0; str[i]; i++)
    {
        sa_extend(str[i]);
    }
    memset(line, 0, sizeof line);
    for(int i=1; i<sz; i++)
    {
        int f=st[st[i].link].len+1;
        line[f]++;
        line[st[i].len+1] --;
    }
    for(int i = 1; i <= n; i++){
        line[i] += line[i-1];
        line[i] %= mod;
    }
    for(int i = 1; i <= n; i++){
        line[i] += line[i-1];
        line[i] %= mod;
    }
    int q,l,k;
    scanf("%d",&q);
    printf("Case %d:\n",casio++);
    while(q--)
    {
        scanf("%d%d",&l,&k);
        ll ans=dp[k]-dp[l-1];
        if(ans<0)ans=(ans+mod)%mod;
        ll ret=line[k] - line[l-1];
        if(ret < 0) ret += mod;
        ans-=ret;
        if(ans<0)ans=(ans+mod)%mod;
        printf("%lld\n",ans);
    }
}



}
