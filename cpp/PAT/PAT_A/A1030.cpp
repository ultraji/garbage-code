/*
1030. Travel Plan (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A traveler's map gives the distances between cities along the highways, together with the cost of each 
highway. Now you are supposed to write a program to help a traveler to decide the shortest path between 
his/her starting city and the destination. If such a shortest path is not unique, you are supposed to 
output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers 
N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to 
N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. 
Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to 
the destination, followed by the total distance and the total cost of the path. The numbers must be 
separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Sample Output
0 2 3 3 40
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 501,INF = 123456789;
int vd[MAXN][MAXN],vc[MAXN][MAXN];
int dd[MAXN],dc[MAXN],vis[MAXN],pre[MAXN],path[MAXN];

int main(){
    int n,m,s,e;
    //freopen("in/in.txt","r",stdin);
    cin >> n >> m >> s >> e;
    fill(vd[0],vd[0]+MAXN*MAXN,INF);
    fill(vc[0],vc[0]+MAXN*MAXN,INF);
    fill(dd,dd+MAXN,INF);
    fill(dc,dc+MAXN,INF);
    fill(vis,vis+MAXN,0);
    fill(pre,pre+MAXN,-1);
    for(int i = 0; i < m; i++){
        int a,b,dis,cost;
        cin >> a >> b >> dis >> cost;
        vd[a][b] = vd[b][a] = dis;
        vc[a][b] = vc[b][a] = cost;
    }
    dd[s] = 0;
    dc[s] = 0;
    for(int k = 0; k < n; k++){
        int min_dis = INF,whin = -1;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && dd[i] <min_dis){
                min_dis = dd[i];
                whin  = i;
            }  
        }
        if(whin == e) break;
        vis[whin] = 1;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && dd[whin] + vd[whin][i] < dd[i]){
                dd[i] = dd[whin] + vd[whin][i];
                dc[i] = dc[whin] + vc[whin][i];
                pre[i] = whin;
            }
            if(vis[i] == 0 && dd[whin] + vd[whin][i] == dd[i] 
              && dc[whin] + vc[whin][i] < dc[i]){
                  dc[i] = dc[whin] + vc[whin][i];
                  pre[i] = whin;
            }
        }
    }
    int j = 0;
    for(int i = e; i != -1; i = pre[i]) path[j++] = i;
    reverse(path,path+j);
    for(int i = 0; i < j; i++){
        printf("%d ",path[i]);
    }
    printf("%d %d\n",dd[e],dc[e]);
    return 0;
}