#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
      unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
        
        if(s.size()!=t.size()){
            return false;
        }
        
        for(int i =0;i<s.size();i++){
            mp1[s[i]]++;
        }
        
        for(int i =0;i<t.size();i++){
            mp2[t[i]]++;
        }
        
        for(int i =0;i<s.size();i++){
            if(mp1[s[i]]!=mp2[s[i]]){
                return false;
            }
        }
        
        return true;
        
    }   
};