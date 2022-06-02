class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto pos = std::find(nums.begin(),nums.end(), target);
        int count = 0;
        while(pos != nums.end()){
            count += 1;
            pos = std::find(pos+1, nums.end(), target);
        }
        return count;
    }
};