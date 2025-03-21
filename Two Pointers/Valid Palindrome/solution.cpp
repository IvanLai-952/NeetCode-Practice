class Solution {
public:
    bool isPalindrome(string s) {
        string str=copystring(s);
        int mid=str.size()/2;

        if(str.size()==0||str.size()==1)
            return true;

        if(str.size()%2==0)
            str.insert(str.begin()+mid,' ');

        for(int i=0; i<=mid; i++){
            if(str[mid-i]!=str[mid+i])
                return false;
        }
        

        return true;
    }
private:
    string copystring(string s){
        string str;

        for(auto c: s){
            if(isdigit(c))
                str+=c;
            if(isalpha(c))
                str+=tolower(c);
        }

        return str;
    }
};