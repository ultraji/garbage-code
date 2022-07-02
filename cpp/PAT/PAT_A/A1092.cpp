/*
1092 To Buy or Not to Buy （20 分）
Eva would like to make a string of beads with her favorite colors so she went to a small shop 
to buy some beads. There were many colorful strings of beads. However the owner of the shop 
would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop 
contains all the beads she needs. She now comes to you for help: if the answer is Yes, please 
tell her the number of extra beads she has to buy; or if the answer is No, please tell her the 
number of beads missing from the string.

For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to 
represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like 
to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra 
ones; yet the 2nd one is not since there is no black bead and one less red bead.

Input Specification:
Each input file contains one test case. Each case gives in two lines the strings of no more 
than 1000 beads which belong to the shop owner and Eva, respectively.

Output Specification:
For each test case, print your answer in one line. If the answer is Yes, then also output the 
number of extra beads Eva has to buy; or if the answer is No, then also output the number of 
beads missing from the string. There must be exactly 1 space between the answer and the number.

Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY

Sample Output 1:
Yes 8

Sample Input 2:
ppRYYGrrYB225
YrR8RrY

Sample Output 2:
No 2
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int need = 0, remain = 0;
    string s1, s2;
    map<char, int> m;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        if(m.find(s1[i]) == m.end()){
            m.insert(pair<char, int>(s1[i], 1));
        }else{
            m[s1[i]] ++;
        }
    }
    for(int i = 0; i < s2.size(); i++){
        if(m.find(s2[i]) == m.end()){
            need ++;
        }else{
            m[s2[i]] --;
            if(m[s2[i]] == 0){
                m.erase(s2[i]);
            }
        }
    }
    if(need == 0){
        for(auto it = m.begin(); it != m.end(); it++){
            remain += it->second;
        }
        cout << "Yes " << remain;
    }else{
        cout << "No " << need;
    }
    return 0;
}
