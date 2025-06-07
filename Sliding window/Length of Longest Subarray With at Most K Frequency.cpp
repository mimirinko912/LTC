class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left=0, max_len = 0, n = nums.size();

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[left]]--;
                left++;
            }
            max_len = max(max_len, (i - left + 1));
        }
        return max_len;
    }
};
