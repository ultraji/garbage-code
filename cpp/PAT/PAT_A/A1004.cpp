/*
1004. Counting Leaves (30)
keywords: 层序遍历

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who 
have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number 
of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, 
followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the 
root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority 
level starting from the root. The numbers must be printed in a line, separated by a space, and there 
must be no extra space at the end of each line.The sample case represents a tree with only 2 nodes, 
where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on 
the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02

Sample Output
0 1
*/

#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 101;

int lf_cnt[MAXN];

struct node {
    int level;
    queue<int> child;
}tree[MAXN];

int main() {
    int n, m, deep;
    queue<node> q;
    //freopen("in.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fa, cnt, cld;
        cin >> fa >> cnt;
        while (cnt--) {
            cin >> cld;
            tree[fa].child.push(cld);
        }
    }
    tree[1].level = 1;
    q.push(tree[1]);
    while(!q.empty()) {
        node no = q.front();
        q.pop();
        deep = no.level;
        if (no.child.empty()) {
            lf_cnt[deep] ++;
        }else {
            while (!no.child.empty()) {
                int cld = no.child.front();
                no.child.pop();
                tree[cld].level = deep + 1;
                q.push(tree[cld]);
            }
        }
    }
    for(int i = 1; i <= deep; i++ ) {
        printf("%d%c", lf_cnt[i], (i == deep )? '\n':' ');
    }
    return 0;
}