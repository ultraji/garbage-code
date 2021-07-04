/*
1072.Gas Station (30 分)
keywords: Dijkstra算法

A gas station has to be built at such a location that the minimum distance between the station and any of the residential 
housing is as far away as possible. However it must guarantee that all the houses are in its service range.Now given the 
map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If 
there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution 
is still not unique, output the one with the smallest index number.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: N (≤10^3), the total 
number of houses; M (≤10), the total number of the candidate locations for the gas stations; K (≤10^4), the number of roads 
connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that 
all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer 
length of the road.

Output Specification:
For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the 
average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate 
up to 1 decimal place. If the solution does not exist, simply output No Solution.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

Sample Output 1:
G1
2.0 3.3

Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20

Sample Output 2:
No Solution
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int MAXN = 1011, INF = __INT_MAX__;
#define TF(n, s) ((s[0] == 'G') ? (n + atoi(s.substr(1).c_str())): atoi(s.c_str()))

/* 1001 - 1010 代表 G1 - GM */
int v[MAXN][MAXN];

bool dijkstra(int s, int n, int m, int ds, int *minDs, double *avrDs) {
    int N = n+m;
    int dp[N+1], vis[N+1];
    fill(dp, dp+N+1, INF);
    fill(vis, vis+N+1, 0);
    dp[s] = 0;
    while (true) {
        int mindp = INF, j = -1;
        for (int i = 1; i <= N; i++) {
            if(vis[i] == 0 && dp[i] < mindp) {
                j  = i;
                mindp = dp[j];
            }
        }
        if (j == -1) {
            break;
        }
        vis[j] = 1;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0 && v[j][i] != INF) {
                if(dp[j] + v[j][i] < dp[i]) {
                    dp[i] = dp[j] + v[j][i];
                }
            }
        }
    }
    *minDs = INF;
    *avrDs = 0;
    for(int i = 1; i <= n; i++) {
        if ((!vis[i]) ||  (dp[i] > ds) ) { /* 从GX出发，所有house可达，测试点3 */
            return false;
        }
        if (dp[i] < *minDs) {
            *minDs = dp[i];
        }
        *avrDs += dp[i];
    }
    *avrDs /= n;
    return true;
}

int main()
{
    int n, m, k, ds;
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> k >> ds;
    fill(v[0], v[0]+MAXN*MAXN, INF);
    for(int i = 0; i < k; i++) {
        string s1, s2;
        int t1, t2, d;
        cin >> s1 >> s2 >> d;
        t1 = TF(n, s1);
        t2 = TF(n, s2);
        if(d < v[t1][t2]) {
            v[t1][t2] = v[t2][t1] = d;
        }
    }
    int minDs = -1, solution = -1, t1 = INF;
    double avrDs = INF, t2 = 0;
    for(int i = n + 1; i <= n + m; i++) {
        if(dijkstra(i, n, m, ds, &t1, &t2)) {
            if ( (t1 > minDs) || (t1 == minDs && t2 < avrDs) ) {
                minDs = t1;
                avrDs = t2;
                solution = i;
            }
        }
    }
    if (solution == -1) {
        printf("No Solution");
    }else {
        printf("G%d\n%.1lf %.1lf", solution - n, (double)minDs, avrDs);
    }
    return 0;
}