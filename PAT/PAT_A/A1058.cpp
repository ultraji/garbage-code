/*
1058. A+B in Hogwarts (20)
时间限制
50 ms
内存限制
65536 kB
代码长度限制
16000 B
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen 
silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B 
are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an 
integer in [0, 29)).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27

Sample Output:
14.1.28
*/

#include <iostream>
using namespace std;

int main(){
    int g1,s1,k1,g2,s2,k2,c1,c2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    c1 = (k1+k2)/29;
    k1 = (k1+k2)%29;
    c2 = (s1+s2+c1)/17;
    s1 = (s1+s2+c1)%17;
    g1 = g1+g2+c2;
    printf("%d.%d.%d",g1,s1,k1);
    return 0;
}