class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }
        int n = nums.size();
        nums.clear();
        for(auto i:map){
            if(i.second>n/3){
                nums.push_back(i.first);
            }
        }
        return nums;
    }
};
