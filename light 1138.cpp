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
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}
int zeros(int n)
{
    int ret = 0;
    for(int i = 5; i <= n;i *= 5){
      ret += (n/i);
    }
    return ret;
}
int main() {
    int T;
    sc1(T);int cs = 0;
    while(T--){
      bool paisi = false;
      int ans = 0;
      int n = 100000000*5;
      int Q;sc1(Q);
       int lo = 5,up = n;
       while(lo <= up){
        int mid = (lo + up)/2;
        int keep = zeros(mid);
        //cout << lo <<" " << mid <<" " << up << " " << keep << endl;
        if(keep == Q){
          ans = mid;
          paisi = true;
          up = mid-1;
        }
        else if(keep > Q) up = mid-1;
        else lo = mid+1;
       }
      printf("Case %d: ",++cs);
      if(paisi) printf("%d\n",ans);
      else puts("impossible");
    }

}
/*
*/

