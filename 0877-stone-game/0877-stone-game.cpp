// Even Simpler Solution

// For LeetCode 877, there is a mathematical observation:

// Number of piles is even.
// Total stones are odd.
// Alice can always choose either all even-indexed piles or all odd-indexed piles, whichever has the larger total.

// Therefore, Alice always wins, so the official shortest solution is:

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};