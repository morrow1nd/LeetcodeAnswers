class Solution {
public:
    string _commonstr(string& s1, string& s2){
        if(s1.find(s2) == 0){
            return s2;
        }
        if(s2.find(s1) == 0)
            return s1;
            
        int end = std::min(s1.length(), s2.length());
        for(int i = 0; i < end; ++i){
            if(s1[i] != s2[i]){
                return s1.substr(0, i);
            }
        }
        return s1.length() < s2.length() ? s1 : s2;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1){
            return strs[0];
        }
        if(strs.size() == 2){
            return _commonstr(strs[0], strs[1]);
        }
        
        strs[strs.size() - 2] = _commonstr(strs[strs.size() - 1], strs[strs.size() - 2]);
        strs.pop_back();

        return longestCommonPrefix(strs);
    }
};