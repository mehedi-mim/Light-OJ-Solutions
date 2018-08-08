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
bool mark[80000];
vector<int> prime;

void segseive (int n)
{
    for(int i = 3;i*i <= n;i+= 2){
      if(!mark[i])
        for(int j = i*i;j <= n;j += i) mark[j] = 1;
    }
    prime.pb(2);
    for(int i = 3;i <= n;i+= 2) if(!mark[i]) prime.pb(i);
}
int arr[100009];
int main() {
  int T;
  sc1(T);int cs = 0;
  segseive(70000);
  //REP(i,0,100) cout << prime[i] <<" ";
  while(T--){
    memset(arr,0,sizeof arr);
    ll ans = 0;
    ll a,b;
    scl2(a,b);
    if(a == 1) a++;
    REP(i,0,prime.size()){
     if(prime[i] > b) break;
     ll start = (a/prime[i]) * (prime[i]);
     if(prime[i] >= a) start = prime[i]+ prime[i];
     else if(start < a) start += prime[i];
     for(ll j = start;j <= b;j += prime[i]){
      //cout << j << endl;
      arr[j-a] = 1;
     }
//     ll start = prime[i]*prime[i];
//     if(start < a){
//      ll keep = a/prime[i];
//      start = prime[i]*keep;
//     }
//     if(!arr[start - a])
//      for(ll j = start; j <= b;j += prime[i]){
//        cout <<j <<" " << j-a << endl;
//        arr[j - a] = 1;
//      }
    }
    for(ll i = a;i <= b;i++) if(!arr[i-a])ans++;
    printf("Case %d: %lld\n",++cs,ans);
  }
}
/*
*/

