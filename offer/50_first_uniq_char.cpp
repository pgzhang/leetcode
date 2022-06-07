class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        unordered_map<char, int> m; // unordered_map使用哈希实现，要快于map
        for(auto c:s){
            ++m[c];
        }
        for(auto c:s){
            if(m[c] == 1) return c;
        }
        return ' ';
    }    
};