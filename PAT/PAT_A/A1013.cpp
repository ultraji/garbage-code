/*
1013. Battle Over Cities (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by 
the enemy, all the highways from/toward that city are closed. We must know immediately if we need to 
repair any other highways to keep the rest of the cities connected. Given the map of cities which have 
all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, 
quickly.
For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is 
occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M 
and K, which are the total number of cities, the number of remaining highways, and the number of cities 
to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the 
numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line 
containing K numbers, which represent the cities we concern.

Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is 
lost.

Sample Input
3 2 3
1 2
1 3
1 2 3

Sample Output
1
0
0
*/


//计算图的联通量
//要修的highway = 联通量-1;
#include <iostream>
using namespace std;
int n,v[1001][1001],vis[1001];

void dfs(int index){
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0 && v[index][i] != 0){
            vis[i] = 1;
            dfs(i);
        }
    }
}
//DFS的次数 即为联通量的个数
int cal_liantong(int j){
    int count = 0;
    fill(vis,vis+n+1,0);
    vis[j] = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            count ++;
            vis[i] = 1;
            dfs(i);
        }
    }
    return count;
}

int main(){
    int m,k,j,a,b;
    //freopen("in/in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    fill(v[0],v[0]+1001*1001,0);
    for(int i = 0; i < m; i++){
        scanf("%d %d",&a,&b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d",&j);
        printf("%d\n",cal_liantong(j)-1);
    }
    return 0;
}