/*
1111. Online Map (30)
keywords: Dijkstra算法

Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your 
user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the 
total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in 
the format:
V1 V2 one-way length time
where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, 
or 0 if not; length is the length of the street; and time is the time taken to pass the street.
Finally a pair of source and destination is given.

Output Specification:
For each case, first print the shortest path from the source to the destination with distance D in the format:
Distance = D: source -> v1 -> ... -> destination
Then in the next line print the fastest path with total time T:
Time = T: source -> w1 -> ... -> destination
In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the 
fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.
In case the shortest and the fastest paths are identical, print them in one line in the format:
Distance = D; Time = T: source -> u1 -> ... -> destination

Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5

Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = __INT_MAX__, MAXN = 501;
int n, vl[MAXN][MAXN], vt[MAXN][MAXN];

void dijkstra_length(int s, int e, int &cost, int &cnt, int path[]) {
    int dpl[n], dpt[n], vis[n], tmp[n];
    fill(dpl, dpl + n, INF);
    fill(dpt, dpt + n, INF);
    fill(vis, vis + n, 0);
    fill(tmp, tmp + n, -1);
    dpl[s] = dpt[s] = 0;
    while(true) {
        int mindp = INF, j = -1;
        for (int  i = 0; i < n; i++) {
            if (vis[i] == 0 && dpl[i] < mindp) {
                j = i;
                mindp = dpl[j];
            }
        }
        if(j == -1 || j == e){
            break;
        }
        vis[j] = 1;
        for (int i = 0; i < n; i++) {
            if(vis[i] == 0 && vl[j][i] != INF) {
                if ( (dpl[j] + vl[j][i] < dpl[i]) ||
                    (dpl[j] + vl[j][i] == dpl[i] && dpt[j] + vt[j][i] < dpt[i]) ) {
                    dpl[i] = dpl[j] + vl[j][i];
                    dpt[i] = dpt[j] + vt[j][i];
                    tmp[i] = j;     /* 记录路径 */
                }
            }
        }
    }
    cost = dpl[e];
    cnt = 0;
    for(int i = e; i != -1; i = tmp[i]) {
        path[cnt++] = i;
    }
    reverse(path, path+cnt);
}

void dijkstra_time(int s, int e, int &cost, int &cnt, int path[]) {
    int dpc[n], dpt[n], vis[n], tmp[n];
    fill(dpc, dpc + n, INF);
    fill(dpt, dpt + n, INF);
    fill(vis, vis + n, 0);
    fill(tmp, tmp + n, -1);
    dpc[s] = dpt[s] = 0;
    while(true) {
        int mindp = INF, j = -1;
        for (int  i = 0; i < n; i++) {
            if (vis[i] == 0 && dpc[i] < mindp) {
                j = i;
                mindp = dpc[j];
            }
        }
        if(j == -1 || j == e){
            break;
        }
        vis[j] = 1;
        for (int i = 0; i < n; i++) {
            if(vis[i] == 0 && vl[j][i] != INF) {
                if ( (dpt[j] + vt[j][i] < dpt[i]) ||
                    (dpt[j] + vt[j][i] == dpt[i] && dpc[j] + 1 < dpc[i]) ) {
                    dpt[i] = dpt[j] + vt[j][i];
                    dpc[i] = dpc[j] + 1;
                    tmp[i] = j;     /* 记录路径 */
                }
            }
        }
    }
    cost = dpt[e];
    cnt = 0;
    for(int i = e; i != -1; i = tmp[i]) {
        path[cnt++] = i;
    }
    reverse(path, path+cnt);
}

int main()
{
    int m, s, e;
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    fill(vl[0], vl[0]+ MAXN*MAXN, INF);
    fill(vt[0], vt[0]+ MAXN*MAXN, INF);
    for(int i = 0; i < m; i++) {
        int v1, v2, oneway, length, time;
        cin >> v1 >> v2 >> oneway >> length >> time;
        if (oneway) {
            vl[v1][v2] = length;
            vt[v1][v2] = time;
        } else {
            vl[v1][v2] = vl[v2][v1] = length;
            vt[v1][v2] = vt[v2][v1] = time;
        }
    }
    cin >> s >> e;
    int cost_length, cost_time, cnt_length, cnt_time, path_length[n], path_time[n];
    dijkstra_length(s, e, cost_length, cnt_length, path_length);
    dijkstra_time(s, e, cost_time, cnt_time, path_time);
    bool is_same = true;
    if (cnt_length == cnt_time) {
        for(int i = 0; i < cnt_length; i++) {
            if(path_length[i] != path_time[i]) {
                is_same = false;
                break;
            }
        }
    }else {
        is_same = false;
    }
    if(is_same) {
        printf("Distance = %d; Time = %d: ", cost_length, cost_time);
    }else {
        printf("Distance = %d: ", cost_length);
        for (int i = 0; i < cnt_length; i++) {
            printf("%d", path_length[i]);
            if(i != cnt_length-1) {
                printf(" -> ");
            }
        }
        printf("\nTime = %d: ", cost_time);
    }
    for (int i = 0; i < cnt_time; i++) {
        printf("%d", path_time[i]);
        if(i != cnt_time-1) {
            printf(" -> ");
        }
    }
    return 0;
}
