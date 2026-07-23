class LRUCache {
public:
    
    list<int> dll; 
    // In map we are storing [key,{address,value}]
    map<int,pair<list<int>::iterator,int>> cache; // ::iterator is datatype (which store address of the node in LL);
    int capacity;

    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    void makeMostRecentlyUsed(int key){
        dll.erase(cache[key].first); // delete that address
        dll.push_front(key); // push it into front ...so that it feels like most recently used elem are at front . so that we can remove from last !

        cache[key].first=dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }

        makeMostRecentlyUsed(key);
        return cache[key].second; // returning the value
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key].second=value;
            makeMostRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            cache[key]={dll.begin(),value};
            capacity--;
        }

        if(capacity < 0){
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */