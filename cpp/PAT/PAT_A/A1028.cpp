/*
1028. List Sorting (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input
Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number 
of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a 
student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters 
without space), and grade (an integer between 0 and 100, inclusive).

Output
For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order 
according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records 
must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must 
be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90

Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60

Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    int ID;
    string name;
    int grade;
}s[100001];

bool cmp1(student s1,student s2){
    return s1.ID < s2.ID;
}

bool cmp2(student s1,student s2){
    if(s1.name == s2.name) return s1.ID < s2.ID;
    return s1.name < s2.name;
}

bool cmp3(student s1,student s2){
    if(s1.grade == s2.grade) return s1.ID < s2.ID;
    return s1.grade < s2.grade;
}

int main(){
    int n, flag;
    cin >> n >> flag;
    for(int i = 0; i < n; i++){
        cin >> s[i].ID >> s[i].name >> s[i].grade;
    }
    switch(flag){
        case 1:sort(s,s+n,cmp1);
            break;
        case 2:sort(s,s+n,cmp2);
            break;
        case 3:sort(s,s+n,cmp3);
            break;
    }
    for(int i = 0; i < n; i++){
        printf("%06d %s %d\n",s[i].ID,s[i].name.c_str(),s[i].grade);
    }
    return 0;
}