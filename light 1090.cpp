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
int ptwo = 0;int pfive = 0;
void ppp(int n,int q)
{
     if(n%2 == 0){
      while(n%2 == 0){
        ptwo++;
        n /= 2;
      }
     }
     if(n%5 == 0){
      while(n%5 == 0){
        pfive++;
        n /= 5;
      }
     }
      ptwo *= q;
      pfive *= q;
      //cout << ptwo <<" " << pfive << endl;

}
void facto(int n)
{
    for(int i = 2;i <= n;i *= 2){
      ptwo += (n/i);
    }

    for(int i = 5;i <= n;i *= 5){
      pfive += (n/i);
    }

}
void sub(int r)
{
  for(int i = 2;i <= r;i *= 2) ptwo -= (r/i);
  for(int i = 5;i <= r;i *= 5) pfive -= (r/i);
}
int main() {
  int T;
  sc1(T);int cs = 0;
  while(T--){
    ptwo = pfive = 0;
    int ans = 0;
    int n,r,p,q;
    sc2(n,r);sc2(p,q);
    ppp(p,q);
    facto(n);
    sub(r);
    sub(n-r);
    ans = min(ptwo,pfive);
    printf("Case %d: %d\n",++cs,ans);
  }
}
/*
*/

