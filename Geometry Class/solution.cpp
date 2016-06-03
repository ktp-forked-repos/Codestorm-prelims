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

const int MAX   = 1000002;
const int LIMIT = 263005;
const int INF   = 1000000001;
const LL  INFL  = 1000000000000000001LL;
const int MOD   = 123456; 
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

char s[12];

int phi[MAX];

LL res[MAX];

void generate_etf() {
    phi[1] = 1;
    for(int i=2; i<MAX; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for(int j=(i<<1); j<MAX; j+=i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

void pre() {
    // result contains summation phi[x] for 1<=x<=i
    res[1] = phi[1];
    for(int i=2; i<MAX; ++i) {
        res[i] = res[i-1] + phi[i];
    }
}
 
void farey(int N, int p) {
    int x1=0, y1=1, x2=1, y2=N;
    int x=1, y=N;
    if (p==1) {
        printf("%d/%d\n",x1,y1);
        return ;
    } 
    else if (p==2) {
        printf("%d/%d\n",x2,y2);
        return ;
    }
    int c = 2;
    // printf("%d/%d, %d/%d",x1,y1,x2,y2);
    while (y!=1.0) {
        x=((y1+N)/(y2))*x2-x1;
        y=((y1+N)/(y2))*y2-y1;
        c++;
        if (c==p) {
            printf("%d/%d\n",x,y);
            return ;
        }
        x1=x2,x2=x,y1=y2,y2=y;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    generate_etf();
    pre();
    int q, a, b;
    scanf("%d", &q);
    assert(q<=2000);
    while (q--) {
        scanf("%d", &a);
        assert(a>=1 && a<=1000000);
        scanf("%s", s);
        if (strcmp(s, "number") == 0) {
            printf("%lld\n", res[a] + 1);
        }
        else if (strcmp(s, "find") == 0) {
            scanf("%d", &b);
            assert(b <= (res[a]+1));
            farey(a, b);
        }
        else {
            PAUSE_EXE;
        }
    }
    cerr<<tick();
    return 0;
}