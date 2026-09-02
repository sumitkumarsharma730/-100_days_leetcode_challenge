class Solution {
    struct Node {
        int leftLen, rightLen, maxLen, size;
        char leftChar, rightChar;

        Node() {
            leftLen = rightLen = maxLen = size = 0;
            leftChar = rightChar = '#';
        }

        Node(char c) {
            leftLen = rightLen = maxLen = size = 1;
            leftChar = rightChar = c;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node left, Node right) {
        if (left.size == 0) return right;
        if (right.size == 0) return left;

        Node res;

        res.size = left.size + right.size;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.leftLen = left.leftLen;
        res.rightLen = right.rightLen;

        res.maxLen = max(left.maxLen, right.maxLen);

        if (left.rightChar == right.leftChar) {

            res.maxLen = max(
                res.maxLen,
                left.rightLen + right.leftLen
            );

            if (left.leftLen == left.size) {
                res.leftLen = left.size + right.leftLen;
            }

            if (right.rightLen == right.size) {
                res.rightLen = right.size + left.rightLen;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[idx] = c;
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, index, c);

            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};