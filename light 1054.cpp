#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb            push_back
#define mp            make_pair
#define R             return 0
#define ff            first
#define ss            second
#define sc1(a)        scanf("%d",&a)
#define sc2(a,b)      scanf("%d%d",&a,&b)
#define scl1(a)       scanf("%lld",&a)
#define scl2(a,b)     scanf("%lld %lld",&a,&b)
#define pnt(a)        printf("%d\n",a)
#define pntl(a)       printf("%lld\n",a)
#define all(a)        a.begin(),a.end()
#define REP(it,a,b)   for(ll it = a;it < b;it++)
#define pii           pair<int,int>
#define pll           pair<long,long>
#define hi            puts("Hi..!")
#define MOD           1000000007LL
#define MAX           1000009
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}
vector<ll> prime;
bool mark[500009];
void seive(ll n)
{
    prime.pb(2);
    for(ll i = 3;i*i <= n;i += 2){
      if(!mark[i]){
        for(ll j = i*i ;j <= n; j += i) mark[j] = 1;
      }
    }
    for(ll i = 3;i <= n;i += 2) {
      if(!mark[i]) prime.pb(i);
    }
}

int main() {
      seive(400000LL);
     // cout << prime[prime.size()-1] << endl;
      ll T;
      scl1(T);ll cs = 0;
      while(T--){
        ll ans = 1;
          ll n,m;
          scl2(n,m);
          REP(i,0,prime.size()){
          if(prime[i] > n) break;
          if(n%prime[i] == 0){
            ll cnt = 0;
            while(n%prime[i] == 0){
              cnt++;
              n /= prime[i];
            }
          cnt *= m;
          ll uno = (bigmod(prime[i],cnt+1,MOD) - 1LL) % MOD;
          ll keep = modinverse(prime[i]-1,MOD) % MOD;
          keep = (keep * uno)% MOD;
          ans = (ans%MOD * keep) % MOD;
          }
          //cout << ans << endl;
          }
          ll keep = modinverse(n-1LL,MOD) % MOD;
          if(n > 2){

            ll uno = (bigmod(n,m+1,MOD)-1LL) % MOD;
            keep = (keep*uno) % MOD;
            ans = (ans%MOD * keep) % MOD;
            if(n == MOD) ans = 1LL;
          }
        printf("Case %lld: %lld\n",++cs,ans);
      }
}
/*
*/
