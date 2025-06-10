class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int max_count = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right]]++;
            max_count = max(max_count, count[s[right]]);

            if (right - left + 1 - max_count > k) {
                count[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }

        return result;

    }
};
