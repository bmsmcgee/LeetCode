function minimumDifference(nums: number[], k: number): number {
    console.log("Original nums:", nums);
    console.log("Value of k:", k);

    // Edge Case
    if (k === 1) {
        console.log("Since k = 1, the minimum difference is 0.");
        return 0;
    }

    // Sort Array
    nums = mergeSort(nums);
    console.log("Sorted:", nums);

    // Initialize minDiff
    let minDiff = Infinity;

    // Use Sliding Window
    for (let i = 0; i < nums.length - k + 1; i++) {
        const windowStart = nums[i];
        const windowEnd = nums[i + k - 1];
        const currentDiff = windowEnd - windowStart;

        console.log(`Window [${i} to ${i + k - 1}] -> (${windowEnd} - ${windowStart}) = ${currentDiff}`);

        if (currentDiff < minDiff) {
            console.log(`--> New minDiff found: ${currentDiff}`);
            minDiff = currentDiff;
        }
    }

    // Return result
    console.log("Final minimum difference:", minDiff);
    return minDiff;
};

function mergeSort(arr: number[]): number[] {
    if (arr.length < 2) {
        return arr;
    }

    const mid = Math.floor(arr.length / 2);
    const left = mergeSort(arr.slice(0, mid));
    const right = mergeSort(arr.slice(mid));

    return merge(left, right);
}

function merge(left: number[], right: number[]): number[] {
    let result: number[] = [];
    let i = 0;
    let j = 0;

    while (i < left.length && j < right.length) {
        if (left[i] <= right[j]) {
            result.push(left[i++]);
        } else {
            result.push(right[j++]);
        }
    }
    return result.concat(left.slice(i)).concat(right.slice(j));
}