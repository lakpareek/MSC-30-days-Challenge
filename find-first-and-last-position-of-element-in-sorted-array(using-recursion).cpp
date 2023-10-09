//BAD CODE TOO MANY LINES. WILL TRY WRITING A BETTER VERSION OF IT TOM

class Solution {
public:
    int getMin(vector<int>& nums, int target, int s, int e, int mid){
        if(s==e){
            if(nums[s] == target){
                return s;
            }else{
                return -1;
            }
        }
        if(s>e){
            return -1;
        }
        if(nums[mid] == target){
            if(mid != 0 && nums[mid-1] == target){
                if(s == mid - 1){
                    return s;
                }
                int newMid = s + ((mid -1) - s)/2;
                return getMin(nums, target, s, mid - 1, newMid);
            }else{
                return mid;
            }
        }
        else if(nums[mid]<target){
            int newMid = (mid + 1) + (e-(mid + 1))/2;
            return getMin(nums, target, mid+1, e, newMid);
        }
        else if(nums[mid]>target){
            int newMid = s + ((mid - 1) - s)/2;
            return getMin(nums, target, s, mid - 1, newMid);
        }
        return -1;
    }
    int getMax(vector<int>& nums, int target, int s, int e, int mid){
        if(s==e){
            if(nums[s] == target){
                return s;
            }else{
                return -1;
            }
        }
        if(s>e){
            return -1;
        }
        if(nums[mid] == target){
            if(mid!= nums.size() - 1 && nums[mid+1] == target){
                if(e == mid + 1){
                    return e;
                }
                int newMid = (mid+1) + (e-(mid+1))/2;
                return getMax(nums, target, mid+1, e, newMid);
            }else{
                return mid;
            }
        }
        else if(nums[mid] == target && s>=e){
            return mid;
        }
        else if(nums[mid]<target){
            int newMid = (mid + 1) + (e-(mid + 1))/2;
            return getMax(nums, target, mid+1, e, newMid);
        }
        if(nums[mid]>target){
            int newMid = s + ((mid - 1) - s)/2;
            return getMax(nums, target, s, mid - 1, newMid);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);

        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        ans[0] = getMin(nums, target, s, e, mid);
        ans[1] = getMax(nums, target, s, e, mid);
        return ans;
    }
};
