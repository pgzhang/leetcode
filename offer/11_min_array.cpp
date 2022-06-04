// Solution 1
class Solution {
public:
    int minArray(vector<int>& numbers) {
            auto it = std::min_element(numbers.begin(), numbers.end());
            return *it;
    }
};

// Solution 2
class Solution {
public:
    int minArray(vector<int>& numbers) {
            for(auto it=numbers.begin(); it!=numbers.end()-1; ++it){
                if(*it > *(it+1)){
                    return *(it+1);
                }
            }
            return numbers[0];
    }
};