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
double dp[200000];

double Expected_Value(int n)
{
    if(n == 1) return 0.0;
    if(dp[n]) return dp[n];
    double sum = 0;int div = 2;
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0){
            div++;
            sum += Expected_Value(i);
            if(i*i != n){
                div++;
                sum += Expected_Value(n/i);
            }
        }

    }
    sum /= (double)(div-1);
    sum += (double)div/(double)(div-1);
    dp[n] = sum;
    return dp[n];
}

void solve(int n)
{
    for(int i = 1;i <= n;i++){
       dp[i] =  Expected_Value(i);
    }
}
int main() {
    int T;sc1(T);
    int cs = 0;
    solve(100000);
    while(T--){
        int n;sc1(n);
        printf("Case %d: %.10lf\n",++cs,dp[n]);
    }
   return 0;
}
/*

*/


