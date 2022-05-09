/*
1028 人口普查 （20 分）
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天
是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10^5]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文
字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人
没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

输出样例：
3 Tom John
*/


// old 和 young 不能初始化为0，而是应该初始化成第一个有效生日的person
#include <iostream>
#include <cstring>

#define FROM ("1814/09/06")
#define TO ("2014/09/06")

struct person{
    char name[6];
    char birthday[15];
}p[100002];

int main()
{
    int n, cnt = 0, old, young;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s", p[i].name, p[i].birthday);
        if(strncmp(FROM, p[i].birthday, 10) <= 0 && 
           strncmp(TO, p[i].birthday, 10) >= 0 ){
            cnt ++;
            if(cnt == 1){
                old = i;
                young = i;
            }
            if(strncmp(p[young].birthday, p[i].birthday, 10) < 0){
                young = i;
            }
            if(strncmp(p[old].birthday, p[i].birthday, 10) > 0){
                old = i;
            }
        }
    }
    if(cnt != 0){
        printf("%d %s %s", cnt, p[old].name, p[young].name);
    }else{
        printf("0");
    }
    return 0;
}
