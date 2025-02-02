class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int left=0, ans=0, maxf=0;

        // find MAX Window
        for(int right=0; right<s.size(); right++){
            freq[s[right]-'A']++;  // add char frequency
            maxf=max(maxf, freq[s[right]-'A']);  // find max frequency

            while((right-left+1)-maxf>k){  // Larger than MAX Replace quota
                // Move start idx of the window
                freq[s[left]-'A']--;
                left++;
            }

            ans=max(ans, right-left+1);
        }

        return ans;
    }
};