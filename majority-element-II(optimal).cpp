//using the boyer moore algo

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;
        for(int num : nums){
            if(num1==num){
                count1++;
            }
            else if(num2 == num){
                count2++;
            }
            else if(count1 == 0){
                num1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        if (count(nums.begin(), nums.end(), num1) > nums.size() / 3) ans.push_back(num1);
        if (count(nums.begin(), nums.end(), num2) > nums.size() / 3) ans.push_back(num2);
        return ans;
    }
};
