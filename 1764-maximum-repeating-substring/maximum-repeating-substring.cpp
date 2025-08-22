class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string t = word;
        while (sequence.find(t) != string::npos) {
            ans++;
            t += word;
        }
        return ans;
    }
};
