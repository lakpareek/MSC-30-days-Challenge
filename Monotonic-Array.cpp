class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }
        int i = 0;
        int j = 1;

        while (j<nums.size() && nums[i] == nums[j]) {
            i++;
            j++;
        }
        if(j==nums.size()){
            return true;
        }
        bool isIncreasing = nums[i] > nums[j] ? false : true; 
        
        if (isIncreasing) {
            while (j < nums.size()) {
                if (nums[i] <= nums[j]) { 
                    i++;
                    j++;
                } else {
                    return false;
                }
            }
        } else {
            while (j < nums.size()) {
                if (nums[i] >= nums[j]) { 
                    i++;
                    j++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
