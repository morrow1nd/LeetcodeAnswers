class Solution {
public:
    int next(const vector<int>& nums, int curr){
        for(int i = curr; i < nums.size() - 1; ++i){
            if(nums[i + 1] != nums[i])
                return i + 1;
        }
        return nums.size(); // end
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int size = nums.size();
        if(size < 3)
            return vector<vector<int>>();
            
        std::sort(nums.begin(), nums.end());
        
        list<vector<int>> out;
        
        int first, second, third, third_value;
        for(first = 0; first < size - 2 && nums[first] <= 0; first = next(nums, first)){
            third = size;
            for(second = first + 1; second < size - 1; second = next(nums, second)){
                third_value = - (nums[first] + nums[second]);
                if(nums[second + 1] > third_value)
                    break;
                third = std::lower_bound(nums.begin() + second + 1, nums.begin() + third, third_value) - nums.begin();
                if(third != size && nums[third] == third_value)
                    out.push_back({nums[first], nums[second], third_value});
            }
        }
        
        return vector<vector<int>>(out.begin(), out.end());
        //return out;
    }
};