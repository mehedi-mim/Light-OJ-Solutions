
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
#define MAX           4294967297
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
map<ll,ll> mp1;
ll mark[65538];
void f1(ll n)
{
  for(ll i = 3;i*i<= n;i += 2){
    if(!mark[i]){
      for(ll j = i*i;j <= n;j+= i){
        mark[j] = 1;
      }
    }
  }
  prime.pb(2);
  for(ll i = 3;i <= n;i+= 2) {
    if(!mark[i]) prime.pb(i);
  }
  return;
}
ll f2(ll n)
{
   ll ret = 0;
   ll k = 0;
   for(ll i = 0;i < prime.size() && prime[i] <= n;i++){
      ll keep = prime[i];
      if(n%keep == 0){
        ll cnt = 0;
        while(n%keep == 0){
          cnt++;
          n /= keep;
        }
        if(k) ret = gcd(ret,cnt);
        else ret = cnt,k++;
      }
   }
   if(n > 2) return 1;
   else return ret;
}

int main() {
      //freopen("0utput.txt","w",stdout);
      ll T;
      f1(65537);
      scl1(T);ll cs = 0;
      while(T--){
        ll ans = 0;
        ll n;scl1(n);
        ll keep = abs(n);
        ans = f2(keep);
        if(n < 0){
          while(ans%2 == 0){
            ans /= 2;
          }
        }
        printf("Case %lld: %lld\n",++cs,ans);
      }
}
/*
*/

