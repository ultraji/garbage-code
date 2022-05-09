/*
1110. Complete Binary Tree (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a tree, you are supposed to tell if it is a complete binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=20) which is the total number of nodes in 
the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node, and gives the indices of the 
left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by 
a space.

Output Specification:
For each case, print in one line "YES" and the index of the last node if the tree is a complete binary tree, or "NO" and the index of the root 
if not. There must be exactly one space separating the word and the number.

Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8

Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1
*/

#include <iostream>
#include <queue>
using namespace std;
int mp[21], n, root, t;
struct node{
    int left,right;
}no[21];
char a[3],b[3];
int main(){
    bool flag = true, over = false;
    queue<int> q;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s %s",a,b);
        if(a[0] != '-'){
            no[i].left = atoi(a);
            mp[no[i].left] = 1;
        }else{
            no[i].left = -1;
        } 
        if(b[0] != '-'){
            no[i].right = atoi(b);
            mp[no[i].right] = 1;
        }else{
            no[i].right = -1;
        }
        if(a[0] == '-' && b[0] != '-') flag = false;
    }
    for(int i = 0; i < n; i++) if(mp[i] == 0) root = i;     //没有出现在左右儿子中的 i 为 root
    q.push(root);
    while(!q.empty() && flag){
        t = q.front();
        q.pop();
        if(over && (no[t].left != -1 || no[t].right != -1)) flag = false;
        if(no[t].left != -1) q.push(no[t].left);
        if(no[t].right != -1) q.push(no[t].right);
        if(!over && (no[t].left == -1 || no[t].right == -1)){
            over = true;
            if(no[t].left == -1 && no[t].right != -1) flag = false;
        }
    }
    printf("%s %d", flag?"YES":"NO", flag?t:root);
    return 0;
}