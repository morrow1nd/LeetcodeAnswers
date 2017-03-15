#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string& s) {
        stringstream ss;
        strlen = s.length();
        _decodeString(ss, s, 0);
        return ss.str();
    }
private:
    int strlen;
    int _decodeString(stringstream& ss, const string& s, int c) {
        for (int i = c; i < strlen; ) {
            if (isdigit(s[i])) {
                i = _handleRepeat(ss, s, i);
            } else if(s[i] == ']'){
                return i + 1;
            } else {
                ss << s[i++];
            }
        }
        return strlen;
    }
    int _handleRepeat(stringstream& ss, const string& s, int c) {
        int num = atoi(s.c_str() + c);
        const int begin = s.find('[', c);
        stringstream ssnew;
        const int end = _decodeString(ssnew, s, begin + 1);
        for(int i = 0; i < num; ++i){
            ss << ssnew.str();
        }
        return end;
    }
};