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

template<class T1> void deb(T1 e1) {
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2) {
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3) {
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6) {
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
#define MX  105
#define inf 100000000

const int mod = 1000000007;

ll fact[SZE+7], inv[SZE+7];

ll big_mod(ll b, ll p, ll m){
    if( p == 0 )    return 1;
    if( p&1 ){
        ll ret = big_mod(b, p-1, m);
        ret = ( ret*b )%m;
        return ret;
    }
    ll ret = big_mod(b, p/2, m);
    ret = ( ret*ret )%m;
    return ret;
}
void precal(){
    ll i, j, k;
    fact[0] = inv[0] = 1;
    for( i = 1; i<=SZE; i++ ){
        fact[i] = ( fact[i-1]*i )%mod;
    }
    inv[SZE] = big_mod(fact[SZE], mod-2, mod);
    for( i = SZE-1; i>0; i-- ){
        inv[i] = ( inv[i+1]*(i+1) )%mod;
    }
}
ll ncr(ll nn, ll rr){
    if( rr>nn ) return 0;
    ll ret = ( fact[nn]*inv[nn-rr] )%mod;
    ret = ( ret*inv[rr] )%mod;
    return ret;
}

int n, m, block, mag, src, tar, cas;
vector<int> adj[MX+7];
pii arr[MX+7];

bool ok(int p1, int p2){
    if( arr[p2].fs>=arr[p1].fs and arr[p2].sc>=arr[p1].sc )
        return 1;
    return 0;
}

ll cal(int p1, int p2){
    if( !ok(p1, p2) )   return 0;
    int d1 = arr[p2].fs-arr[p1].fs;
    int d2 = arr[p2].sc-arr[p1].sc;
    return ncr(d1+d2, d1);
}

ll dp2[MX+7][MX+7];
int mark2[MX+7][MX+7];
ll rec2(int p1, int p2){
    ll &ret = dp2[p1][p2];
    if( mark2[p1][p2] == cas )  return ret;
    mark2[p1][p2] = cas;
    ret = 0;
    for( auto it:adj[p1] ){
        if( it == p2 or !ok(it, p2) )  continue;
        ll tmp = ( rec2(p1, it)*cal(it, p2) )%mod;
        ret = ( ret+tmp )%mod;
    }
    ret = ( cal(p1, p2)-ret+mod )%mod;
    return ret;
}

ll dp1[MX+7][MX+7];
int mark1[MX+7][MX+7];
ll rec1(int cur, int taken){
    if( cur == tar ){

        return (taken<=mag);
    }
    ll &ret = dp1[cur][taken];
    if( mark1[cur][taken] == cas )  return ret;
    mark1[cur][taken] = cas;
    ret = ( rec2(cur, tar)*rec1(tar, taken) )%mod;
    for( auto it:adj[cur] ){
        if( it==tar )   continue;
        ll res = ( rec2(cur, it)*rec1(it, taken+1) )%mod;
        ret = ( ret+res )%mod;
    }
    return ret;
}

int main() {
	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    //ios_base::sync_with_stdio(0);
//    freopen("00.txt", "r", stdin);
    int t, i, j, k;
    precal();
    sf("%d", &t);

    while(t--){
        sf("%d %d", &n, &m);
        sf("%d %d", &block, &mag);
        for( i = 0; i<=MX; i++ ){
            adj[i].clear();
        }
        src = 0, tar = block+1;
        arr[0] = mp(1, 1);
        for( i = 1; i<=block; i++ ){
            sf("%d %d", &arr[i].fs, &arr[i].sc);
        }
        arr[block+1] = mp(n, m);
        for( i = 0; i<=tar; i++ ){
            for( j = 0; j<=tar; j++ ){
                if( i == j )    continue;
                if( ok(i, j) ){
                    adj[i].pb(j);
                }
            }
        }
        cas++;
        ll ans = rec1(0, 0);
        pf("%lld\n", ans);
    }

    return 0;
}




























