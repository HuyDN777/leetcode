class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> seenA(n + 1, false), seenB(n + 1, false), isCommon(n + 1, false);
        vector<int> result;
        int commonCount = 0;

        for(int i = 0; i < n; ++i) {
            int a = A[i], b = B[i];

            seenA[a] = true;
            seenB[b] = true;

            if(seenB[a] && !isCommon[a]) {
                ++commonCount;
                isCommon[a] = true;
            }

            if(seenA[b] && !isCommon[b]) {
                ++commonCount;
                isCommon[b] = true;
            }

            result.push_back(commonCount);
        }

        return result;
    }
};