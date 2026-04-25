class LRUCache {
    private:
    int m_capacity;

    std::unordered_map<int, int> umap;

    std::list<int> list_key;

   std::unordered_map<int, std::list<int>::iterator>  umap_position;

public:
    LRUCache(int capacity) 
    {
        m_capacity = capacity;
    }

    int get(int key) 
    {
        if(umap.find(key) != umap.end())
        {
            // Nooo find it in list, use umap_position
            // remove existing - erase that key entry from list_key
            // push_back same key/ current_key
            
            list_key.erase(umap_position[key]);

            list_key.push_back(key);

            umap_position[key] = std::prev(list_key.end());

            // insted better approch below
            // auto it = list_key.insert(list_key.end(), key);
            // umap_position[key] = it;

            return umap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) 
    {
        if(umap.find(key) != umap.end())
        {
            umap[key] = value;

            // find it in list
            // remove existing - erase that key entry from list_key
            // push_back same key/ current_key
            auto it_pos =umap_position.find(key);

              if(it_pos != umap_position.end()){

                list_key.erase(it_pos->second);
              }
           
            list_key.push_back(key);

            umap_position[key] = prev(list_key.end());
            
                  

        }
        else
        {
            if(list_key.size() < m_capacity)
            {
            
                umap[key] = value;
            
                list_key.push_back(key);
                
                umap_position[key] = prev(list_key.end());

            }
            else
            {
                // remove least RU key
                int lruKey = list_key.front();
                list_key.pop_front();

                umap.erase(lruKey);
                umap_position.erase(lruKey);

                // add new key
                umap[key] = value;
            
                list_key.push_back(key);
                umap_position[key] = prev(list_key.end());
                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */