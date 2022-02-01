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

#define mx 100001

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
/*
sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b) {
        if(a.first != b.first) return (a.first < b.first);
        return (a.second > b.second);
*/
inline void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
inline void inp_vi(vi& v, ll n)
{
    TC(n)
    {
        ll num;
        cin>>num;
        v.pb(num);
    }
}
inline void inp_v_str(v_str& v, ll n)
{
    TC(n)
    {
        string num;
        cin>>num;
        v.pb(num);
    }
}

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs)
{
    return lhs.size() == rhs.size()
           && std::equal(lhs.begin(), lhs.end(),
                         rhs.begin());
}


inline string IntToString(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline ll StringToInt(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

ll d(char c)
{
    return c-'0';
}

vi v = {1,2,3,4,5,6,7,8,9,10}; // vec
vi TREE(3*INT_MAX); // segTree

void construct(ll node, ll b, ll e)
{

    if(b==e)
    {
        TREE[node] = v[b];
        return;
    }


    ll left = node*2+1;
    ll right = node*2 +2;

    ll mid = (b+e)/2;

    construct(left, b, mid);
    construct(right, mid+1, e);

    TREE[node] = max(TREE[left], TREE[right]);
}

ll findMax(SEGMENT_Parameters)
{

    if(low> e || high < b)
    {
        return INT_MIN;
    }

    if(low<=b && high >= e)
    {
        return TREE[node];
    }


    ll left = node*2+1;
    ll right = node*2 +2;

    ll mid = (b+e)/2;

    ll p1 = findMax(left, b, mid, low, high);
    ll p2= findMax(right, mid+1, e, low, high);

    return max(p1,p2);

}


void updateRange(SEGMENT_Parameters, ll inc)
{
    if(low > e || high < b)
    {
        return;
    }

    if(b==e)
    {
        TREE[node] =  inc;
        return;
    }

    ll left = node*2+1;
    ll right = node*2 +2;

    ll mid = (b+e)/2;

    updateRange(left, b, mid, low, high, inc);
    updateRange(right, mid+1, e, low, high, inc);

    TREE[node] = max(TREE[left], TREE[right]);



}


void solve()
{
    construct(0,0, v.size()-1);
    updateRange(0,0, v.size()-1, 4,9, 9);
    cout<<findMax( 0, 0, v.size()-1,9,10);
    rep(i,v.size())
    {
        cout<<TREE[i]<<endl;
    }

}
int main()
{

    solve();


    return 0;
}
