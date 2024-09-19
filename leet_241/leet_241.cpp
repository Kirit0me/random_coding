#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> roonil_is_gay(string exp) {
    vector<int> urmom;

    if (exp.find_first_not_of("0123456789") == string::npos) {
        urmom.push_back(stoi(exp));
        return urmom;
    }

    for(int i{0}; i<exp.size(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            vector<int> left = roonil_is_gay(exp.substr(0, i));
            vector<int> right = roonil_is_gay(exp.substr(i+1));

            for(int l: left) {
                for(int r: right) {
                    if(exp[i] == '+') urmom.push_back(l+r);
                    if(exp[i] == '-') urmom.push_back(l-r);
                    if(exp[i] == '*') urmom.push_back(l*r);
                }
            }
        }
    }
    sort(urmom.begin(), urmom.end());
    return urmom;
}

int main() {
    string testing_urmom = "2*3-4*5";
    vector<int> I_AM_SO_ANNOYED_NOW_PLS_HELP_ME = roonil_is_gay(testing_urmom);
    for(int j: I_AM_SO_ANNOYED_NOW_PLS_HELP_ME)
        cout << j << ", ";
}

// Different Ways to Add Parentheses
// Medium
// Topics
// Companies
// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "23-45"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2(3-(45))) = -34 
// ((23)-(45)) = -14 
// ((2(3-4))5) = -10 
// (2((3-4)5)) = -10 
// (((23)-4)5) = 10
 

// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
// The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
// class Solution {
//     public List<Integer> diffWaysToCompute(String expression) {

//     }
// }