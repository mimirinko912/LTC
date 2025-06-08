class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int left=0,max_len=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;++i){

            while(nums[i]-nums[left] > 2 * k){
                ++left;
            }
            max_len=max(max_len,(i-left+1));
        }
        return max_len;
    }
};
