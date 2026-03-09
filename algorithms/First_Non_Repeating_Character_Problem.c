/******************************************************************************
Given a string s, return the index of the first non-repeating character.
If none exists, return -1.

Input:  "leetcode"
Output: 0

Input:  "loveleetcode"
Output: 2

Input:  "aabb"
Output: -1


Constraints

- String length: 1 ≤ n ≤ 10^5
- Assume ASCII input (for now)
- Aim for better than O(n²)
*******************************************************************************/

#include <stdio.h>

#define MAX_CHARACTER 100000

int main()
{
    char received_word[MAX_CHARACTER];

    int non_repeating_char_ix = -1;

    scanf("%s", received_word); 
    
    for (unsigned int index = 0; index < MAX_CHARACTER; index++)
    {
        if (received_word[index] == '\0') { break; } // Break the loop, no waste looping
        
        for (unsigned int inner_index = 0; inner_index < MAX_CHARACTER; inner_index++)
        {
            if (received_word[inner_index] == '\0') { break; } // Break the inner loop, no waste looping
            if (inner_index == index) { continue; }
            
            if (received_word[index] == received_word[inner_index])
            {
                non_repeating_char_ix = -1;
                break;
            }
            else
            {
                non_repeating_char_ix = index;
            }
        }
        
        if (non_repeating_char_ix != -1)
        {
            break;
        }
    }
    
    printf("%d", non_repeating_char_ix);

    return 0;
}


/*
- Time Complexity: O(n²):
    - Outer loop:  O(n)
    - Inner loop:  O(n)

Too slow for production.

Expected optimal solution: O(n) time complexity, O(1) space complexity (since we are only dealing with ASCII characters, we can use a fixed-size array to count occurrences).
*/