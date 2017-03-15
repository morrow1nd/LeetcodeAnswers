/* === My explanation ===

## 1:  (a * b) % m = ((a % m) * (b % m)) % m
suppose:
  a = a1 * m + a2  (0 <= a2 < m)
  b = b1 * m + b2  (0 <= b2 < m)
so: (a * b)%m = (m*m*a1*b1 + (a1*b2 + a2*b1)m + a2*b2)%m = ((a%m) * (b%m))%m

## 2:  a^1234567 % m 
     = a^(1234560 + 7) % m 
     = (a^1234560 * a^7) % m
     = ((a^1234560 %m) * (a^7 %m)) % m      (from #1)

## 3: (a*m + b)^n %m = (b^n)%m
(a*m + b)^n = C(n,0)(a*m)^n + C(n,1)(a*m)^(n-1)*b + ... C(n,n)(a*m)^0 * b^n
(a*m + b)^n %m = b^n %m

## 4: (a^b)%m = ((a%m)^b)%m
(a^b)%m = ((a1*m + a2)^b)%m
        = (a2^b)%m                  (from #3)
        = ((a%m)^b)%m

## 5: a^1234560 % m
     = (a^123456)^10 %m
     = ((a^123456 %m)^10)%m         (from #4)
*/

// copied from https://discuss.leetcode.com/topic/50489/c-clean-and-short-solution
class Solution {
    const int base = 1337;
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};