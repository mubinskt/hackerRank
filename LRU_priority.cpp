#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'simulatePriorityCache' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER capacity
 *  2. INTEGER numOperations
 *  3. STRING_ARRAY operationTypes
 *  4. INTEGER_ARRAY keys
 *  5. INTEGER_ARRAY values
 *  6. INTEGER_ARRAY priorities
 */

vector<int> simulatePriorityCache(int capacity, int numOperations, vector<string> operationTypes, vector<int> keys, vector<int> values, vector<int> priorities) 
{
    // return all get() values in order into a vector
    // vector<int> from get values
    
     
    // unorder_map<key, val>
    // unorder_map<key, priority>
    
    
    // for loop based on numoperations
    
    vector<int> retVect; 
    unordered_map<int, int> umapVal;
    unordered_map<int, int> umapPriority;
    deque<int> dqLRU; // O(n) for erase, so we should use a list<key> with unorderedmap<key, list<int>::iterator> pos;
    
    
    for(int i =0; i<numOperations; i++)
    {
        if(operationTypes[i] == "put")
        {
            if(umapVal.size() < capacity)
            {
                umapVal[keys[i]] = values[i];
                umapPriority[keys[i]] = priorities[i];
                dqLRU.push_back(keys[i]);
                //keys - 1,2,3,2used -,3,2
            }
            else 
            {
                int evictKey = dqLRU.front();
                dqLRU.pop_front();
                umapVal.erase(evictKey);
                umapPriority.erase(evictKey);
                
                
                // add new enteries
                umapVal[keys[i]] = values[i];
                umapPriority[keys[i]] = priorities[i];
            
            }
        }
        else if(operationTypes[i] == "get")
        {
            if(umapVal.find(keys[i]) == umapVal.end())
            {
                // ret -1 when no key present
                retVect.push_back(-1);
                continue;
            }
            
            retVect.push_back(umapVal[keys[i]]);
            
            auto it = std::find(dqLRU.begin(), dqLRU.end(), keys[i]);
            
            if (it != dqLRU.end()) {
                dqLRU.erase(it);
                    }
            
            dqLRU.push_back(keys[i]);
             
        }
        else if(operationTypes[i] == "updatePriority")
        {
            if(umapPriority.find(keys[i]) == umapVal.end())
            {
                continue;
            }
            umapPriority[keys[i]] = priorities[i];
            
            auto itPri = std::find(dqLRU.begin(), dqLRU.end(), keys[i]);
            
            if(itPri != dqLRU.end()){
                dqLRU.erase(itPri);
            }
            
            dqLRU.push_back(keys[i]);
        }
        
    }
    
    return retVect;
}

int main()
{
    string capacity_temp;
    getline(cin, capacity_temp);

    int capacity = stoi(ltrim(rtrim(capacity_temp)));

    string numOperations_temp;
    getline(cin, numOperations_temp);

    int numOperations = stoi(ltrim(rtrim(numOperations_temp)));

    string operationTypes_count_temp;
    getline(cin, operationTypes_count_temp);

    int operationTypes_count = stoi(ltrim(rtrim(operationTypes_count_temp)));

    vector<string> operationTypes(operationTypes_count);

    for (int i = 0; i < operationTypes_count; i++) {
        string operationTypes_item;
        getline(cin, operationTypes_item);

        operationTypes[i] = operationTypes_item;
    }

    string keys_count_temp;
    getline(cin, keys_count_temp);

    int keys_count = stoi(ltrim(rtrim(keys_count_temp)));

    vector<int> keys(keys_count);

    for (int i = 0; i < keys_count; i++) {
        string keys_item_temp;
        getline(cin, keys_item_temp);

        int keys_item = stoi(ltrim(rtrim(keys_item_temp)));

        keys[i] = keys_item;
    }

    string values_count_temp;
    getline(cin, values_count_temp);

    int values_count = stoi(ltrim(rtrim(values_count_temp)));

    vector<int> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item_temp;
        getline(cin, values_item_temp);

        int values_item = stoi(ltrim(rtrim(values_item_temp)));

        values[i] = values_item;
    }

    string priorities_count_temp;
    getline(cin, priorities_count_temp);

    int priorities_count = stoi(ltrim(rtrim(priorities_count_temp)));

    vector<int> priorities(priorities_count);

    for (int i = 0; i < priorities_count; i++) {
        string priorities_item_temp;
        getline(cin, priorities_item_temp);

        int priorities_item = stoi(ltrim(rtrim(priorities_item_temp)));

        priorities[i] = priorities_item;
    }

    vector<int> result = simulatePriorityCache(capacity, numOperations, operationTypes, keys, values, priorities);

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
