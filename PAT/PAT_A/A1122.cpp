/*
1122. Hamiltonian Cycle (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".
In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2< N <= 200), the number of vertices, 
and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format "Vertex1 Vertex2", where the 
vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:

n V1 V2 ... Vn

where n is the number of vertices in the list, and Vi's are the vertices on a path.

Output Specification:

For each query, print in a line "YES" if the path does form a Hamiltonian cycle, or "NO" if not.

Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1

Sample Output:
YES
NO
NO
NO
YES
NO
*/

#include <iostream>
using namespace std;
int mp[202], v[202][202],p[202];
int main(){
    int n, m, k, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a][b] = v[b][a] = 1;
    }
    cin >> k;
    while(k--){
        bool flag = true;
        fill(mp, mp+n+1, 0);
        cin >> m;
        if(m > 0){
            if(m != n+1) flag = false;
            for(int i = 0; i < m; i++){
                cin >> p[i];
                mp[p[i]] = 1;
            }
            for(int i = 1; i <= n; i++){        //判断每个数字是否都出现，
                if(mp[i] != 1) flag = false;
            }
            for(int i = 0; i < m-1; i++){       //判断是否为通路
                if(v[p[i]][p[i+1]] == 0) flag = false;
            }
            if(p[0] != p[m-1]) flag = false;    //首尾是否相同
        }else{
            flag = false;
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}