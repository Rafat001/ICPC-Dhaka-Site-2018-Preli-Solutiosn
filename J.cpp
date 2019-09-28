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

vector<int> edge[100005];
vector<pair<int, int> > ans;
void dfs(int u, int p, int lev = 0)
{
    if(lev){
        if(lev&1) ans.push_back({u, p});
        else ans.push_back({p, u});
    }
    for(int v : edge[u])
    {
        if(v != p){
            dfs(v, u, lev+1);
        }
    }
}
int main()
{
	int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++) edge[i].clear();
        ans.clear();
        for(int i = 1; i<n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        printf("Case %d:\n", tst++);
        dfs(1, -1);
        for(int i = 0; i<n-1; i++)
            printf("%d %d\n", ans[i].first, ans[i].second);

    }
	return 0;
}
