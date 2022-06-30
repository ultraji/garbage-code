/*
1041. Be Unique (20)
时间限制 100 ms
内存限制 65536 kB
代码长度限制 16000 B
Being unique is so important to people on Mars that even their lottery is designed in 
a unique way. The rule of winning is simple: one bets on a number chosen from [1, 104]. 
The first one who bets on a unique number wins. For example, if there are 7 people 
betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:
Each input file contains one test case. Each case contains a line which begins with a 
positive integer N (<=105) and then followed by N bets. The numbers are separated by 
a space.

Output Specification:
For each test case, print the winning number in a line. If there is no winner, print 
"None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31

Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
*/
#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    int haxi[10000],num[100000],n;
    while(cin >> n){
        memset(num,0,sizeof(int)*100000);
        memset(haxi,0,sizeof(int)*10000);
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            haxi[num[i]] ++;
        }
        int i = 1;
        for(; i <= n; i++){
            if(haxi[num[i]] == 1){
                cout << num[i] << endl;
                break;
            }
        }
        if(i == n+1){
            cout << "None" << endl;
        }
    }
    return 0;
}