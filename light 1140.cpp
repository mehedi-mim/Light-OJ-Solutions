#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define ld            long double
#define pb            push_back
#define m_p            make_pair
#define ff            first
#define ss            second
#define sc1(a)        scanf("%d",&a)
#define sc2(a,b)      scanf("%d%d",&a,&b)
#define scl1(a)       scanf("%lld",&a)
#define scl2(a,b)     scanf("%lld %lld",&a,&b)
#define pnt(a)        printf("%d\n",a)
#define pntl(a)       printf("%lld\n",a)
#define all(a)        a.begin(),a.end()
#define rep(it,a,b)   for(ll it = a;it < b;it++)
#define pii           pair<int,int>
#define pll           pair<long,long>
#define hi            puts("Hi..!")
#define MOD           1000000007LL
#define MAX           1000009
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
template <class T> inline T power(T p,T e){ll ret=1;for(;e>0;e>>=1){if(e&1)ret=(ret*p);p=(p*p);}return(T)ret;}
template <class T> inline T bigmod(T p,T e,T M){ll ret=1;for(;e>0;e>>=1){if(e&1)ret=(ret*p)%M;p=(p*p)%M;}return(T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}

int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}

//solution...............
ll solve(ll n)
{
    ll ret = 0;
    ll p = 1;
    string s = "";
    ll d = 0;

    ret += (n/10);
    s = ('0' + n%10);
    n /= 10;

    while(n >= 10){
        d = n%10;
        char c = ('0' + d);
        s = ( c + s);

        ll keep = n/10;
        keep--;
        ll mul = power((ll)10,(ll)p);
        ret += keep*mul;

        if(d){
            ret += mul;
        }
        else{
            ll temp = toLlint(s);
            ret += temp+1;
        }
        p++;
        n /= 10;
    }
    return ret;
}
int main() {
   int T;
   sc1(T);int cs = 0;
   while(T--){
    ll ans = 0;
    ll a,b;scl2(a,b);
    ll lft = 1,rgt = 1;

    if(a >= 10)
    lft += solve(a);
    if(b >= 10)
    rgt += solve(b);
    ll temp = 0;
    if(!a) temp++;
    while(a){
        if(a%10 == 0) temp++;
        a /=10;
    }
    ans = rgt - lft + temp;
    printf("Case %d: %lld\n",++cs,ans);
   }
   return 0;
}
/*

*/


