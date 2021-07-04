/*
1121. Damn Single (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big 
party, so they can be taken care of.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of couples. 
Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of 
couples, there is a positive integer M (<=10000) followed by M ID's of the party guests. The numbers are separated by spaces. It is 
guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

Output Specification:
First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be 
separated by exactly 1 space, and there must be no extra space at the end of the line.

Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

Sample Output:
5
10000 23333 44444 55555 88888
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int, int> cp, party;
vector<int> v;
int main(){
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cp[a] = b;
        cp[b] = a;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(cp.count(a) == 0){
            v.push_back(a);
        }else{
            if(party.count(cp[a]) == 1){
                party.erase(cp[a]);
            }else{
                party[a] = 1;
            }
        }
    }
    for(auto it = party.begin(); it != party.end(); it++){
        v.push_back(it->first);
    }
    sort(v.begin(), v.end());
    n = v.size();
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        printf("%05d%c", v[i], (i==n-1)?'\n':' ');
    }
    return 0;
}