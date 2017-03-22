/*
 * @First write at 2017/02/16
 *   not better then https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
 *
 */

#define setbit(x,y) (x|=(1<<y))
#define clrbit(x,y) (x&=~(1<<y))

struct Type {
    unsigned int t[8];
    bool dirty;
    unsigned int sum;

    Type()
        : t({0}), sum(0)
    {}

    bool contain(Type& c) {
        if ((sum & c.sum) == 0) {
            return false;
        }
        for (int i = 0; i < 8; ++i) {
            if ((t[i] & c.t[i]) > 0)
                return true;
        }
        return false; // no chance to come here!
    }
    void sync() {
        sum = t[0] | t[1] | t[2] | t[3] | t[4] | t[5] | t[6] | t[7];
    }
    void add(const char c) {
        setbit(t[c / 32], c % 32);
        setbit(sum, c % 32);
    }
    void add_without_sync(const char c) {
        setbit(t[c / 32], c % 32);
    }
};

struct TypeTable {
    Type types[256];

    TypeTable() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 32; ++j) {
                setbit(types[i * 32 + j].t[i], j);
                types[i * 32 + j].sync();
            }
        }
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        static TypeTable typeTable;
        static auto& table = typeTable.types;

        const char * str = s.c_str();
        const int strlength = s.length();

        int begin = 0;
        int end = 0;
        Type type; // empty
        int length = 0;
        int max_length = 0;

        int i = 0;

        while (end < strlength) {
            if (type.contain(table[str[end]])) {
                for (i = end - 1; i >= begin; --i) {
                    if (str[i] == str[end])
                        break;
                }
                begin = i + 1;
                length = end - begin + 1;
                type = Type();
                for (int i = begin; i <= end; ++i) {
                    type.add_without_sync(str[i]);
                }
                type.sync();
            } else { // not found
                type.add(str[end]);
                ++length;
                if (length > max_length)
                    max_length = length;
            }
            ++end;
        }

        return max_length;
    }
};