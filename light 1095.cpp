#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define ld            long double
#define pb            push_back
#define m_p           make_pair
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
ll nCr[1009][1009];
ll fact[10000];
void factorial()
{
    fact[0] = 1;
    for(ll i = 1;i <= 1000;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}
void calnCr()
{
    nCr[1][1] = 1;
    nCr[1][0] = 1;
    for(int i = 2;i <= 1000;i++){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        for(int j = 1;j < i;j++){
            nCr[i][j] = nCr[i-1][j-1] % MOD + nCr[i-1][j] % MOD;
            nCr[i][j] = nCr[i][j] % MOD;
        }
    }
}
ll solve(ll n,ll k)
{
    ll ans = fact[n];
    for(ll i = 1;i <= k;i++){
        ans -= (((i&1)?1:-1)*nCr[k][i] * fact[n-i]) % MOD;
        ans = (ans + MOD) % MOD;
    }
    return ans;
}
int main() {
   ll T;scl1(T);int cs = 0;
   calnCr();
   factorial();
   while(T--){
    ll ans = 0;
    ll n,m,k;scl2(n,m);scl1(k);
    ans = (nCr[m][k] * solve(n-k,m-k)) % MOD;
    printf("Case %d: %lld\n",++cs,ans);
   }
   return 0;
}
/*

*/


