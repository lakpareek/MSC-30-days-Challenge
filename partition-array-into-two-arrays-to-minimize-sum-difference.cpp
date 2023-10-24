class Solution {
public:
     bool isSubsetSum(vector<int>&arr, int sum, vector<int>&v){
   int  n=arr.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
            for(int j=1;j<=sum;j++)
            {
                dp[0][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
         for(int i=0;i<sum/2+1;i++)
         {
             if(dp[n][i]==1)
             v.push_back(i);
         }
        return dp[n][sum];
    }
    int minimumDifference(vector<int>& nums) {
        vector<int>v;
        
             int n=nums.size(),mi=INT_MAX,sum=0;
         for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum<=0)
        {
         for(int i=0;i<n;i++)
             mi=min(mi,nums[i]);
          
         for(int i=0;i<n;i++)
             nums[i]+=abs(mi);
        }
        int sum2=0;
        for(int i=0;i<nums.size();i++)
            sum2+=nums[i];
        bool ans=isSubsetSum(nums,sum2,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size();i++)
         {
            if(sum2-2*v[i]<mini)
             mini=sum2-2*v[i];
         }
        return mini;
    }

};
