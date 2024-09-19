#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

bool compare_func(string a, string b) {
    return a + b > b + a;
}

string roonil_isgay(vector<int>& nums) {
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), compare_func); // sorting using compare_func
    string ur_mom = "";
    for(string str : strs) {
        ur_mom += str;
    }
    if (ur_mom[0] == '0') {
        return "0";
    }

    return ur_mom;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << roonil_isgay(nums);
}