/*
1080 MOOC期终成绩 （25 分）
对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须
首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为
 G=(Gmid−term×40%+Gfinal×60%)，如果 Gmid−term > Gfinal；否则总评 G 就是 Gfinal。这里 Gmid−term 
 和 Gfinal分别为学生的期中和期末成绩。
现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：
输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考
试的学生数）。每个数都不超过10000。
接下来有三块输入。第一块包含 P 个在线编程成绩 Gp；第二块包含 M 个期中考试成绩 Gmid−term；第三块包含 N 个
期末考试成绩 Gfinal。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；
分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：
打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 Gp G​mid−term Gfinal G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到
整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81

输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct stu{
    string num;
    int Gp, Gm, Gf, G;
    bool operator < (stu s) const {
        if(G == s.G){
            return num < s.num;
        }
        return G > s.G;
    }
};

int main(){
    int p, m, n, g;
    string num;
    vector<stu> v;
    map<string, stu> mp;
    cin >> p >> m >> n;
    getchar();
    for(int i = 0; i < p; i++){
        cin >> num >> g;
        mp[num] = {num, g, -1, -1, -1};
    }
    for(int i = 0; i < m; i++){
        cin >> num >> g;
        mp[num].Gm = g;
    }
    for(int i = 0; i < n; i++){
        cin >> num >> g;
        mp[num].Gf = g;
    }
    for(auto it: mp){
        if(it.second.Gm > it.second.Gf){
            // Gf = -1 的情况不需要考虑，因为已经不及格了
            it.second.G = 0.4 * it.second.Gm + 0.6 * it.second.Gf + 0.5;
        }else{
            it.second.G = it.second.Gf;
        }
        v.push_back(it.second);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i].G >= 60 && v[i].Gp >= 200){
            cout << v[i].num << ' ' << v[i].Gp << ' ' << v[i].Gm << ' ' \
                << v[i].Gf << ' ' << v[i].G << endl;
        }
    }
    return 0;
}