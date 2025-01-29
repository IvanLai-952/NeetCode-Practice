class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        vector<int> cnt(26);

        for(int i=0; i<s.size(); i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }

        for(auto val: cnt){
            if(val!=0)
                return false;
        }

        return true;
    }
};