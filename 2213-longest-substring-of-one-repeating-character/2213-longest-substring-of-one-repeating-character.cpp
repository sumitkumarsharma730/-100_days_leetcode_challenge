class Solution {
public:

    struct Node {
        int lmx, rmx, mx;

        Node(int x = 1) {
            lmx = rmx = mx = x;
        }
    };

    vector<Node> tree;
    string s;

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(1);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        merge(node, l, r);
    }

    void merge(int node, int l, int r) {

        int left = node * 2;
        int right = node * 2 + 1;

        tree[node].lmx = tree[left].lmx;
        tree[node].rmx = tree[right].rmx;

        tree[node].mx = max(tree[left].mx, tree[right].mx);

        int mid = (l + r) / 2;

        // Can join left suffix + right prefix
        if (s[mid] == s[mid + 1]) {

            tree[node].mx = max(
                tree[node].mx,
                tree[left].rmx + tree[right].lmx
            );

            // Entire left segment has same character
            if (tree[left].lmx == mid - l + 1) {
                tree[node].lmx += tree[right].lmx;
            }

            // Entire right segment has same character
            if (tree[right].rmx == r - mid) {
                tree[node].rmx += tree[left].rmx;
            }
        }
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            s[idx] = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        merge(node, l, r);
    }

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

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};