#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define ld            long double
#define pb            push_back
#define m_p           make_pair
#define ff            first
#define ss            second
#define sc1(a)        scanf("%d",&a)
#define sc2(a,b)      scanf("%d%d",&a,&b)
#define scl1(a)       scanf("%I64d",&a)
#define scl2(a,b)     scanf("%I64d %I64d",&a,&b)
#define pnt(a)        printf("%d\n",a)
#define pntl(a)       printf("%I64d\n",a)
#define all(a)        a.begin(),a.end()
#define rep(it,a,b)   for(ll it = a;it < b;it++)
#define pii           pair<int,int>
#define pll           pair<long,long>
#define hi            puts("Hi..!")
#define MOD           1000000007LL
#define MAX           1000009
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
template <class T> inline T power(T p,T e){ll ret=1;for(;e>0;e>>=1){if(e&1)ret=(ret*p);p=(p*p);}return(T)ret;}
template <class T> inline T bigmod(T p,T e,T M){ll ret=1;for(;e>0;e>>=1){if(e&1)ret=(ret*p)%M;p=(p*p)%M;}return(T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}

//solution...............
double pro[200];
int arr[200];
int main() {
    int T;int cs = 0;
    sc1(T);
    while(T--){
        double exp = 0;
        memset(pro,0,sizeof pro);
        int n;
        sc1(n);
        rep(i,1,n+1){
        sc1(arr[i]);
        }
        pro[1] = 1;
        exp = (arr[1]);
        rep(i,2,n+1){
          rep(k,1,7){
          int j = (i-k);
          if(j < 1) break;
          int cnt = min(6,n-j);
          pro[i] = pro[i] + (pro[j] * (double(1)/double(cnt)));
          }
        exp += pro[i] * (double)arr[i];
        }
        printf("Case %d: %.10lf\n",++cs,exp);
    }
   return 0;
}
/*

*/

