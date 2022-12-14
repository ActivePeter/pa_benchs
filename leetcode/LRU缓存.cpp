#include "list"
#include "unordered_map"
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto find=quick_get.find(key);
        if(find==quick_get.end()){
            return -1;
        }
        
            // auto v=*find->second;
        auto value=find->second->second;
        auto end=find->second;
        end++;
        lru_queue.erase(find->second,end);
        lru_queue.push_back({key,value});
        end=lru_queue.end();
        end--;
        quick_get[key]=end;
        return value;
    }
    
    void put(int key, int value) {
        auto find=quick_get.find(key);
        if(find!=quick_get.end()){
            // auto v=*find->second;
            auto end=find->second;
            end++;
            lru_queue.erase(find->second,end);
        }
        
        lru_queue.push_back({key,value});
        auto end=lru_queue.end();
        end--;
        quick_get[key]=end;

        if(lru_queue.size()>cap){
            quick_get.erase(lru_queue.front().first);
            lru_queue.pop_front();
        }
    }
    unordered_map<int, list<pair<int,int>>::iterator> quick_get;
    list<pair<int,int>> lru_queue;
    int cap;
};

int main(){
    auto c=LRUCache(2);
    c.put(2,1);
    c.put(1,1);
    auto v=c.get(1);
    c.put(4,1);
    v=c.get(1);
    v=c.get(2);
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */