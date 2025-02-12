class Solution {
    public:
        // Function to find the median of two sorted arrays
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();  // Size of first array
            int n2 = nums2.size();  // Size of second array
            int n = n1 + n2;        // Total elements in merged arrays
             
            // Ensure binary search is performed on the smaller array for efficiency
            if(n1 > n2){
                return findMedianSortedArrays(nums2, nums1); // Swap arrays to keep nums1 smaller
            }
            
            int partition = (n + 1) / 2;  // The partition index to split arrays into left and right halves
    
            // Handle edge cases where one of the arrays is empty
            if(n1 == 0) {
                // If nums1 is empty, simply find the median of nums2
                return n2 % 2 ? nums2[n2 / 2] : (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;
            }
                
            if(n2 == 0) {
                // If nums2 is empty, simply find the median of nums1
                return n1 % 2 ? nums1[n1 / 2] : (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;
            }
            
            // Binary search to find the correct partition
            int left1 = 0, right1 = n1; // Binary search bounds
            int cut1, cut2;             // Partition indices for nums1 and nums2
            int l1, r1, l2, r2;         // Left and right partition elements
    
            while(left1 <= right1) {   
                cut1 = (left1 + right1) / 2;   // Midpoint partition in nums1
                cut2 = partition - cut1;       // Complementary partition in nums2
        
                // Assign left and right elements for partitioning
                l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]; // Left part of nums1
                l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1]; // Left part of nums2
                r1 = (cut1 >= n1) ? INT_MAX : nums1[cut1];    // Right part of nums1
                r2 = (cut2 >= n2) ? INT_MAX : nums2[cut2];    // Right part of nums2
                
                // If the partition is valid (all elements in left half are <= elements in right half)
                if (l1 <= r2 && l2 <= r1) {
                    return (n % 2) ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                // If partition is incorrect, adjust the search range
                else {
                    if (l1 > r2) {
                        right1 = cut1 - 1; // Move search space left
                    } else {
                        left1 = cut1 + 1;  // Move search space right
                    }
                }        
            }
            return 0.0;  // This should never be reached
        }
    };