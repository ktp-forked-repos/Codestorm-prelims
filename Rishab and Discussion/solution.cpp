/******************************************
*    AUTHOR:         BHUVNESH JAIN        *
*    INSTITUITION:   BITS PILANI, PILANI  *
******************************************/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL; 
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const int MAX   = 100005;
const int LIMIT = 263005;
const int INF   = 1000000001;
const LL  INFL  = 1000000000000000001LL;
const LL  MOD   = 1000000007LL;
const double EPS = 1e-10;
const double PI = acos(-1.0);

#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PAUSE_EXE       assert(false)
#define inchar          getchar//_unlocked
#define outchar(x)      putchar(x)//_unlocked(x)
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define loopr(c,i)      for(typeof(c.end()) i = c.end(); i != c.begin(); )
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())

double tick(){static clock_t oldt;clock_t newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt = newt;return diff;}
template<typename T> void inPos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outPos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T, typename S>T expo(T e, S n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template<typename T> T InverseEuler(T a, T m){return (a==1?1:power(a,m-2,m));}
template<typename T> T gcd(T a, T b){return __gcd(a,b);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
 
vector <int> degrees, temp;
 
vector<int>::iterator query;
 
LL pre1[MAX], pre2[MAX];
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    int t, n, x, pos;
    LL other;
    inPos(t);
    assert(t<=10);
    bool possible;
    LL sum, check;
    while(t--) {
        inPos(n);
        assert(n<=100000);
        degrees.clear();
        temp.clear();
        sum = 0;
        possible = true;
        REP(i, n) {
            inPos(x);
            assert(x >= 0);
            assert(x <= 1000000);
            sum += 1LL*x;
            degrees.pb(x);
            if (x>=n) {
                possible = false;
            }
        }
        if (sum%2==1 || (!possible)) {
            printf("Rishab is a liar\n");
            continue;
        }
        sort(allr(degrees));
        CREP(i, n) {
            temp.pb(degrees[i]);
        }
        pre1[0] = degrees[0];
        MYREP(i, 1, n-1) {
            pre1[i] = pre1[i-1] + degrees[i];
        }
        pre2[0] = temp[0];
        MYREP(i, 1, n-1) {
            pre2[i] = pre2[i-1] + temp[i];
        }
        REP(i, n) {
            check = 1LL*i*(i+1);
            query = lower_bound(all(temp), i+1);
            pos = query - temp.begin();
            if ((*query) > (i+1)) {
                pos--;
            }
            pos = min(pos, n-i-2);
            if (pos<0) {
                other = 0;
            }
            else {
                other = pre2[pos];
            }
            if (pos==-1) {
                other += 1LL*(i+1)*(n-i-1);
            }
            else {
                other += 1LL*(i+1)*(n-i-pos-2);
            }
            check += other;
            if (pre1[i]<=check) {
                continue;
            }
            else {
                possible = false;
                break;
            }
        }
        if (possible) {
            printf("Rishab is not a liar\n");
        }
        else {
            printf("Rishab is a liar\n");
        }
    }
    cerr<<tick();
    return 0;
} 