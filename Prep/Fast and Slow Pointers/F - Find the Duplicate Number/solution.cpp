int FindDuplicate(std::vector<int> nums){
  // Initialize the fast and slow pointers and make them point the first
  //  element of the array
  int fast = nums[0];
  int slow = nums[0];
  // PART 1: Traverse the array until an intersection point is found
  while(true){
    // Move the slow pointer using the nums[slow] flow
    slow = nums[slow];
    //  Move the fast pointer two times fast as the slow pointer using the 
    // nums[nums[fast]] flow  
    fast = nums[nums[fast]];
    // Break the loop when slow pointer becomes equal to the fast pointer, i.e., 
    /// if the intersection is found

    if (slow == fast){
      // if intersection point is found, break the loop
      break;
    }
  }
  // PART 2: 
  // Make the slow pointer point the starting position of an array again, i.e.,
  // start the slow pointer from starting position
  slow = nums[0];
  // Traverse in the array until the slow pointer becomes equal to the
  // fast pointer
  while (slow != fast){
    // Move the slow pointer using the nums[slow] flow
    slow = nums[slow];
    // Move the fast pointer slower than before, i.e., move the fast pointer
    // using the nums[fast] flow
    fast = nums[fast];
  }
  // return the fast pointer as it'll be pointing to the duplicate number in the array
  return fast;
}
// Driver code
int main() {
  std::vector<std::vector<int>> nums = {
    {1, 3, 2, 3, 5, 4},
    {2, 4, 5, 4, 1, 3},
    {1, 6, 3, 5, 1, 2, 7, 4},
    {1, 2, 2, 4, 3},
    {3, 1, 3, 5, 6, 4, 2}
  };

  for (int i = 0; i < nums.size(); i++){
    std::string input = "";
    for (int x: nums[i]){
      input += std::to_string(x) + ", ";
    }
    input = input.substr(0, input.size() - 2);
    std::cout << i + 1 << ".\tnums: [" << input << "]" << std::endl;
    std::cout << "\tDuplicate Number: " << FindDuplicate(nums[i]) << std::endl;
    std::cout << std::string(100,'-')<< std::endl;
  }
}
