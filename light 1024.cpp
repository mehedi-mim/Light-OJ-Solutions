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
string Bigmul(string lcm,ll mul)
{
   ll len = lcm.length();
   ll carry = 0;
   REP(i,0,len){
   carry += (lcm[i] - 48) * mul;
   lcm[i] = (carry%10 + 48);
   carry /= 10;
   }
   while(carry){
    lcm += carry%10 + 48;
    carry /= 10;
   }
   return lcm;
}
vector<ll> prime;
bool mark[10009];
ll fact[10009];

void lseiv(int n)
{
    for(int i = 3;i*i <= n;i+= 2){
      if(!mark[i])
        for(int j = i*i;j <= n;j += i) mark[j] = 1;
    }
    prime.pb(2);
    for(int i = 3;i <= n;i+= 2) if(!mark[i]) prime.pb(i);
}

int main() {
      ll T,cs = 0;
      lseiv(10000);
      scl1(T);
      while(T--){
        memset(fact,0,sizeof fact);
        ll n;scl1(n);
        vector<ll> v;
        vector<ll> factor;
        REP(i,0,n) {
        ll x;scl1(x);v.pb(x);
        }
        REP(i,0,v.size()){
          ll keep = v[i];
          REP(j,0,prime.size()){
          ll mul = prime[j];
          if(prime[j] > keep) break;
            while(keep%prime[j] == 0){
              mul *= prime[j];
              keep /= prime[j];
            }
            mul /= prime[j];
            fact[prime[j]] = max(fact[prime[j]],mul);
          }
          if(keep > 2){
            fact[keep] = max(fact[keep],1LL);
          }
        }
        string lcm = "1";
        REP(i,0,prime.size()){
         ll keep = fact[prime[i]];
         if(keep){
          lcm = Bigmul(lcm,keep);
         }
        }
        reverse(lcm.begin(),lcm.end());
        printf("Case %lld: ",++cs);
        cout << lcm << endl;
      }
}
