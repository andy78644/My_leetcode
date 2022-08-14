class Solution {
public:
    public:
    vector<vector<string>> getSeqs(string& word, string& beginWord, unordered_map<string,pair<bool,vector<string>>>& words) {
        if (beginWord == word) return {{beginWord}};
        vector<vector<string>> seqs;
        for (auto& w: words[word].second) {
            auto w_seqs = getSeqs(w,beginWord,words);
            for (auto& seq: w_seqs) seq.push_back(word);
            copy(w_seqs.begin(), w_seqs.end(), back_inserter(seqs));
        }
        return seqs;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,pair<bool,vector<string>>> words;
        // records whether the word has been visited, and all parents in the shortest paths from beginWord
        for (auto& s: wordList) words.insert({s,{false,{}}});
        // if (!words.count(endWord)) return {};
        
        vector<string> q = {beginWord};
        while (!q.empty()) {
            bool done = false;
            vector<string> newq;
            for (auto& w : q)
                words[w].first = true;
            for (auto& w : q) {
                auto word = w;
                for (auto& c : word) {
                    auto corig = c;
                    for (c = 'a'; c <= 'z'; ++c)
                        // now word is modified and w is the original
                        if (c != corig) {
                            auto it = words.find(word);
                            if (it != words.end() && !it->second.first) {
                                if (it->second.second.empty())
                                    newq.push_back(word);
                                it->second.second.push_back(w);
                                if (word == endWord) done = true;
                            }
                        }
                    c = corig;
                }
            }
            if (done) {
                q.clear(); newq.clear();
                return getSeqs(endWord,beginWord,words);
            }
            q = move(newq);
        }
        return {};
    }
};