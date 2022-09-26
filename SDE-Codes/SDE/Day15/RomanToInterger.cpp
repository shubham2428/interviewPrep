#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        if(s.empty()) return 0;
        
        unordered_map<char,int> roman = 
        { 
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 } 
        };
        
        int sum = 0;
        
        for(int i = 0 ; i < s.length() -1 ; ++i)
        {
            if(roman[s[i]] < roman[s[i + 1]])
            {
                sum = sum - roman[s[i]];
            }
            else
            {
                sum = sum + roman[s[i]];
            }  
        }
        
        sum = sum + roman[s.back()];
        
        return sum;
    }
};