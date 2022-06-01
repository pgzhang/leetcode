class Solution {
public:
    string reverseLeftWords(string s, int n) {
        std::reverse(s.begin(), s.begin()+n);
        std::reverse(s.begin()+n, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};