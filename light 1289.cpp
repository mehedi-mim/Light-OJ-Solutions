#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb            push_back
#define m_p            make_pair
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
#define MOD           4294967296LL
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
int arr[100000000];
int pos = 0;
vector<int> prime;
int fact[15000];
bool mark[10009];
ll lcm = 1;
// prime generation section
void seive()
{
   for(int i = 3;i*i <= 10009;i += 2){
    if(!mark[i]){
      for(int j = i*i; j <= 10005;j += i) mark[j] = 1;
    }
   }
   prime.pb(2);
   for(int i = 3;i <= 10005; i+= 2) if(!mark[i]) prime.pb(i);
}

// lcm calculation
void f1(int n)
{
   for(int i = 0;i < prime.size() && prime[i] <= n;i++){
         if(n%prime[i] == 0){
              int cnt = 1;
              while(n%prime[i] == 0 && n){
                cnt *= prime[i];
                n /= prime[i];
              }
              if(fact[prime[i]] < cnt){
                if(fact[prime[i]])
                lcm /= fact[prime[i]];
                lcm = (lcm%MOD * cnt%MOD) % MOD;
                fact[prime[i]] = cnt;
              }
         }
   }
   if(n > 2) lcm = (lcm * n) % MOD;
}

int main() {
     int T,cs = 0;
     sc1(T);
     seive();
     for(int i = 2;i <= 100000;i++){
      f1(i);
      arr[i-1] = lcm;
     }
     while(T--){
      //print section
      int n;sc1(n);
      printf("Case %d: %d\n",++cs,arr[n-1]);
     }
}
/*
*/

