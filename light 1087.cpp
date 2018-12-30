#include <bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb            push_back
#define m_p           make_pair
#define ff            first
#define ss            second
#define sc1(a)        scanf("%d",&a)
#define sc2(a,b)      scanf("%d%d",&a,&b)
#define scl1(a)       scanf("%lld",&a)
#define scl2(a,b)     scanf("%lld %lld",&a,&b)
#define pnt(a)        printf("%d\n",a)
#define pntl(a)       printf("%lld\n",a)
#define all(a)        a.begin(),a.end()
#define rep(it,a,b)   for(ll it = a;it < b;it++)
#define pii           pair<int,int>
#define pll           pair<long,long>
#define hi            puts("Hi..!")
#define MOD           1000000007LL
#define MAX           200009
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

struct info {
ll prop, sum;
} tree[MAX * 3];

ll arr[MAX];
ll brr[MAX];
ll n,q;

//Initialization...........................................................
void init(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node].sum = brr[b];
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
//Update.....................
ll query(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

//Update.....................

void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    ll Left = node * 2;
    ll Right = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;

}

ll solve(ll x)
{
    ll ret = 1000000007;
    ll lo = 1;
    ll up = 200000;
    ll mid = (lo + up)/2;
    while(lo <= up){
        mid = (lo + up)/2;
        ll keep = query(1,1,200000,mid,mid);
        if(keep < x){
            lo = mid+1;
        }
        else{
            if(keep == x) ret = mid;
            up = mid-1;
        }
    }
    return ret;
}

int main() {
   cin.tie(0);
   //freopen("0utput.txt","w",stdout);
   int T;int cs = 0;
   sc1(T);
   while(T--){
   memset(tree,0,sizeof tree);
   scl2(n,q);
   rep(i,1,200005) brr[i] = i,arr[i] = -1;
   init(1,1,200000);

   rep(i,1,n+1){
   scl1(arr[i]);
   }
   ll nxt = n+1;
   printf("Case %d:\n",++cs);
   while(q--){
    char c;ll x;
    cin >> c >> x;
    if(c == 'c'){
        ll pos = solve(x);
        //cout << pos <<" " << arr[pos] << endl;
        if(pos == 1000000007){
            puts("none");
        }
        else if(arr[pos] == -1){
            puts("none");
        }
        else{
            pntl(arr[pos]);
            update(1,1,200000,pos,200000,(-1));
            //update......................
        }
    }
    else{
        arr[nxt++] = x;
    }
   }

   }
   return 0;
}
/*

*/

