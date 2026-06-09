class Solution{
public:
    int longestSubarray(vector<int> &nums, long long k){
        int left=0,right=0;
        long long sum=nums[0];
int maxlen=0;
int n=nums.size();
while(right<n){
    while(left<=right && sum>k){
        sum-=nums[left];
        left++;
            }
            if(sum==k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
            if(right<n){
                sum+=nums[right];
            }
}

return maxlen;
    }
};
