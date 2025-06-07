class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i < n; i++)mp[nums[i]]++;

        int cpl = mp.size();
        mp.clear();
        int left = 0,count = 0;
        for(int i = 0 ;i<n;++i){
            mp[nums[i]]++;
            while(mp.size() == cpl){
                count += n - i;
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};
