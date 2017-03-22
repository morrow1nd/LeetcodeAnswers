#include <cassert>

struct step {
    int pi;
    int si;
    int w;

    step(int pi, int si, int w)
        : pi(pi), si(si), w(w) {}
};


class Solution {
public:
    const char* s;
    const char* p;
    int slen;
    int plen;
    list<step> steps;
    
    bool isMatch(string _s, string _p){
        char * s = new char[_s.length() + 3];
        char * p = new char[_p.length() + 3];
        *p = '^';
        strcpy(s, _s.c_str());
        strcpy(p + 1, _p.c_str());
        strcpy(p + strlen(p), "$");
        bool res = match(p, s);
        delete[] s;
        delete[] p;
        return res;
    }

// copy from 《代码之美》
int match(char *regexp,char *text)  
{  
 if(regexp[0] == '^')  
  return matchhere(regexp+1,text);  
 do{ /*即使字符串为空也必须检查*/  
  if (matchhere(regexp,text))  
   return 1;  
 }while (*text++!= '\0');  
 return 0;  
}  
/*matchhere在text的开头查找regexp*/  
int matchhere(char *regexp,char *text)  
{  
 if (regexp[0] == '\0')  
  return 1;  
 if (regexp[1] == '*')  
  return matchstar(regexp[0],regexp+2,text);  
 if (regexp[0] == '$' && regexp[1]=='\0')  
  return *text == '\0';  
 if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))  
  return matchhere(regexp+1,text+1);  
 return 0;  
}  
/*matchstar :在text的开头查找C*regexp*/  
int matchstar (int c,char *regexp,char *text)  
{  
 do { /*通配符*匹配零个或多个实例*/  
  if (matchhere(regexp,text))  
   return 1;  
 }while (*text!='\0' && (*text++ ==c || c== '.'));  
 return 0;  
}  
    
    
private:
    // 我的版本：使用显示构造的栈，效率低下
    bool _isMatch(string _s, string _p) {
        s = _s.c_str();
        p = _p.c_str();
        slen = _s.length();
        plen = _p.length();
        steps.clear();

        int pi = 0, si = 0, w = 0; // will do

        for (;;) {
            if (pi == plen && si == slen)
                return true;

            bool has_next_step = goto_next_step(&pi, &si, &w);

            while (!has_next_step) {
                bool has_prev_step = go_back_to_prev_step(&pi, &si, &w);
                if (has_prev_step == false)
                    return false;
                has_next_step = goto_next_step(&pi, &si, &w);
            }
            // we go to next step now!
        }

        // can't goto here!
    }
    bool go_back_to_prev_step(int *pi, int *si, int *w) {
        if (steps.empty())
            return false; // has no prev step
        step prev = steps.back();
        steps.pop_back();
        *pi = prev.pi;
        *si = prev.si;
        *w = prev.w;
        return true;
    }
    bool goto_next_step(int *pi, int *si, int *w) {
        if (*pi == plen)
            return false; // no next step

        if (*pi + 1 == plen) {
            if (*si < slen && *w == 0 && (p[*pi] == '.' || p[*pi] == s[*si])) {
                steps.push_back(step(*pi, *si, 1));
                *pi += 1;
                *si += 1;
                return true;
            } else {
                return false;
            }
        }

        if (p[*pi + 1] == '*') {
            switch (*w) {
            case 0: {
                steps.push_back(step(*pi, *si, 1)); // will do
                *pi += 2;
                *w = 0;
                return true;
            }
            case 1: {
                if (*si < slen && (p[*pi] == '.' || p[*pi] == s[*si])) {
                    steps.push_back(step(*pi, *si, 2));
                    *pi += 2;
                    *si += 1;
                    *w = 0;
                    return true;
                } else {
                    return false;
                }
            }
            case 2: {
                if (*si < slen && (p[*pi] == '.' || p[*pi] == s[*si])) {
                    steps.push_back(step(*pi, *si, 3));
                    *si += 1;
                    *w = 0;
                    return true;
                } else {
                    return false;
                }
            }
            default:
                return false;
            }
        } else {
            // p[*pi + 1] != '*'
            if (*si < slen && *w == 0 && (p[*pi] == '.' || p[*pi] == s[*si])) {
                steps.push_back(step(*pi, *si, 1));
                *pi += 1;
                *si += 1;
                *w = 0;
                return true;
            } else {
                return false;
            }
        }
    }
};