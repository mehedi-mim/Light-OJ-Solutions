#include <bits/stdc++.h>
using namespace std;
#define mx 100009
struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

struct table{
int node;
int cost;
};
int pr[mx];
vector<edge> e;     //memset koro...............
table P[mx][22];
int T[mx],L[mx],dist[mx];
vector<pair<int,int> > g[mx];  //memset kor...........
//MST................

int find(int r)
{
    if(pr[r] == r) return r;
    else pr[r] = find(pr[r]);
    return pr[r];
}
void mst(int n)
{
    sort(e.begin(), e.end());
    for (int i = 0; i <= n; i++)
        pr[i] = i;
    int count = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        int x,y,z;
        x = e[i].u;y = e[i].v;z = e[i].w;
        int u = find(x);
        int v = find(y);
        if (u != v) {
            g[x].push_back(make_pair(y,z));
            g[y].push_back(make_pair(x,z));
            pr[u] = v;
            count++;
            if (count == n - 1)
                break;
        }
    }
}
//MST part end........................


//LCA part..
void dfs(int from,int u,int dep,int cost)
{

    T[u] = from;
    L[u] = dep;
    dist[u] = cost;
    for(int i = 0;i < (int)g[u].size();i++)
    {
        int v = g[u][i].first;
        if(v == from) continue;
        int w = g[u][i].second;
        dfs(u,v,dep+1,w);
    }
}
int lca_query(int p, int q)
  {
      int tmp, log, i;
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
          log = 1;

      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
      }
        int ret = 0;
        for (i = log; i >= 0; i--){
          if (L[p] - (1 << i) >= L[q]){
               ret = max(ret,P[p][i].cost);
               p = P[p][i].node;

          }
        }

        if (p == q) return ret;
         for (i = log; i >= 0; i--)
          if (P[p][i].node != -1 && P[p][i].node != P[q][i].node)
          {
              int keep1 = P[p][i].cost,keep2 = P[q][i].cost;
              p = P[p][i].node; q = P[q][i].node;
              ret = max(ret,max(keep1,keep2));
          }
      ret = max(ret,max(dist[p],dist[q]));
      return ret;
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0].node = T[i],P[i][0].cost = dist[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1].node != -1){
                {

                   P[i][j].node = P[P[i][j - 1].node][j - 1].node;
                   P[i][j].cost = max(P[i][j-1].cost,P[P[i][j - 1].node][j - 1].cost);
                }
             }

 }
//LCA part end..................

int main()
{
    int tc;scanf("%d",&tc);int cs = 0;
    while(tc--){
        int n,m;
        scanf("%d %d",&n,&m);
        e.clear();
        for(int i = 0;i < n;i++){
         g[i].clear();
        }
        while(m--){
            int x,y,cost;
           scanf("%d %d %d",&x,&y,&cost);
            x--;y--;
            edge get;get.u = x;get.v = y;
            get.w = cost;
            e.push_back(get);
        }
        mst(n);
        dfs(0,0,0,0);
        lca_init(n);
//        for(int j = 0;j < 3;j++){
//            for(int i = 0;i < n;i++){
//                cout << i <<" " << P[i][j].cost << ";";
//            }
//            cout << endl;
//        }

        int q;scanf("%d",&q);
        printf("Case %d:\n",++cs);
        while(q--){
            int x,y;
            scanf("%d %d",&x,&y);
            x--;y--;
            int lca = lca_query(x,y);
            printf("%d\n",lca);
        }
    }
    return 0;
}

