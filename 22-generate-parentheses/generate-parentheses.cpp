class Solution {
public:

    bool valid(string s){
        int count = 0;

        for(char c : s){
            if(c == '(') count++;
            else count--;

            if(count < 0) return false;
        }

        return count == 0;
    }

    void generate(int n, string curr, vector<string>& ans){

        if(curr.length() == 2*n){
            if(valid(curr))
                ans.push_back(curr);
            return;
        }

        generate(n, curr + "(", ans);
        generate(n, curr + ")", ans);
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        generate(n, "", ans);

        return ans;
    }
};