/*
1123. Is It a Complete AVL Tree (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; 
if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.   
Now given a sequence of insertions, you are supposed to output the level-order traversal sequence of the resulting AVL tree, and to tell if it 
is a complete binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<= 20). Then N distinct integer keys are 
given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, insert the keys one by one into an initially empty AVL tree. Then first print in a line the level-order traversal sequence 
of the resulting AVL tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. 
Then in the next line, print "YES" if the tree is complete, or "NO" if not.

Sample Input 1:
5
88 70 61 63 65
Sample Output 1:
70 63 88 61 65
YES

Sample Input 2:
8
88 70 61 96 120 90 65 68

Sample Output 2:
88 65 96 61 70 90 120 68
NO
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node{
    int data,height;
    node *left,*right;
};

node* newNode(int data){
    node* t = new node;
    t->data = data;
    t->height = 1;
    t->left = t->right = NULL;
    return t;
}

int getHeight(node* r){
    if(r == NULL) return 0;
    return r->height;
}

int getBalanceFactor(node* r){
    return getHeight(r->left) - getHeight(r->right);
}

void updateHeight(node* &r){
    r->height = max( getHeight(r->left), getHeight(r->right) ) + 1;
}

void L(node* &r){
    node* tmp = r->right;
    r->right = tmp->left;
    tmp->left = r;
    updateHeight(r);
    updateHeight(tmp);
    r = tmp;
}

void R(node* &r){
    node* tmp = r->left;
    r->left= tmp->right;
    tmp->right = r;
    updateHeight(r);
    updateHeight(tmp);
    r = tmp;
}

void insert(node* &r, int data){
    if(r == NULL){
        r = newNode(data);
        return;
    }
    if(data < r->data){
        insert(r->left, data);
        updateHeight(r);
        if(getBalanceFactor(r) == 2){
            if(getBalanceFactor(r->left) == 1){
                R(r);
            }else if(getBalanceFactor(r->left) == -1){
                L(r->left);
                R(r);
            }
        }
    }else if(data > r->data){
        insert(r->right, data);
        updateHeight(r);
        if(getBalanceFactor(r) == -2){
            if(getBalanceFactor(r->right) == -1){
                L(r);
            }else if(getBalanceFactor(r->right) == 1){
                R(r->right);
                L(r);
            }
        }
    }
}

int main(){
    vector<int> v;
    int n, a;
    queue<node*> q;
    node* t = NULL;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        insert(t, a);
    }
    bool isComplete = true, overFlag = false;
    q.push(t);
    while(!q.empty()){
        t = q.front();
        q.pop();
        v.push_back(t->data);
        if((t->left||t->right) && overFlag ) isComplete = false;
        if(t->left != NULL) q.push(t->left);
        if(t->right != NULL) q.push(t->right);
        if(!overFlag && (t->left == NULL || t->right == NULL)){
            overFlag = true;
            if(t->left == NULL && t->right != NULL) isComplete = false;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d%c", v[i], (i==n-1)?'\n':' ');
    }
    printf("%s",isComplete?"YES":"NO");
    return 0;
}