#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll matA[4][4],matI[4][4],matM[4][4];
ll matTemp[4][4];
ll Mod;
void mulIM()
{
    memset(matTemp,0,sizeof matTemp);

    for(ll i = 1;i <= 2;i++){
        for(ll j = 1;j <= 2;j++){
            for(ll k = 1;k <= 2;k++){
                ll keep = matTemp[i][j];
                ll peek = (matI[i][k]%Mod*matM[j][k]%Mod)%Mod;
                matTemp[i][j] = (keep+peek)%Mod;
            }
        }
    }
    for(ll i = 1;i <= 2;i++)for(ll j = 1;j <= 2;j++) matI[i][j] = matTemp[i][j];
}
void mulMM()
{
    memset(matTemp,0,sizeof matTemp);
    for(ll i = 1;i <= 2;i++){
        for(ll j = 1;j <= 2;j++){
            for(ll k = 1;k <= 2;k++){
                ll keep = matTemp[i][j];
                ll peek = (matM[i][k]%Mod*matM[j][k]%Mod)%Mod;
                matTemp[i][j] = (keep+peek)%Mod;
            }
        }
    }
    for(ll i = 1;i <= 2;i++)for(ll j = 1;j <= 2;j++) matM[i][j] = matTemp[i][j];

}

void matExpo(ll n)
{
    while(n>0){
        if(n%2){
            mulIM();
        }
        mulMM();
        n /= 2;
    }
}

int main()
{

    int T;
    scanf("%d",&T);int cs = 0;
    while(T--){
         memset(matI,0,sizeof matI);
         memset(matA,0,sizeof matA);
         memset(matM,0,sizeof matM);

         matI[1][1] = matI[2][2] = 1;
         matM[1][2] = matM[2][2] = matM[2][1] = 1;

        ll f1,f2,n,m,ans = 0;
        scanf("%lld %lld %lld %lld",&f1,&f2,&n,&m);

        Mod = 1;
        while(m--)Mod *= 10;
        matA[1][1] = f1;matA[1][2] = f2;
        matExpo(n);

        memset(matTemp,0,sizeof matTemp);
        if(n)
        for(ll i = 1;i <= 1;i++){
        for(ll j = 1;j <= 2;j++){
            for(ll k = 1;k <= 2;k++){
                ll keep = matTemp[i][j];
                ll peek = (matA[i][k]%Mod*matI[j][k]%Mod)%Mod;
                matTemp[i][j] = (keep+peek)%Mod;
            }
        }
       }
       for(ll i = 1;i <= 1;i++)for(ll j = 1;j <= 2;j++) matA[i][j] = matTemp[i][j];
       ans = matA[1][1];
       printf("Case %d: %lld\n",++cs,ans);
    }
    return 0;
}
