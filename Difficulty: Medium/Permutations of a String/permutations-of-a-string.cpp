class Solution {
  public:
    void check(string &s, vector<int>& used, vector<string>& ans, string &temp) {
        if (temp.size() == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            // Skip already used characters
            if (used[i]) continue;

            // Skip duplicates — only use the first unused occurrence
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            used[i] = 1;
            temp.push_back(s[i]);
            check(s, used, ans, temp);
            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> ans;
        string temp = "";
        vector<int> used(s.size(), 0);

        sort(s.begin(), s.end()); // Important to handle duplicates

        check(s, used, ans, temp);
        return ans;
    }
};
