class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i< m;i++){
            for(int j = 1;j<n;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }


        for(int i = 0; i< n;i++){

            for(int k = i;k<n;k++){

                unordered_map<int,int> mp ;
                mp[0] = 1;

                int sum = 0;

                for(int j = 0;j<m;j++){

                    sum += matrix[j][k];

                    if(i > 0) sum -= matrix[j][i-1];

                    count += mp[sum - target];

                    mp[sum]++;

                }
            }
        }
        return count;
    }
};
