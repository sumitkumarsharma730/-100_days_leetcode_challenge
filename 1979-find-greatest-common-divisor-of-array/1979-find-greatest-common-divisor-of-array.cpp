//Euclidean Algorithm
//The key idea is:

// gcd(a, b) = gcd(b, a % b)

// gcd(48,18) = gcd(18,12)
class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());

        return gcd(minimum, maximum);
    }
};