/*
1071. Speech Patterns (25)
时间限制 300 ms
内存限制 65536 kB
代码长度限制 16000 B

People often have a preference among synonyms of the same word. For example, some may prefer 
"the police", while others may prefer "the cops". Analyzing such patterns can help to narrow 
down a speaker's identity, which is useful when validating, for example, whether it's still 
the same person behind an online avatar.Now given a paragraph of text sampled from someone's 
speech, can you find the person's most commonly used word?

Input Specification:
Each input file contains one test case. For each case, there is one line of text no more than 1048576 
characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical 
character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:
For each test case, print in one line the most commonly occurring word in the input text, followed by a 
space and the number of times it has occurred in the input. If there are more than one such words, print 
the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined 
as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the 
line beginning/end.
Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a can?  It can!"

Sample Output:
can 5
*/

#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    string str,s;
    map<string,int> mp;
    getline(cin,str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i = 0; i < str.size(); i++){
        if(isalnum(str[i])){
            s += str[i];
        }
        if(i == str.size() - 1 || !isalnum(str[i])){
            if(s != "") mp[s] ++;
            s = "";
        }
    }
    int max = 0;
    for(map<string,int>::iterator it = mp.begin();it != mp.end(); it++){
        if(it->second > max){
            str = it->first;
            max = it->second;
        }
    }
    cout << str << ' ' << max << endl;
    return 0;
}