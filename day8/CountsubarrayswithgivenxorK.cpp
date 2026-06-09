class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
      int xr=0;
      map<int,int>mp;
      mp[xr]++;
      int cnt=0;
      for(int i=0;i<nums.size();i++){
xr = xr^nums[i];
int x = xr^k;
cnt += mp[x];
mp[xr]++;
      }  
        return cnt;
    }
  
};