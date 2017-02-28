class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] != 0 && nums[i] != (i + 1)) {
                if (nums[i] == nums[nums[i] - 1]) {
                    nums[i] = 0;
                    ++i;
                } else {
                    int tem = nums[i];
                    nums[i] = nums[tem - 1];
                    nums[tem - 1] = tem;
                }
            } else {
                ++i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }

private:
    /* copy from https://discuss.leetcode.com/topic/65944/c-solution-o-1-space */
    /*
        这个解法是把nums里的元素当成一种tag，标记为负号之后就说明此处索引对应的数字是存在的。

        nums里的元素存放了两种信息，一种是原来的数值，另一种是此处索引对应的值存不存在。
    */
    vector<int> __findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};