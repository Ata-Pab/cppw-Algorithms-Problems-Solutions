/******************************************************************************
Given a string s, find the length of the longest substring without repeating characters.

Input:  "abcabcbb"
Output: 3
Explanation: "abc"

Input:  "bbbbb"
Output: 1
Explanation: "b"

Input:  "pwwkew"
Output: 3
Explanation: "wke"

Constraints

1 ≤ n ≤ 100000
ASCII input

Required complexity
O(n)

Approach
Sliding Window

======> Modify the algorithm to also return the substring itself, not just its length.

Input
pwwkew

Output
wke


Time  : O(n)
Space : O(1)
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

#define ASCII_SIZE 256

int main()
{
    std::string s;
    std::cin >> s;

    std::vector<int> last_seen(ASCII_SIZE, -1);

    int left = 0;
    int max_len = 0;
    // To get substring
    int best_start_ix = -1;

    for (size_t right = 0; right < s.length(); right++)
    {
        unsigned char c = s[right];

        if (last_seen[c] >= left) // eliminate the risk of moving the window backwards
        {
            left = last_seen[c] + 1;
        }

        last_seen[c] = right;

        int window_len = right - left + 1;

        if (window_len > max_len)
        {
            max_len = window_len;
            best_start_ix = left;
        }
    }

    std::string out = s.substr(best_start_ix, max_len);

    std::cout << out << std::endl;
    std::cout << max_len << std::endl;

    return 0;
}