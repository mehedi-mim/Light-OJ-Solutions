#include <bits/stdc++.h>
using namespace std;
#define ll            long long int
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
#define MOD           1000000007
#define MAX           1000009
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}

int main() {
    //freopen("0utput.txt","w",stdout);
     ll T;ll cs = 0LL;
     scl1(T);
     while(T--){
      ll x1,y1,x2,y2;
      scl2(x1,y1);scl2(x2,y2);
      ll x,y;
      x = fabs(x2 - x1);
      y = fabs(y2 - y1);
      //cout << x <<" " << y << endl;
      ll ans = __gcd(x,y) + 1LL;
      printf("Case %lld: %lld\n",++cs,ans);
     }
}
/*
*/

