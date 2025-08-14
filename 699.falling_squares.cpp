struct hcn{
    int left, right, height;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<hcn> cur_rec;
        vector<int> ans;
        int max_height = 0;

        for(auto &p : positions){
            int left = p[0];
            int sz = p[1];
            int right = left + sz;

            int pev_rec = 0;
            for(auto &pev_p : cur_rec){
                if(left < pev_p.right && right > pev_p.left){
                    pev_rec = max(pev_rec, pev_p.height);
                }
            }
            int new_height = pev_rec + sz;
            cur_rec.push_back({left, right, new_height});
            max_height = max(max_height, new_height);
            ans.push_back(max_height);
        }
        return ans;
    }
};