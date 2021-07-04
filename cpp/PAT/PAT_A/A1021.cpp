/*
1021. Deepest Root (25)
时间限制
1500 ms
内存限制
65536 kB
代码长度限制
16000 B
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the 
selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called 
the deepest root.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer 
N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines 
follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in 
increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" 
where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5

Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/

//树的直径问题
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
struct node{
    int index;
    int deep;
}no;
int father[10010], vis[10010], t[10010], roots[10010], n, k, maxDepth = 0;
vector<int> map[10010];

int findFather(int a){
    while(father[a] != a) a = father[a];
    return a;
}

void Union(int a,int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb) father[fa] = fb;
}

void bfs(int u,int depth){
    queue<node> q;
    fill(vis,vis+n+1,0);
    q.push({u,1});
    vis[u] = 1;
    while(!q.empty()){
        no = q.front();
        u = no.index;
        if(no.deep > maxDepth){
            maxDepth = no.deep;
            k = 0;
            roots[k++] = u;
        }else if(no.deep == maxDepth){
            roots[k++] = u;
        }
        q.pop();
        
        for(int i = 0; i < map[u].size(); i++){
            if(vis[map[u][i]] == 0){
                q.push({map[u][i],no.deep+1});
                vis[map[u][i]] = 1;
            }
        }
    }
}

int main(){
    int a,b,components = 0;
    cin >> n;
    for(int i = 0; i <= n; i++) father[i] = i;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
        Union(a,b);
    }
    for(int i = 1; i <= n; i++){
        if(father[i] == i) components ++;
    } 
    if(components != 1){
        printf("Error: %d components\n",components);
    }else{
        set<int> s;
        bfs(1,1);
        for(int i = 0; i < k; i++)
            s.insert(roots[i]);
        bfs(roots[0],1);
        for(int i = 0; i < k; i++)
            s.insert(roots[i]);
        for(auto it = s.begin(); it != s.end(); it++){
            printf("%d\n",*it);
        }
    }
    return 0;
}