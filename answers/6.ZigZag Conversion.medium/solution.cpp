class Solution {
public:
    /*
     * First edit at 2017/02/18
     * this code is awful
     */
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        const char* c = s.c_str();
        static char* out = (char*)malloc(1024 * 4);
        static int out_size = 1024 * 4;
        if(s.length() >= out_size){
            free(out);
            out = (char*)malloc(s.length() + 1);
        }
        int oi = 0;
        
        bool tag = true;
        
        for(int i = 0; i < numRows; ++i){
            tag = true;
            for(int curr = i; curr < s.length() && curr >= 0; ){
                out[oi++] = (char)(c[curr]);
                if(i == 0 || i == numRows - 1){
                    curr += 2 * (numRows - 1);
                    continue;
                }
                if(tag){
                    curr += 2 * (numRows - i - 1);
                }else{
                    curr += 2 * (i);
                }
                tag = ! tag;
            }
        }
        out[s.length()] = '\0';
        string ret(out);
        return ret;
    }
};