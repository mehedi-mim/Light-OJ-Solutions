#include <bits/stdc++.h>
using namespace std;
#define mx 40000

vector<int> g[mx];
int cost[mx];
int tree[mx*4];
int from[mx],to[mx];
int visit[mx];
int pos[mx];
int arr[mx];
int sz;

//convert
void dfs(int node) {
  visit[node] = true;
  pos[node] = ++sz;
  from[node] = sz;
  arr[sz] = node;
  to[node] = sz;

  for (size_t i = 0; i < g[node].size(); i++) {
       int v = g[node][i];
       if(!visit[v]){
         dfs(v),to[node] = max(to[node],to[v]);
       }
  }
}

//convert

//segment tree........
void init(int node ,int b,int e)
{
    if(b == e){
        tree[node] = cost[arr[b]];
        return ;
    }
    int Left = node * 2;
    int Right = node* 2 + 1;
    int mid = (b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i > e || j < b)return 0;
    if(b >= i && e <= j) return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b+e)/2;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return p1 + p2;

}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

//LCA Part

int T[mx];
int P[mx][22];
int L[mx];
void dfss(int frm,int u,int dep)
{
    T[u]=frm;
    L[u]=dep;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==frm) continue;
        dfss(u,v,dep+1);
    }
}
int lca_query(int p, int q)
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }
void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

// LCA end

int main() {
    int Tc;scanf("%d",&Tc);
    int cs = 0;
    while (Tc--) {
    sz = 0;
    memset(tree,0,sizeof tree);
     for(int i = 0;i < mx-1;i++){
        cost[i] = 0;
        T[i] = 0;
        g[i].clear();
        visit[i] = 0;
        from[i] = 0;
        to[i] = 0;
        arr[i] = 0;
     }
      int n;scanf("%d",&n);
      for (size_t i = 0; i < n; i++) {
        int x;scanf("%d",&x);
        cost[i] = x;
      }
      for (size_t i = 1; i < n; i++) {
        int u,v;scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    dfss(0,0,0);
    lca_init(n);
    init(1,1,n);
    int q;scanf("%d",&q);
    printf("Case %d:\n",+cs);

    while(q--){
        int type,u,v;scanf("%d%d%d",&type,&u,&v);
        if(type == 0){
            int keep = lca_query(u,v);

            cout << pos[u] <<" " << pos[keep] <<" " << pos[v] << endl;
            int x,y,z;
            int ans = 0,p1 = 0,p2= 0;
            x = min(pos[u],pos[keep]);
            y = max(pos[u],pos[keep]);
            p1 = query(1,1,n,x,y);

            x = min(pos[keep],pos[v]);
            y = max(pos[keep],pos[v]);
            cout << x <<" " << y << endl;
            p2 = query(1,1,n,x,y);

            int p3 = query(1,1,n,y,y);
            ans = (p1 + p2 - p3);
            printf("%d\n",ans);
        }
        else{
            update(1,1,n,pos[u],v);
        }
    }




}
return 0;
}
/*
1
7
1 2 3 4 5 6 7
1 5
1 6
6 7
6 4
4 2
4 3
*/
