class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;

        for(char c : s) {
            if(c == '(') {
                cnt++;
                if(cnt > 1)
                    ans += c;
            }
            else {
                cnt--;
                if(cnt > 0)
                    ans += c;
            }
        }

        return ans;
    }
};