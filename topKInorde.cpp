#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getTopKFrequentEvents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY events
 *  2. INTEGER k
 */

vector<int> getTopKFrequentEvents(vector<int> events, int k) 
{
    
    // add to map, return first k elements from map
    // change it to priority queue
    
    
    std::unordered_map<int, int> umap_;
    
    auto cmp = [](const pair<int, int>& a,const pair<int,int>&b) {return a.second > b.second;};
    
    
    std::priority_queue<
    std::pair<int,int>, 
    std::vector<std::pair<int,int>>, 
    decltype(cmp)> pq(cmp);
    
    
    //map
    
    for(auto& event_ : events)
    {
        
        umap_[event_]++;
       
    }
    
    for(auto& m : umap_)
    {
        pq.push(m);
        
        if (pq.size() > k) 
        {
            pq.pop(); // maintain top k
        }
    }
    
    
    vector<int> retVec;
    
     
    unordered_set<int> used;
    
    while(!pq.empty())
    {
        auto [node, val] = pq.top();
        pq.pop();   
        
        
        
        //4,1,- 4,2
        
        // if (umap_[node] != val) {
        //         continue; 
        // }
        
        // if (used.count(node)) continue;
        
        retVec.push_back(node);
        //used.insert(node);
        
        if(retVec.size()>=k)
        {
            break;
        }
    }
    
    reverse(retVec.begin(), retVec.end());
    
    return retVec;
}

int main()
{
    string events_count_temp;
    getline(cin, events_count_temp);

    int events_count = stoi(ltrim(rtrim(events_count_temp)));

    vector<int> events(events_count);

    for (int i = 0; i < events_count; i++) {
        string events_item_temp;
        getline(cin, events_item_temp);

        int events_item = stoi(ltrim(rtrim(events_item_temp)));

        events[i] = events_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> result = getTopKFrequentEvents(events, k);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
