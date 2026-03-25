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
*******************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

/* The implementation below is not correct solution for all conditions. See v2 */
int main()
{
    std::vector<std::int32_t> nums = {4, 3, 1, 1, 1, 1, 2, 3}; // (can be negative), Result should be 5 for k_sum=3 condition
    uint32_t subtotal = 0;
    uint32_t k_sum = 3; // Desired sum for subarrays
    uint16_t left = 0;
    uint16_t right = 0;
    uint16_t max_subarrays = 0;

    while (right < nums.size())
    {
        subtotal = subtotal + nums[right];
        
        if (subtotal >= k_sum)
        {
            if (subtotal == k_sum)
            {
                max_subarrays++;
            }
            subtotal = 0;
            right = left + 1;
            left = right;
            continue;
        }

        right++;
    }

    std::cout << max_subarrays;
}