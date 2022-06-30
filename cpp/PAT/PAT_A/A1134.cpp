/*
1134. Vertex Cover (25)
时间限制
600 ms
内存限制
65536 kB
代码长度限制
16000 B
A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a 
graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10^4), being the 
total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N-1) of 
the two ends of the edge.
After the graph, a positive integer K (<= 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:
Nv v[1] v[2] ... v[Nv]
where Nv is the number of vertices in the set, and v[i]'s are the indices of the vertices.

Output Specification:
For each query, print in a line "Yes" if the set is a vertex cover, or "No" if not.

Sample Input:
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2

Sample Output:
No
Yes
Yes
No
No
*/

//图的所有边 是否能 被给出的顶点集合 遍历

#include <iostream>
#include <vector>
using namespace std;
int mp[10001];
vector<int> v[10001];
int main(){
    int n, m, k, nv, a, b;
    //freopen("in/in.txt","r",stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(i);  //顶点a上有编号为i的边
        v[b].push_back(i);  //顶点b上有编号为i的边
    }
    cin >> k;
    while(k--){
        bool flag = true;
        fill(mp,mp+n,0);
        cin >> nv;
        for(int i = 0; i < nv; i++){
            cin >> a;
            for(int j = 0; j < v[a].size(); j++){
                mp[v[a][j]] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            if(mp[i] != 1) flag = false;
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}