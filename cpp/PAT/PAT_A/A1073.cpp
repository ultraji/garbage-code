/*
1073 Scientific Notation （20 分）
Scientific notation is the way that scientists easily handle very large numbers or very 
small numbers. The notation matches the regular expression [+-][1-9].[0-9]+E[+-][0-9]+ 
which means that the integer portion has exactly one digit, there is at least one digit 
in the fractional portion, and the number and its exponent's signs are always provided 
even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the 
conventional notation while keeping all the significant figures.

Input Specification:
Each input contains one test case. For each case, there is one line containing the real 
number A in scientific notation. The number is no more than 9999 bytes in length and the 
exponent's absolute value is no more than 9999.

Output Specification:
For each test case, print in one line the input number A in the conventional notation, 
with all the significant figures kept, including trailing zeros.

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num, radix, expo;
    cin >> num;
    if(num[0] == '-'){
        cout << '-';
    }
    num.erase(0, 1);
    int e = num.find('E');
    int plot = num.find('.');
    radix = num.substr(0, e);
    expo = num.substr(e+2);
    int cnt = atoi(expo.c_str());
    if(num[e+1] == '-'){
        radix.erase(plot, 1);
        cout << "0.";
        for(int i = 0; i < cnt-1; i++){
            cout << '0';
        }
        cout << radix;
    }else {
        radix.erase(plot, 1);
        int af_plot = radix.size() - 1; // 小数点后的位数
        if(cnt >= af_plot){
            cout << radix.append(cnt - af_plot, '0');
        }else{
            cout << radix.insert(cnt+1, 1, '.');
        }
    }
    return 0;
}
