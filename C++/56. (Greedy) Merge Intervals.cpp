class Solution {
    public:
        // Function to merge overlapping intervals
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            // Step 1: Sort intervals based on the start time (first element of each pair)
            sort(intervals.begin(), intervals.end());
    
            vector<vector<int>> merged; // Stores the merged intervals
    
            // Step 2: Iterate through each interval
            for (vector<int> interval : intervals) {
                // If merged is empty OR the current interval does not overlap with the last merged interval
                if (merged.empty() || merged.back()[1] < interval[0]) {
                    merged.push_back(interval);  // No overlap → Add new interval
                } else {
                    // Overlapping intervals → Merge by updating the end time
                    merged.back()[1] = max(merged.back()[1], interval[1]);
                }
            }
    
            return merged; // Return the final merged intervals
        }
    };