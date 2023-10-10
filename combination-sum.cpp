class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &output, int i, int sum){
        if (sum == target) {
            ans.push_back(output);
            return;
        }

        if (i >= candidates.size() || sum > target) {
            return; 
        }
        //not include
        helper(candidates, target, ans, output, i+1, sum);
        output.push_back(candidates[i]);
        sum += candidates[i];
        //include
        helper(candidates, target, ans, output, i, sum);
        output.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        int sum = 0;
        helper(candidates, target, ans, output, i, sum);
        return ans;
    }
};
