class Solution {
    public:
        vector<string> reorderLogFiles(vector<string>& logs) {
            // Create two separate vectors: one for letter-logs, another for digit-logs
            vector<string> letterLog, digitLog;
    
            // Step 1: Separate letter-logs and digit-logs
            for (const string &log : logs) {
                int pos = log.find(' ') + 1;  // Find the position after the first space (where the content starts)
                
                // Check if the first character of the content is a letter
                if (isalpha(log[pos])) {
                    letterLog.push_back(log);  // Store letter-log separately
                } else {
                    digitLog.push_back(log);   // Store digit-log separately
                }
            }
    
            // Step 2: Sort letter-logs using a custom comparator
            sort(letterLog.begin(), letterLog.end(), [](const string &log1, const string &log2) {
                // Find the first space to separate the identifier from the content
                int pos1 = log1.find(' ');
                int pos2 = log2.find(' ');
    
                // Extract content (everything after the identifier)
                string content1 = log1.substr(pos1 + 1);
                string content2 = log2.substr(pos2 + 1);
    
                // Primary sorting criteria: Sort by content
                if (content1 == content2) {
                    return log1 < log2;  // If content is the same, sort by the identifier (log1 < log2)
                }
    
                return content1 < content2;  // Otherwise, sort lexicographically by content
            });
    
            // Step 3: Merge sorted letter-logs with digit-logs (digit-logs remain in their original order)
            letterLog.insert(letterLog.end(), digitLog.begin(), digitLog.end());
    
            return letterLog;  // Return the reordered logs
        }
    };