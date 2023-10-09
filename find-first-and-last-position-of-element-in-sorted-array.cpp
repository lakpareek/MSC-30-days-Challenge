class Solution {
public:
    int getmin(vector<int>& nums, int target){
        int minel = -1;
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s+e)/2;
        while(s<=e){
            if(nums[mid] == target){
                minel = mid;
                e = mid - 1;
            }
            else if(nums[mid] > target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = (s+e)/2;
        }
        return minel;
    }

    int getmax(vector<int>& nums, int target){
        int maxel = -1;
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s+e)/2;
        while(s<=e){
            if(nums[mid] == target){
                maxel = mid;
                s = mid+1;
            }
            else if(nums[mid] > target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = (s+e)/2;
        }
        return maxel;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(getmin(nums, target));
        ans.push_back(getmax(nums, target));
        return ans;
    }
};
