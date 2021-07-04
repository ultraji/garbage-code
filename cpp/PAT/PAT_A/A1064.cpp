/*
1064. Complete Binary Search Tree (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.
Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You 
are supposed to output the level order traversal sequence of this BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative 
integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in 
a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0

Sample Output:
6 3 8 1 5 7 9 0 2 4
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int in[1001], level[1001];
// typedef struct node{
//     int data;
//     node *left, *right;
// }*tree;

int pow2(int n){
    int sum  = 1;
    for(int i = 0; i < n; i++) sum *= 2;
    return sum;
}

// node* newNode(int data){
//     node* t = new node;
//     t->data = data;
//     t->left = t->right = NULL;
// }

void creatTree(/*tree &t,*/ int l, int r, int pos){
    if(l > r) return;
    int n = r-l+1;
    int h = log(n+1)/log(2);
    int l_num = n-(pow2(h)-1);
    int root = l + min(pow2(h)/2, l_num) + (pow2(h-1)-1);
    level[pos] = in[root];
    //t = newNode(in[root]);
    creatTree(/*t->left,*/ l, root-1, 2*pos);
    creatTree(/*t->right,*/ root+1, r, 2*pos+1);
}

int main(){
    int n;
    //tree t = NULL;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    sort(in, in+n);
    creatTree(/*t,*/ 0, n-1, 1);
    for(int i = 1; i <= n; i++){
        printf("%d%c",level[i],(i==n)?'\n':' ');
    }
    return 0;
}