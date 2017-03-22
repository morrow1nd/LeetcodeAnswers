class Solution {
public:
    int reverse(int x) {
        unsigned int ux = abs(x);
        
        unsigned int result = 0;
        unsigned int tem;
        unsigned int buf;
        unsigned int i;
        
        while(ux){
            buf = ux / 10;
            i = ux - ((buf << 3) + (buf << 1));
            
            tem = (result << 3) + (result << 1) + i;
            if(result & 0x80000000 
                || tem < result
                || (tem - i) / 10 != result
                )
                return 0;
            result = tem;
            ux = buf;
        }
        
        if(result & 0x80000000)
            return 0;
        return x > 0 ? result : - result;
    }
    
    /* https://discuss.leetcode.com/topic/6005/shortest-code-possible-in-c */
    int reverse_1(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};