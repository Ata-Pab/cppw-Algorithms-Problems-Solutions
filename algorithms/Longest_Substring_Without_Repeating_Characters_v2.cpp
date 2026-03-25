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

==== Fix ====

Last index where each character appeared

last_seen[256]

When we encounter a character again:
c = s[right]

We check:
last_seen[c]

If that index lies inside the current window, we jump the left pointer.

If a duplicate appears:
left = max(left, last_seen[c] + 1) // The max is critical because we must never move left backwards.

==== Demo ====
string: "pwwkew"

-> Step 1
right = 0
char = p
last_seen[p] = -1

Window:
[p]
length = 1

Update:
last_seen[p] = 0

-> Step 2
right = 1
char = w
last_seen[w] = -1

Window:

[p w]
length = 2

Update:
last_seen[w] = 1

-> Step 3 (duplicate)
right = 2
char = w
last_seen[w] = 1

So we move:

left = max(0, 1+1)
left = 2

Window becomes:

[w]

Update:

last_seen[w] = 2
-> Step 4
right = 3
char = k

Window:

[w k]
length = 2
-> Step 5
right = 4
char = e

Window:

[w k e]
length = 3
-> Step 6
right = 5
char = w
last_seen[w] = 2

Move left:

left = max(2, 2+1)
left = 3

Window:

[k e w]
length = 3
Final Answer
max length = 3

Substring:
wke


Time  : O(n)
Space : O(1)  (256 ASCII table)
*******************************************************************************/
#include <iostream>
#include <vector>

#define ASCII_SIZE 256

int main()
{
    std::string s;
    std::cin >> s;

    std::vector<int> last_seen(ASCII_SIZE, -1);

    int left = 0;
    int max_len = 0;

    for (int right = 0; right < s.length(); right++)
    {
        unsigned char c = s[right];

        if (last_seen[c] >= left)
        {
            left = last_seen[c] + 1;
        }

        last_seen[c] = right;

        int window_len = right - left + 1;

        if (window_len > max_len)
            max_len = window_len;
    }

    std::cout << max_len << std::endl;

    return 0;
}