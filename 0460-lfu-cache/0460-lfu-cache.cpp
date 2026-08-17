class LFUCache {
public:

    struct Node {
        int key;
        int value;
        int freq;

        Node(int key, int value, int freq) {
            this->key = key;
            this->value = value;
            this->freq = freq;
        }
    };

    int cap;
    int size;

    // key -> iterator pointing to the node in freq list
    unordered_map<int, list<Node>::iterator> mp;

    // frequency -> list of nodes
    // Front = Most Recently Used
    // Back  = Least Recently Used
    map<int, list<Node>> freq;


    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }


    // Increase frequency of a key
    void makeMostFrequentlyUsed(int key) {

        auto it = mp[key];

        int value = it->value;
        int oldFreq = it->freq;

        // Remove node from old frequency list
        freq[oldFreq].erase(it);

        // If list becomes empty, remove frequency
        if (freq[oldFreq].empty()) {
            freq.erase(oldFreq);
        }

        // Increase frequency
        int newFreq = oldFreq + 1;

        // Insert at front of new frequency list
        freq[newFreq].push_front(
            Node(key, value, newFreq)
        );

        // Update iterator in map
        mp[key] = freq[newFreq].begin();
    }


    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];

        int value = it->value;

        // Accessing key increases frequency
        makeMostFrequentlyUsed(key);

        return value;
    }


    void put(int key, int value) {

        // Capacity is zero
        if (cap == 0) {
            return;
        }


        // Key already exists
        if (mp.find(key) != mp.end()) {

            auto it = mp[key];

            // Update value
            it->value = value;

            // Increase frequency
            makeMostFrequentlyUsed(key);

            return;
        }


        // Cache is not full
        if (size < cap) {

            size++;

            // New node always starts with frequency 1
            freq[1].push_front(
                Node(key, value, 1)
            );

            // Store iterator
            mp[key] = freq[1].begin();

            return;
        }


        // Cache is full
        // Remove LFU
        // If frequency is same, remove LRU

        auto &leastFreqList = freq.begin()->second;

        // Back = least recently used
        Node victim = leastFreqList.back();

        int keyToDelete = victim.key;

        // Remove from frequency list
        leastFreqList.pop_back();

        // If frequency list becomes empty
        if (leastFreqList.empty()) {
            freq.erase(freq.begin());
        }

        // Remove from hashmap
        mp.erase(keyToDelete);


        // Insert new node with frequency 1
        freq[1].push_front(
            Node(key, value, 1)
        );

        mp[key] = freq[1].begin();
    }
};