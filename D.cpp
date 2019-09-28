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
inline ll mulmod(ll base, ll mul, ll modulo)
{
    ll ret = 0;
    while(mul > 0){
        if(mul%2==1) ret = (ret + base) % modulo;
        base = (base + base) % modulo;
        mul /= 2;
    }
    return (ret + modulo) % modulo;
}
inline ll bigmod(ll a, ll p, ll m)
{
    ll ret = 1;
    while(p)
    {
        if(p & 1) ret = mulmod(ret, a, m);
        a = mulmod(a, a, m);
        p /= 2;
    }
    return ret;
}

inline bool miller(ll p, int iter = 20)
{
    if(p==3 || p==2 || p==5) return true;
    if(p%2==0) return false;
    if(p < 3) return false;
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

    for(int i = 0; i<iter; i++)
    {
        ll a = (rnd()) % (p-4) + 2;
        ll s = p-1;
        while(s % 2 == 0) s/=2;
        ll mod = bigmod(a, s, p);
        if(mod==1 || mod==p-1) continue;
        bool flag = 0;
        s *= 2;
        while(s != p-1)
        {
            mod = mulmod(mod, mod, p);
            if(mod == p-1){
                flag = 1;
                break;
            }
            s *= 2;
        }
        if(flag==0) return 0;
    }
    return 1;
}

inline bool isvali(ll n)
{
    if(n < 10){
        return (n==2 || n==3 || n==5 || n==7);
    }
    while(n){
        if(isvali(n%10) == false) return false;
        n /= 10;
    }
    return true;
}
inline ll next(ll n)
{
    if(n < 10){
        if(n > 7) return 7;
        if(n > 5) return 5;
        if(n > 3) return 3;
        if(n > 2) return 2;
        return -1;
    }
    string st;
    while(n)
    {
        st += char(48 + n%10);
        n /= 10;
    }
//    cout << st << endl;
    int len = st.length();
    int i;
    for(i = len-1; i>=0; i--)
    {
        if(isvali(st[i]-'0') == false) break;
    }
    if(i == -1){
        int f = 0;
        for(int j = 0; j<len; j++){
            if(st[j] != '2'){
                st[j] = next(st[j]-'0') + '0';

                for(int k = j-1; k>=0; k--)
                    st[k] = '7';
                f = 1;
                break;
            }
        }
        if(!f){
            st = string(st.length()-1, '7');
        }
    } else{
        int f = 0;
        for(int j = i; j<len; j++)
        {
            if(next(st[j]-'0') != -1){
                st[j] = next(st[j]-'0') + '0';
                f = 1;
               for(int k = j-1; k>=0; k--)
                    st[k] = '7';
                break;
            }
        }
        if(!f) st = string(st.length()-1, '7');
    }
    len = st.length();
    reverse(st.begin(), st.end());
    ll num = 0;
    for(int i = 0; i<len; i++)
        num = num * 10ll + st[i] - '0';
    return num;
}

int main()
{


    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        while(1){
            if(isvali(n) && miller(n)){
                break;
            } else{
                n = next(n);
            }
        }
        printf("Case %d: %lld\n", tst++, n);
    }
    return 0;
}
