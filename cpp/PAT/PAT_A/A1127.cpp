/*
1127. ZigZagging on a Tree (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder 
and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is 
too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, 
print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 
1 11 5 8 17 12 20 15.


Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 30), the total number of nodes in the 
binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are 
separated by a space.

Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, 
and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1

Sample Output:
1 11 5 8 17 12 20 15
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int in[31], post[31],zigzag[31], n, k = 0;
struct node{
    int data,level;
    node *left, *right;
};

node* newNode(int data, int level){
    node* r = new node;
    r->data = data;
    r->level = level;
    r->left = r->right = NULL;
    return r;
}

void creatTree(node* &t, int in_s, int in_e, int post_s, int post_e, int level){
    if(in_s > in_e) return;
    int pos = post[post_e], mid;
    for(mid = in_s; mid <= in_e; mid ++){
        if(in[mid] == pos) break;
    }
    t = newNode(pos, level);
    creatTree(t->left, in_s, mid-1, post_s, post_s + mid-1-in_s, level+1);
    creatTree(t->right, mid+1, in_e, post_e-1 - (in_e-mid-1), post_e-1, level+1);
}

int main(){
    queue<node*> q;
    stack<int> s;
    node *t = NULL, *r;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    creatTree(t, 0, n-1, 0, n-1, 1);
    q.push(t);
    while(!q.empty()){
        r = q.front();
        q.pop();
        if(r->level % 2 == 0){
            for( ;!s.empty(); s.pop()){
                zigzag[k++] = s.top();
            }
            zigzag[k++] = r->data;
        }else{
            s.push(r->data);
        }
        if(r->left != NULL) q.push(r->left);
        if(r->right != NULL) q.push(r->right);
    }
    for( ;!s.empty(); s.pop()){
        zigzag[k++] = s.top();
    }
    for(int i = 0; i < n; i++){
        printf("%d%c", zigzag[i], (i==n-1)?'\n':' ');
    }
    return 0;
}