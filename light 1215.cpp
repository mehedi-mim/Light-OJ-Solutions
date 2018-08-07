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
struct Sorter{int fs,sc;}; // Define array here before last ';'.
bool cmp(Sorter A,Sorter B){if(A.fs==B.sc) return A.sc < B.sc;return A.fs < B.fs;}

map<ll,ll> aa,bb,lcmlcm;
#define MAX 100000000
#define LIM 10000
int flagArr[MAX>>6];
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))
vector<int> prime;
void BitSeive()
{
       register int i,j,k;
       for(i=3;i<LIM;i+=2)
       {
              if(!ifComp(i))
              {
                     for(j=i*i,k=i<<1;j<MAX;j+=k)
                            isComp(j);
              }
       }
       prime.push_back(2);
       for(int i = 3;i < 1000000; i+= 2){
         if(!ifComp(i))
              {
                prime.push_back(i);
              }
       }
}

int main() {
    BitSeive();
    //cout << prime[prime.size()-1] << endl;
    ll T;ll cs = 0;
    scl1(T);
    while(T--){
    ll a,b,c,lcm;c = 1;
    aa.clear();bb.clear();lcmlcm.clear();
    scl2(a,b);scl1(lcm);
    // a calculating
    set<int> s;
    REP(i,0,prime.size()){
    if(a < prime[i]) break;
    if(a % prime[i] == 0){
      s.insert(prime[i]);
      int cnt = 0;
      while(a%prime[i] == 0){
        cnt++;
        a /= prime[i];
      }
      aa[prime[i]] = cnt;
    }
    }
    if(a > 2){
      aa[a] = 1;
      s.insert(a);
    }
    // b calculating
     REP(i,0,prime.size()){
    if(b < prime[i]) break;
    if(b % prime[i] == 0){
      int cnt = 0;
      s.insert(prime[i]);
      while(b%prime[i] == 0){
        cnt++;
        b /= prime[i];
      }
      bb[prime[i]] = cnt;
    }
    }
    if(b > 2){
      s.insert(b);bb[b] = 1;
    }
    REP(i,0,prime.size()){
    if(lcm < prime[i]) break;
     if(lcm%prime[i] == 0){
      int cnt = 0;
      while(lcm%prime[i] == 0){
        cnt++;
        lcm /= prime[i];
      }
      lcmlcm[prime[i]] = cnt;
      if(cnt > aa[prime[i]] && cnt > bb[prime[i]]){
        int temp = cnt;
        while(temp){
          c *= prime[i];
          temp--;
        }
      }
     }
    }
    if(lcm > 2){
      c *= lcm;
    }
    bool paisi = true;
    set<int> :: iterator it;
    for(it = s.begin(); it != s.end();it++){
        int i = (*it);
        ll mx = max(aa[i],bb[i]);
      //cout << lcmlcm[i] << " " << mx <<" " << i << endl;
      if(lcmlcm[i] < mx) {
        paisi = false;
        break;
      }
    }
    printf("Case %lld: ",++cs);
    if(paisi) printf("%lld\n",c);
    else puts("impossible");
    }
}
/*
*/
