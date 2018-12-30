
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <stack>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;

#define sf                 scanf
#define sf1(a)             scanf("%d",&a)
#define sf2(a,b)           scanf("%d %d",&a,&b)
#define sf3(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d)       scanf("%d %d %d %d",&a,&b,&c,&d)
#define sfl1(a)            scanf("%lld",&a)
#define sfl2(a,b)          scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sfl4(a,b,c,d)      scanf("%lld %lld %lld %lld",&a,&b,&c,&d)

#define pf                 printf
#define pfc(x)             printf("Case %d\n: ",x)
#define pfs(x)             printf("%d\n",x);

#define TC                 int __T;sf1(__T);while(__T--)
#define ll                 long long
#define here               printf("Entered! \n")

#define sqr(a)             ((a)*(a))


#define lst                list<ll>
#define vec                vector<ll>
#define setl               set<ll>
#define setc               set<chat>
#define mapl               map<ll,ll>
#define maps               map<string,ll>
#define mp                 make_pair
#define pii                pair<int,int>
#define pll                pair<ll,ll>

#define fs                 first
#define sc                 second
#define pb                 push_back
#define pfr                push_front
#define ppb                pop_back()
#define all(a)             a.begin(),a.end()
#define Reall(a)           a.rbegin(),a.rend()


#define FOR(a)             for(ll i = 0;i<(a);i++)
#define FOR1(a,b)          for(ll i=(a);i<=(b);i++)
#define mem(x,y)           memset(x,y,sizeof(x))
#define WRITE(f)           freopen(f,"w",stdout)

struct sorter{ll first,second;};
bool cmp (sorter A,sorter B){ if(A.first==B.first) return A.second<B.second; return A.first<B.first;}
ll _M;
ll BM(ll N,ll P){if(P==0)return 1;if(P%2==0){ll x=BM(N,P/2);return ((x%_M)*(x%_M))%_M;}else return ((N%_M)*(BM(N,P-1)%_M))%_M;}

int main()
{

   ll T,n,m;
   scanf("%lld",&T);
   for(int i = 1;i <= T;i++){
    scanf("%lld %lld",&n,&m);
    ll ans = (n*m)/2;
    cout << "Case "<<i<<": "<< ans << endl;
   }

   return 0;
}





