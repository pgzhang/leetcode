class Solution {
public:
    string replaceSpace(string s) {
        auto pos = s.find(" ");
        
        while(pos != string::npos){
            s = s.replace(pos,1, "%20");
            pos = s.find(" ");
        }
        return s;
    }
};