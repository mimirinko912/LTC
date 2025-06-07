class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int div) {
        int count = 0,sum = 0 ;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i = 0;i < n;i++){
            sum  += nums[i];//4 9 9 7 4 5
            int re = ((sum % div)+div)%div;
            count += mp[re];

            mp[re]++;

        }
        return count;
    }
};
