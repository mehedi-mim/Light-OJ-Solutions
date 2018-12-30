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
#define MAX           400000
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

string s;
struct info
{
int sum,prop;
}tree[MAX];
//initialization.....................
void update(int node,int b,int e,int i,int j)
{
   if(i > e || j < b) return;
   if(b >= i && e <= j){
    tree[node].sum += (e-b+1);
    tree[node].prop++;
    return;
   }
   int Left = node*2;
   int Right = node*2 + 1;
   int mid = (b + e)/2;
   update(Left,b,mid,i,j);
   update(Right,mid+1,e,i,j);
   tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j){
      return tree[node].sum + carry * (e - b + 1);
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    int p1 = query(Left,b,mid,i,j,carry+tree[node].prop);
    int p2 = query(Right,mid+1,e,i,j,carry+tree[node].prop);
    return p1 + p2;
}

int main() {
    //freopen("0utput.txt","w",stdout);
    int T;sc1(T);int cs = 0;
    while(T--){
    cin.tie(0);
    memset(tree,0,sizeof tree);
    int ans = 0;
    cin >> s;
    int q;sc1(q);
    int len = s.length();
    s = "0" + s;
    //query.............................

   printf("Case %d:\n",++cs);
    while(q--){
    char qq;
    //cin.tie(0);
    cin >> qq;
    if(qq == 'I'){
      int x,y;sc2(x,y);
      update(1,1,len,x,y);
    }
    else{
      int x;sc1(x);
      int keep = s[x] - 48;
      int res = query(1,1,len,x,x,0);
      if(res&1){
        if(keep) puts("0");
        else puts("1");
      }
      else printf("%d\n",keep);
    }
    }
    //end........................................
   }
   return 0;
}
/*
*/
