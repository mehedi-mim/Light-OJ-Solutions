#include <bits/stdc++.h>
using namespace std;
int arr[25][25];
int wheel[25];
int main()
{
    int T;
    scanf("%d",&T);
    int cs = 0;
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        int ans = 0;
        memset(arr,0,sizeof arr);
        memset(wheel,0,sizeof wheel);

        queue <int> q;
        for(int i = 1;i <= n;i++) q.push(i);

        int cnt = 0;
        int i = 1;
        while(1){

            if(wheel[i] == 0){

                queue<int> temp_q;
                bool paisi = true;

                while(!q.empty()){
                    int person = q.front();q.pop();
                    if(!arr[person][i] && paisi){
                        arr[person][i]++;
                        wheel[i] = person;
                        cnt++;
                        paisi = false;
                        continue;
                    }
                    temp_q.push(person);
                }
                if(temp_q.size()) q = temp_q;

            }
            else{

                int person = wheel[i];
                wheel[i] = 0;
                q.push(person);
                queue<int> temp_q;
                bool paisi = true;
                while(!q.empty()){
                    int person = q.front();q.pop();
                    if(!arr[person][i] && paisi){
                        arr[person][i]++;
                        wheel[i] = person;
                        cnt++;
                        paisi = false;
                        continue;
                    }
                    temp_q.push(person);
                }
                if(temp_q.size()) q = temp_q;

            }
            ans += 5;
            if(cnt == n*m && q.size() == n) break;

            i++;
            if(i > m) i = 1;
        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
