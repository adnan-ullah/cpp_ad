
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
#define REP(i, n) FOR(i, 0, n)
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

vi tree(100);
vi v;
void seg(ll node,ll b, ll e)
{

}

ll query (ll node, ll b, ll e, ll low, ll high)
{


}

char getting(char ch)
{
}

void solve()
{

        string s;
        cin>>s;

        stack<char> stc;

        for(auto i:s)
        {
            if(!stc.empty())
            {
                char tp = stc.top();
                if(tp==i)
                {
                    continue;
                }
                else
                    stc.push(i);
            }
            else
            {
                stc.push(i);
            }
        }

        string str = "";
        while(!stc.empty())
        {

            str+=stc.top();
            stc.pop();
        }
        reverse(ALL(str));

        cout<<str<<endl;

}
int main()
{

    solve();

    return 0;
}
