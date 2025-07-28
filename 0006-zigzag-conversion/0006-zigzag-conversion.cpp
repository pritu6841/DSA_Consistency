class Solution {
public:
    string convert(string s, int numRows) {
        int g = numRows + (numRows - 1); // Full cycle gap (down + up)
        if (numRows == 1) return s;      // Edge case: no zigzag
        
        string res;
        res.reserve(s.size());           // Reserve space for efficiency

        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                // Row 0: vertical heads
                for (int x = 0; x < s.size(); x += g - 1)
                    res.push_back(s[x]);
            } 
            else if (i == numRows - 1) {
                // Last row: vertical tails
                for (int x = 0; x + i < s.size(); x += g - 1)
                    res.push_back(s[x + i]);
            } 
            else {
                // Middle rows: each cycle gives 2 characters
                for (int x = 0; x < s.size() + g; x += g - 1) {
                    if (x - i >= 0 && x - i < s.size())
                        res.push_back(s[x - i]);
                    if (x + i < s.size())
                        res.push_back(s[x + i]);
                }
            }
        }

        return res;
    }
};