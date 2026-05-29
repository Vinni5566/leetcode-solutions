class Solution {
public:
    struct Node {
        int child[26];
        int best;

        Node() {
            memset(child, -1, sizeof(child));
            best = -1;
        }
    };

    vector<Node> trie;

    bool better(int a, int b, vector<string>& words) {
        if (b == -1) return true;

        if (words[a].size() != words[b].size()) {
            return words[a].size() < words[b].size();
        }

        return a < b;
    }

    void updateBest(int node, int idx, vector<string>& words) {
        if (better(idx, trie[node].best, words)) {
            trie[node].best = idx;
        }
    }

    void insert(string& word, int idx, vector<string>& words) {
        int node = 0;
        updateBest(node, idx, words);

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];
            updateBest(node, idx, words);
        }
    }

    int query(string& word) {
        int node = 0;
        int ans = trie[0].best;

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                return ans;
            }

            node = trie[node].child[c];
            ans = trie[node].best;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.reserve(500005);
        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (string& q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};
