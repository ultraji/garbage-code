/*
1115. Counting Nodes in a BST (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the 
lowest 2 levels of the resulting tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input 
sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary 
search tree.

Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:
n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28

Sample Output:
2 + 4 = 6
*/

/*
#include <iostream>
using namespace std;
int level[51] = {0,3,8};
int main(){
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++){
        level[i] = 2*level[i-1] + 2*level[i-2];
    }
    printf("%d",level[n]);
    return 0;
}
*/

#include <iostream>
#include <queue>
using namespace std;
int level[1001];
struct node{
    int data, level;
    node *left,*right;
};

node* newNode(int data){
    node* r = new node;
    r->data = data;
    r->left = r->right = NULL;
    return r;
}

void insert(node* &t, int data){
    if(t == NULL){
        t = newNode(data);
        return;
    }else{
        if(data > t->data) insert(t->right,data);
        else insert(t->left,data);
    }
}

int main(){
    int n, a, l;
    node* t = NULL;
    queue<node*> q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        insert(t,a);
    }
    t->level = 1;
    q.push(t);
    while(!q.empty()){
        t = q.front();
        level[t->level] ++;
        q.pop();
        if(t->left != NULL){
            q.push(t->left);
            t->left->level = t->level + 1;
        }
        if(t->right != NULL){
            q.push(t->right);
            t->right->level = t->level + 1;
        }
    }
    l = t->level;
    printf("%d + %d = %d", level[l], level[l-1], level[l]+level[l-1]);
    return 0;
}
