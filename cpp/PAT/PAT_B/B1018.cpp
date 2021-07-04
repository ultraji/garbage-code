/*
1018. 锤子剪刀布 (20)
大家应该都会玩“锤子剪刀布”的游戏。
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多
的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：
5 3 2
2 3 5
B B
*/

#include <iostream>
#include <map>
using namespace std;

char f[4] = {' ', 'J', 'C', 'B'}; 
map<char,int> mp = { pair<char, int>('J',1), pair<char, int>('C',2), pair<char, int>('B',3)};

int a_w[4], b_w[4], n, a_win, b_win;    // x_w数组存J，C，B赢的次数,x_win存总的赢的次数

int main(){
    char a, b, tmp;
    scanf("%d%c", &n, &tmp);
    for(int i = 0; i < n; i++){
        scanf("%c%c%c%c", &a, &tmp, &b, &tmp);
        if(mp[a] - mp[b] == -2 || mp[a] - mp[b] == 1){
            a_win ++;
            a_w[mp[a]] ++;
        }else if(mp[a] - mp[b] == 2 || mp[a] - mp[b] == -1){
            b_win ++;
            b_w[mp[b]] ++;
        }
    }
    printf("%d %d %d\n", a_win, n-a_win-b_win, b_win);
    printf("%d %d %d\n", b_win, n-a_win-b_win, a_win);
    // 将 x_win 作索引用
    a_win = 3;
    b_win = 3;
    for(int i = 2; i >= 1; i--){
        if(a_w[i] > a_w[a_win]){
            a_win = i;
        }
        if(b_w[i] > b_w[b_win]){
            b_win = i;
        }
    }
    printf("%c %c", f[a_win], f[b_win]);
    return 0;
}