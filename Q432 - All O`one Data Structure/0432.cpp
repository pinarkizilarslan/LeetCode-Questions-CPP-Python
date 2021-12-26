class AllOne {
private:
    unordered_map<string, int> count;
    map<int, unordered_set<string>> strings;

public:
    AllOne() {
    }

    void inc(string key) {
        ++count[key];
        int temp = count[key];
        if (temp == 1)
            strings[1].insert(key);
        else {
            strings[temp-1].erase(key);
            if (strings[temp-1].empty())
                strings.erase(temp-1);
            strings[temp].insert(key);
        }
    }

    void dec(string key) {
        --count[key];
        int temp = count[key];
        if (temp == 0)
            count.erase(key);
        strings[temp+1].erase(key);
        if (strings[temp+1].empty())
            strings.erase(temp+1);
        if (temp)
            strings[temp].insert(key);
    }

    string getMaxKey() {
        if(!strings.empty())
            return *(*strings.rbegin()).second.begin();

        return "";
    }

    string getMinKey() {
        if(!strings.empty())
            return *(*strings.begin()).second.begin();

        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
