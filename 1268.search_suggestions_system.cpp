class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());

        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            vector<string> vec;
            for (string& product : products) {
                if (product.substr(0, prefix.length()) == prefix) {
                    vec.push_back(product);
                    if (vec.size() == 3) break; 
                }
            }
            result.push_back(vec);
        }

        return result;
    }
};
