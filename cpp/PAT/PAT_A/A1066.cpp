/*
1066. Root of AVL Tree (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; 
if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules. 
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys 
to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70

Sample Input 2:
7
88 70 61 96 120 90 65

Sample Output 2:
88
*/
#include <iostream>
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
    r  = tmp;
}

void R(node* &r){
    node* tmp = r->left;
    r->left= tmp->right;
    tmp->right = r;
    updateHeight(r);
    updateHeight(tmp);
    r  = tmp;
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
    int n, a;
    node* r = NULL;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        insert(r,a);
    }
    printf("%d",r->data);
    return 0;
}