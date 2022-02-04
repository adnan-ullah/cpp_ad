//Author: Adnan
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> v_str;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define mx 5999999

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define fin(n) cin>>n
#define fin_2(a,b) cin>>a>>b
#define fin_3(a,b,c) cin>>a>>b>>c
#define COUNT(v,n) count(v.begin(), v.end(), n)
#define show(a) cout<<a<<endl
#define SEGMENT_Parameters ll node, ll b, ll e , ll low, ll high

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll d(char c)
{
    return c-'0';
}

struct node
{
    ll level;
    ll values;
};


vector<node> tree(3*mx);
vi v ;

vector<int> primes(mx, 1);

void seive()
{

    primes[0] = 0;
    primes[1] = 0;
    for(int i = 2; i*i <= mx ; i++)
    {
        if(primes[i])
            for(int j = i*i ; j<=mx ; j+=i)
            {

                primes[j] = 0;
            }
    }

}

void construct(ll node, ll b, ll e)
{
    if(b==e)
    {

        tree[node].values = primes[v[b]];

        tree[node].level = 1;
        return;

    }
    ll mid = (b+e)/2;
    ll left = node*2;
    ll right = node*2+1;

    construct(left, b, mid );

    construct(right, mid+1, e);

    tree[node].values = tree[left].values + tree[right].values;

    return;
}

ll range_quory(ll node, ll b, ll e, ll low, ll high)
{
    if(low>e || high < b)
        return 0;
    if(b>=low && high >= e)
    {
        return tree[node].values;
    }
    ll mid = (b+e)/2;
    ll left = node*2;
    ll right = node*2+1;

    ll p1 = range_quory(left, b, mid, low, high);

    ll p2 = range_quory(right, mid+1, e,low, high);



    return p1+p2;
}

void updDateNode(ll node, ll b, ll e, ll ind, ll value )
{
    if(b>e)
        return;
    if(b==e)
    {
        tree[node].values = primes[value];
        return;
    }

    ll mid = (b+e)/2;
    ll left = node*2;
    ll right = node*2+1;

    if(ind>=b && ind<=mid)
        updDateNode(left, b, mid,  ind,  value );
    else
        updDateNode(right, mid+1, e,  ind,  value);

    tree[node].values = tree[left].values + tree[right].values;


}

void solve()
{
    ll n;
    cin>>n;
    inp_vi(v,n);
    construct(1,0, v.size()-1);


    ll q;
    cin>>q;

    TC(q)
    {
        ll x,y,o;
        cin>>o>>x>>y;

        if(o==1)
        {
            --x;
            --y;
            show(range_quory(1,0,v.size()-1,x,y));

        }
        else
        {
            --x;
            updDateNode(1,0, v.size()-1,x, y );
        }
    }


}
int main()
{

    seive();

    solve();


    return 0;
}
