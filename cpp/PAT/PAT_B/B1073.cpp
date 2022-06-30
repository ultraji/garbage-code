/*
1073 多选题常见计分法 （20 分）
批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且
没有选择任何错误选项，则得到 50% 分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助
老师批改多选题，并且指出哪道题的哪个选项错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一
道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的
正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给
出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情
况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后 1 位。最后输出错得最多的题目选项的信息，格式为：
错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号。如果有并列，则每行一个选项，按题目编号递增顺序输出；
再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例 1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例 1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例 2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例 2：
5.0
5.0
Too simple
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ti{
    int score, cnum, anum;
    int c[5];
}t[101];

string cstr[5] = {"-a", "-b", "-c", "-d", "-e"};

int main(){
    int n, m, anum, tmp[5], max = 0;
    char c;
    string s;
    map<string, int> mp;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> t[i].score >> t[i].cnum >> t[i].anum;
        for(int j = 0; j < t[i].anum; j++){
            cin >> c;
            t[i].c[c-'a'] = 1;
        }
    }
    getchar();
    for(int i = 0; i < n; i++){
        double score = 0.0;
        getline(cin, s);
        for(int j = 0, tn = 1; j < s.size(); j++){
            if(s[j] == '('){
                fill(tmp, tmp+5, 0);
            }
            if(s[j] >= 'a' && s[j] <= 'e'){
                tmp[s[j]-'a'] = 1;
            }
            if(s[j] == ')'){
                bool isMore = false;
                int cnt = 0;
                for(int k = 0; k < 5; k++){
                    if(t[tn].c[k] == 1 && tmp[k] == 1){
                        cnt ++;
                    }else if(t[tn].c[k] == 0 && tmp[k] == 1){
                        mp[to_string(tn)+cstr[k]] ++;
                        isMore = true;
                    }else if(t[tn].c[k] == 1 && tmp[k] == 0){
                        mp[to_string(tn)+cstr[k]] ++;
                    }
                }
                if(!isMore){
                    score += (cnt < t[tn].anum) ? 0.5*t[tn].score : t[tn].score;
                }
                tn ++;
            }
        }
        printf("%.1f\n", score);
    }
    vector<string> v;
    for(auto it : mp){
        if(it.second > max){
            v.clear();
            max = it.second;
            v.push_back(it.first);
        }else if(it.second == max){
            v.push_back(it.first);
        }
    }
    if(max == 0){
        printf("Too simple");
    }else{
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            printf("%d %s\n", max, v[i].c_str());
        }
    }
    return 0;
}