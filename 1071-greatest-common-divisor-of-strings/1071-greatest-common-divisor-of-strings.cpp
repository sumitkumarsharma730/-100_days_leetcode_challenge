// Time  -> O(m+n)
// space -> O(m+n)(due to string concatenation)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len = gcd(str1.size(), str2.size());

        return str1.substr(0, len);
    }
};