class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
            return;
        }
        if (cache.size() == cap) {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
