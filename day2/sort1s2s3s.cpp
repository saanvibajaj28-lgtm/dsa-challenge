class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low=0;
        int mid =0;
        int high=nums.size();

        while(low<=high){
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
             else if (nums[mid] == 1) {
                mid++;
            }
              else {
                swap(nums[mid], nums[high]);
                high--;
            }
            for(int val:nums){
                cout<<nums;
            }
        }
       
    }
};


