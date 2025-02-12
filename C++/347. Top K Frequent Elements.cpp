class Solution {
    public:
        // Function to return the top k most frequent elements in an array
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // Edge case: If k equals the number of unique elements, return all elements
            if (k == nums.size()) {
                return nums;
            }
    
            // Step 1: Count frequency of each element using an unordered map (hash map)
            unordered_map<int, int> mp;
            for (int num : nums) {
                mp[num]++; // Increase the count of 'num' in the hash map
            }
    
            // Step 2: Create a max-heap (priority queue) to store elements based on frequency
            priority_queue<pair<int, int>> pq;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                pq.push(make_pair(it->second, it->first)); // (frequency, element)
                
                // Step 3: Maintain only the top k frequent elements
                if (pq.size() > (int)mp.size() - k) { 
                    res.push_back(pq.top().second); // Store the top element
                    pq.pop(); // Remove the element from the heap
                }
            }
    
            return res; // Return the top k frequent elements
        }
    };