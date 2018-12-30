#include <bits/stdc++.h>
using namespace std;
#define ll            long long
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
int cum[100000];
int main() {

    int T;int cs = 0;
    sc1(T);
    while(T--){
        printf("Case %d:\n",++cs);
        memset(cum,0,sizeof cum);
        map<int,int> mp,visit;
        int n,q;
        sc2(n,q);
        vector<pii> v;
        vector<int> num;
        rep(i,0,n){
         int x,y;
         sc2(x,y);
         v.pb(m_p(x,y));
         if(!visit[x]) num.pb(x) ,visit[x]++;
         if(!visit[y]) num.pb(y) ,visit[y]++;
        }
        vector<int> query;
        while(q--){
        int x;sc1(x);
        if(!visit[x]) num.pb(x),visit[x]++;
        query.pb(x);
        }
        sort(all(num));
        rep(i,0,num.size()) mp[num[i]] = i+1;
        rep(i,0,v.size()){
        pii tom = v[i];
        cum[mp[tom.ff]]++;
        cum[mp[tom.ss]+1]--;
        }
        for(int i = 1;i <= num.size();i++) cum[i] += cum[i-1];
        rep(i,0,query.size()){
        cout << cum[mp[query[i]]] << endl;
        }
    }
   return 0;
}
/*

*/
