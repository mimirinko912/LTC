class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long answer = 0;
        long long MOD = 1e9+7;

        vector<long long> prefix (n+2,0);

        for(int i = 0 ; i < n; i++) prefix[i+1] = (prefix[i] + strength[i] + MOD)%MOD;

        vector<long long> sumofprefix (n+2,0);

        for(int i = 0 ; i <= n; i++) sumofprefix[i+1] = (sumofprefix[i] + prefix[i] + MOD)%MOD;

        vector<int> leftmin (n,-1);
        vector<int> rightmin (n,n);

        stack<int> stk;

        for(int i = 0; i<n; i++){
            while(!stk.empty() && strength[i] < strength[stk.top()]){
                rightmin[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        stk = stack<int> ();

        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && strength[i] <= strength[stk.top()]){
                leftmin[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);

        }

        for(int i = 0; i < n;i++){
            int left = leftmin[i] + 1, right = rightmin[i];
            int llen = i - left + 1;
            int rlen = right - i;

            long long interval = ((((sumofprefix[right + 1] - sumofprefix[i + 1]  + MOD)%MOD) * llen) % MOD  * strength[i] ) % MOD;
            interval = (interval - ((((sumofprefix[i + 1] - sumofprefix[left]  + MOD)%MOD) * rlen) % MOD * strength[i]) % MOD + MOD ) % MOD;

            answer = (answer + interval + MOD)%MOD;
        }

        return answer;
    }
};
