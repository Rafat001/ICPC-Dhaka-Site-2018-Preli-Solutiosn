/*input

*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define mx 100005
#define fs first
#define sc second
#define pb push_back
#define mkp make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { Long a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})
#define DB if(0)
#define deb(x) cout << #x " is " << x << endl
#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

using namespace std;

typedef long long Long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<string> vs;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    x*=sgn; return ~c;
}


ll fun(ll n)
{
    ll mult = 1;
    ll ret = 0;
    if(n == 0) return 0;

    while(mult <= n){
        ll nw = n/mult;
        ll sq = sqrt(nw);
        ret += (sq + 1)/2;
        mult *= 2ll;
    }
    return ret;
}
int main()
{
	int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        printf("Case %d: %lld\n", tst++, fun(r) - fun(l-1));
    }
	return 0;
}
