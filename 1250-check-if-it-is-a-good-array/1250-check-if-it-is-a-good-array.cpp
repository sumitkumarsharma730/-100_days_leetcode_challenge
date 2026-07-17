// For integers a₁, a₂, ..., aₙ, there exist integers x₁, x₂, ..., xₙ such that:

// a₁x₁ + a₂x₂ + ... + aₙxₙ = gcd(a₁, a₂, ..., aₙ)

// This is the exact form of Bézouts Identity

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;

        for (int x : nums) {  // O(n)
            g = gcd(g, x);    // O(logM)
            if (g == 1)
                return true;
        }

        return false;
    }
};