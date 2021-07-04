/*
1084. Broken Keyboard (20)
时间限制
200 ms
内存限制
65536 kB
作者
CHEN, Yue
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters 
corresponding to those keys will not appear on screen.Now given a string that you are supposed to 
type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and 
the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are 
either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the 
space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The 
English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed 
that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es

Sample Output:
7TI
*/

#include <iostream>
#include <cstring>
using namespace std;
int mp[128],vis[128];
int main(){
    char a[100],b[100];
    gets(a);
    gets(b);
    int al = strlen(a), bl = strlen(b);
    for(int i = 0; i < al; i++){
        if(isalpha(a[i])) a[i] = toupper(a[i]);
        mp[a[i]] ++;
    }
    for(int i = 0; i < bl; i++){
        if(isalpha(b[i])) b[i] = toupper(b[i]);
        mp[b[i]] --;
    }
    for(int i = 0; i < al; i++){
        if(mp[a[i]] != 0 && vis[a[i]] == 0){
            printf("%c",a[i]);
            vis[a[i]] = 1;
        }
    }
    return 0;
}