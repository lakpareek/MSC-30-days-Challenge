class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> x;
        for(char c:s){
            x[c]++;
        }
        for(char c:t){
            x[c]--;
            if(x[c] < 0){
                return c;
            }
        }
        return '\0';
    }
};
