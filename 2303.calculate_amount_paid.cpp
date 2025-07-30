class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.0;
        int prevUpper = 0;

        for (const auto& bracket : brackets) {
            int upper = bracket[0];
            int percent = bracket[1];

            if (income <= prevUpper) break;

            int taxable = min(income, upper) - prevUpper;
            tax += taxable * (percent / 100.0);

            prevUpper = upper;
        }

        return tax;
    }
};
