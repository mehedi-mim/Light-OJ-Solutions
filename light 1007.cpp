#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll mark[(5000009>>5) + 100];
#define ipt freopen("input.txt","r",stdin)
#define opt freopen("output.txt","w",stdout)
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))
ll phi[5000005];
void sieve(ll n) {
    for(ll i = 1;i <= n;i++) phi[i] = i;
    ll i, j;
    SET(1);
    for(i = 2; i <= n; i++) {
        if(!GET(i)) {
            for(j = i; j <= n; j += i) {
                phi[j] = phi[j]/i*(i-1);
                SET(j);
            }
        }
    }
   for(ll i = 1;i <= n;i++) phi[i] = phi[i]*phi[i] + phi[i-1];
}

int main()
{
   //ipt;
   //opt;
   sieve(5000000);
   ll T,cs = 0;scanf("%llu",&T);
   while(T--){
   ll a,b;
   scanf("%llu %llu",&a,&b);
   ll ans = phi[b] - phi[a-1];
   printf("Case %llu: %llu\n",++cs,ans);
   }
   return 0;
}


