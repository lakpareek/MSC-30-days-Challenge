class Solution {
private:
    void solve(vector<int>& digits, int n){
        if(n == 0){
            digits.insert(digits.begin(), 1);
            return;
        }
        if(digits[n-1] + 1 <= 9){
            digits[n-1] = digits[n-1] + 1;
        }
        else{
            digits[n-1] = digits[n-1] + 1 - 10;
            solve(digits, n - 1);
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        solve(digits, n);
        return digits;

    }
};