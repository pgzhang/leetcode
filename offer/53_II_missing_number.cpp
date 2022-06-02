class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> v = {0};
        v.resize(len+1);
        for(auto i :nums){
            v[i] = 1;
        }
        auto it = std::find(v.begin(), v.end(), 0);
        return static_cast<int>(std::distance(v.begin(), it));
    }
};