/******************************************************************************
Given an integer array nums and an integer k, return the number of subarrays whose sum equals k.

nums = [1,1,1]
k = 2

Output = 2

Explanation: The subarrays [1,1] (index 0-1) and [1,1] (index 1-2) sum to 2.

nums = [1,2,3]
k = 3

Output = 2

Explanation:
[1,2]
[3]

Cosntraints
1 ≤ n ≤ 100000
nums[i] can be negative

Required complexity
O(n)

HINT: Prefix Sums + Hash Map

==== FIX ====
Key identity:

sum(i..j) = prefix[j] - prefix[i-1]

We want:

prefix[j] - prefix[i-1] = k

Rearrange:

prefix[i-1] = prefix[j] - k

So for each position j, we count how many times we have seen:

prefix_sum - k

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> nums = {4, 3, 1, 1, 1, 1, 2, 3};
    int k = 3;

    std::unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;

    int prefix_sum = 0;
    int result = 0;

    for (auto &n : nums)
    {
        prefix_sum += n;

        if (prefix_count.find(prefix_sum - k) != prefix_count.end())
        {
            result += prefix_count[prefix_sum - k];
        }

        prefix_count[prefix_sum]++;
    }

    std::cout << result << std::endl;
}