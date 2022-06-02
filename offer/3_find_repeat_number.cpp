class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> v = {0};
        v.resize(len);
        for(auto i :nums){
            if (v[i]) return i;
            v[i] += 1;
        }
        return 0;
    }
};

// Bad Solution
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto pos = std::unique(nums.begin(), nums.end()); 
        // unique pos及之后的数值无法确定,因为是覆盖型算法，后面数值平移覆盖重复数值
        return *pos;
    }
};