class LRUCache {
public:
    int cap;
    list<pair<int,int>> lruList;
    unordered_map<int,list<pair<int,int>>::iterator> cache;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (cache.find(key)==cache.end()) return -1;
        //move to front as most recently used
        auto it=cache[key];
        int value=it->second;
        lruList.erase(it);
        lruList.push_front({key,value});
        cache[key]=lruList.begin();
        return value;

    }
    
    void put(int key, int value) {
        if (cache.find(key)!=cache.end())
            lruList.erase(cache[key]); //key exists, erase old (MRU)
        else if (lruList.size()==cap)
        {
            //capacity full - evict least recently used (back)
            auto lru=lruList.back();
            cache.erase(lru.first);
            lruList.pop_back();
        }
        //insert new at front
        lruList.push_front({key,value});
        cache[key]=lruList.begin();
    }
};

//list lets us insert/remove etc in O(1) time using iterators. lruList maintains the order of recently used keys (front - most, back - least). The map tells us where a key is in the list - the key is the key of the cache entry and value is an iterator pointing to where this key is stored in the list

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 /*
class LRUCache {
public:
    vector<vector<int>> cache;
    int cap;
    int LRU=0;

    LRUCache(int capacity) {
        cap=capacity;
        cache.resize(capacity,vector<int>(2));
        for (int i=0;i<capacity;i++)
        {
            cache[i][0]=-1;
            cache[i][1]=-1;
        }
    }
    
    int get(int key) {
        for (int i=0;i<cache.size();i++)
            if (cache[i][0]==key)
            {
                int val=cache[i][1];
                cache.erase(cache.begin()+i); //move it to the end (most recently used)
                cache.push_back({key,val});
                return val;
            }   
        return -1;
    }
    
    void put(int key, int value) {
        for (int i=0;i<cache.size();i++)
            if (cache[i][0]==key)
            {
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        if (cache.size()==cap)
            cache.erase(cache.begin()); //remove LRU
        cache.push_back({key,value}); //recent
    }
};
 */