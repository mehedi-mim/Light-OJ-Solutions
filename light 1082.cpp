#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define ld            long double
#define pb            push_back
#define m_p            make_pair
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
template <class T> inline T power(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}
int tree[400000];
int arr[100009];
void init(int node,int b,int e)
{
     if(b == e) {
      tree[node] = arr[b];
      return;
     }
     int Left = node*2;
     int Right = node*2+1;
     int mid = (b+e)/2;
     init(Left,b,mid);
     init(Right,mid+1,e);
     tree[node] = min(tree[Left],tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
    if(i > e || j < b) return 1000000;
    if(b >= i && e <= j) return tree[node];
     int Left = node*2;
     int Right = node*2+1;
     int mid = (b+e)/2;
     int p1 = query(Left,b,mid,i,j);
     int p2 = query(Right,mid+1,e,i,j);
     return min(p1,p2);
}
int main() {
   int T;sc1(T);int cs = 0;
   while(T--){
    int ans = 0;
    int n,q;sc2(n,q);
    REP(i,1,n+1){
    sc1(arr[i]);
    }
    init(1,1,n);
    printf("Case %d:\n",++cs);
    while(q--){
      int x,y;sc2(x,y);
      ans = query(1,1,n,x,y);
      printf("%d\n",ans);
    }
   }
   return 0;
}
/*
*/
