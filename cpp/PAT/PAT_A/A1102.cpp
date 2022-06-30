/*
1102. Invert a Binary Tree (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes 
in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the 
indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are 
separated by a space.

Output Specification:
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted 
tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/

#include <iostream>
#include <queue>
using namespace std;
int mp[10],r[2][10], n, root, tmp, k = 0;
struct node{
    int left,right;
}no[10];

void inorder(int a){
    if(no[a].left != -1) inorder(no[a].left);
    r[1][k++] = a;
    if(no[a].right != -1) inorder(no[a].right);
}

int main(){
    char s[4],c;
    queue<int> q;
    scanf("%d%c",&n,&c);
    for(int i = 0; i < n; i++){
        gets(s);
        no[i].left = no[i].right = -1;
        if(isdigit(s[0])){
            no[i].right = s[0]-'0';
            mp[s[0]-'0'] = 1;
        }
        if(isdigit(s[2])){
            no[i].left = s[2]-'0';
            mp[s[2]-'0'] = 1;
        }
    }
    for(int i = 0; i < n; i++) if(mp[i] == 0) root = i;
    for(q.push(root); !q.empty(); q.pop()){
        tmp = q.front();
        r[0][k++] = tmp;
        if(no[tmp].left != -1) q.push(no[tmp].left);
        if(no[tmp].right != -1) q.push(no[tmp].right);
    }
    k = 0;
    inorder(root);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", r[i][j], (j==n-1)?'\n':' ');
    return 0;
}