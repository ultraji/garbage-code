/*
1116. Come on! Let's C (20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the 
idea of the contest is for fun, the award rules are funny as the following:
0. The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
1. Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
2. Everyone else will receive chocolates.
Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10000), the total number of contestants. 
Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer 
K followed by K query ID's.

Output Specification:
For each query, print in a line "ID: award" where the award is "Mystery Award", or "Minion", or "Chocolate". If the ID is not in the ranklist, 
print "Are you kidding?" instead. If the ID has been checked before, print "ID: Checked".

Sample Input:
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222

Sample Output:
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/

#include <iostream>
#include <cmath>
using namespace std;
string mp[10001];
int vis[10001];

bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i < sqrt(n)+1; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n, m, a;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(i == 1){
            mp[a] = "Mystery Award";
        }else if(isPrime(i)){
            mp[a] = "Minion";
        }else{
            mp[a] = "Chocolate";
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        printf("%04d: ",a);
        if(vis[a] == 0){
            if(mp[a] == ""){
                printf("Are you kidding?\n");
            }else{
                vis[a] = 1;
                printf("%s\n",mp[a].c_str());
            }
        }else{
            printf("Checked\n");
        }
    }
    return 0;
}