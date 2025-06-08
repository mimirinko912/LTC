int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefix_counter;
    prefix_counter[0] = 1;
    int curr_sum = 0;
    int count = 0;

    for (int num : nums) {
        curr_sum += num;

        if (prefix_counter.count(curr_sum - goal)) {
            count += prefix_counter[curr_sum - goal];
        }

        prefix_counter[curr_sum]++;
    }

    return count;
}
