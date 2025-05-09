class Solution {
    public:
        int minimumDifference(vector<int>& nums, int k) {
            cout << "Original nums: ";
            for (int n : nums) {
                cout << n << " ";
            }
            cout << "\nValue of k: " << k << endl << endl;
    
            // Edge Case
            if (k == 1) {
                cout << "Since k = 1, the min difference is 0." << endl;
                return 0;
            }
    
            // Sort Array
            mergeSort(nums, 0, nums.size() - 1);
    
            cout << "Sorted: ";
            for (int n : nums) {
                cout << n << " ";
            }
            cout << endl << endl;
    
            // Initialize minDiff
            int minDiff = INT_MAX;
    
            // Use Sliding Window
            for (int i = 0; i <= nums.size() - k; ++i) {
                int windowStart = nums[i];
                int windowEnd = nums[i + k - 1];
                int diff = windowEnd - windowStart;
    
                cout << "Window [" << i << " to " << i + k - 1 << "] -> (" << windowEnd << " - " << windowStart << ") = " << diff << endl;
    
                if (diff < minDiff) {
                    cout << "--> New minDiff found: " << diff << endl << endl;
                    minDiff = diff;
                }
            }
    
            // Return result
            cout << endl << "Final minimum difference: " << minDiff << endl;
            return minDiff;
    
        }
    
        void mergeSort(vector<int>& arr, int left, int right) {
            if (left >= right) {
                return;
            }
    
            int mid = left + (right - left) / 2;
    
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
    
            merge(arr, left, mid, right);
        }
    
        void merge(vector<int>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;
    
            vector<int> L(n1);
            vector<int> R(n2);
    
            for (int i = 0; i < n1; ++i) {
                L[i] = arr[left + i];
            }
            for (int j = 0; j < n2; ++j) {
                R[j] = arr[mid + 1 + j];
            }
    
            int i = 0;
            int j = 0;
            int k = left;
    
            while(i < n1 && j < n2) {
                if(L[i] <= R[j]) {
                    arr[k++] = L[i++];
                } else {
                    arr[k++] = R[j++];
                }
            }
    
            while (i < n1) {
                arr[k++] = L[i++];
            }
            while (j < n2) {
                arr[k++] = R[j++];
            }
        }
    
    };