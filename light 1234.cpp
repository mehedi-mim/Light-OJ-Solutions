
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
#define scl1(a)       scanf("%I64d",&a)
#define scl2(a,b)     scanf("%I64d %I64d",&a,&b)
#define pnt(a)        printf("%d\n",a)
#define pntl(a)       printf("%I64d\n",a)
#define all(a)        a.begin(),a.end()
#define REP(it,a,b)   for(ll it = a;it < b;it++)
#define pii           pair<int,int>
#define pll           pair<long,long>
#define hi            puts("Hi..!")
#define MOD           1000000007
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
double Harmonic[100009];
int main() {
      //freopen("0utput.txt","w",stdout);
      ll T,cs = 0;
      scl1(T);
      int pos = 1;
      ll i,j;
      for( i = 1;i <= 100000000;i++){
        double cal = 0.0;
        for( j = i;j <= (i+1000-1);j++){
          cal += (double)((double)1/(double)j);
        }
      Harmonic[pos] = Harmonic[pos-1] + cal;
      i = j-1;
      pos++;
      }
//      printf("%.10lf\n",1/(double)1001);
//      double keep = Harmonic[1];
//      keep += 1 /(double)1001;
//      printf("%.10lf\n",keep);

      while(T--){
        double ans = 0;
        ll n;scl1(n);
        ll keep = (n/1000);
        ll rem = (n%1000);
        ans += Harmonic[keep];
        ll start = (1000*keep);
        for(ll i = start+1;i <= start+rem;i++){
          ans += (double)(1/(double)i);
        }
        printf("Case %lld: %.10lf\n",++cs,ans);
      }
}
/*
*/
