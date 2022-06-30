/*
1112. Stucked Keyboard (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will 
appear repeatedly on screen for k times.
Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.
Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever 
it is pressed. For example, when k=3, from the string "thiiis iiisss a teeeeeest" we know that the keys "i" and "e" might be stucked, but "s" 
is not even though it appears repeatedly sometimes. The original string could be "this isss a teest".

Input Specification:
Each input file contains one test case. For each case, the 1st line gives a positive integer k ( 1<k<=100 ) which is the output repeating 
times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, 
{0-9} and "_". It is guaranteed that the string is non-empty.

Output Specification:
For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once 
only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest

Sample Output:
ei
case1__this_isss_a_teest
*/

#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int mp[128], vis[128], k;
char s[1001], r1[50], r2[1001], c;
int main(){
    set<char> s_yes;
    scanf("%d%c",&k,&c);
    gets(s);
    for(int i = 0,cnt = 0; i < strlen(s)-1; i++){
        mp[s[i]] = 1;
        if(s[i] != c){
            c = s[i];
            cnt = 0;
        }
        cnt ++;
        if(s[i+1] != c && cnt%k != 0) s_yes.insert(s[i]);
    }
    for(auto it = s_yes.begin(); it != s_yes.end(); it ++){
        mp[*it] = 0;
    }
    int x = 0, y = 0;
    for(int i = 0; i < strlen(s); i++){
        r2[y++] = s[i];
        if(mp[s[i]] == 1){
            if(vis[s[i]] ++ == 0){
                r1[x++] = s[i];
            }
            i = i+k-1;
        }
    }
    r1[x] = r2[y] = '\0';
    printf("%s\n%s",r1,r2);
    return 0;
}