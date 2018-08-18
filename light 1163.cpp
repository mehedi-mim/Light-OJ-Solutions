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
int arr[1000000];
int main() {
      //freopen("0utput.txt","w",stdout);
      int T,cs = 0;
      scl1(T);
      while(T--){
        ll n;
        scl1(n);
        printf("Case %d: ",++cs);
        int cnt = 0;
        for(ll i = 9;i >= 0;i--){
          ll keep = n-i;
          if(keep%9 == 0){
            if(cnt)printf(" ");
            ll ans = n + keep/9;
            printf("%lld",ans);
            cnt++;
          }
        }
        puts("");

      }

      return 0;
}
/*
*/
