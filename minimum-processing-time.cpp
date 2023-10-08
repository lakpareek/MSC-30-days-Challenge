class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        reverse(tasks.begin(), tasks.end());
        int ans = INT_MIN;
        for(int i = 0; i<processorTime.size(); i++){
            int maxTime = INT_MIN;
            int j = i*4;
            int temp = j + 4;
            while(j<temp){
                maxTime = max(maxTime, (processorTime[i] + tasks[j]));
                j++;
            }
            ans = max(ans, maxTime);
        }
        return ans;
    }
};
