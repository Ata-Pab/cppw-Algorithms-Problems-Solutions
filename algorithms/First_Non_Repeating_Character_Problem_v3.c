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

New constraint

You may only scan the string once. The solution below is slightly violating 
this constraint even the functionality is correct. See v4 for full solution.
- Single pass: O(n) - You cannot do two passes.
*******************************************************************************/

#include <stdio.h>

#define ASCII_SIZE 256
#define MAX_CHARACTER 100000

typedef struct {
    int index;
    int frequency;
} _CharFrequencyHashMap;

int main()
{
    char received_word[MAX_CHARACTER];
    _CharFrequencyHashMap freq[ASCII_SIZE] = {0};
    int min_index = -1;

    scanf("%99999s", received_word);

    // Count the frequency of each character in the string and assign them to a hashmap
    for (int i = 0; received_word[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)received_word[i];
        if (freq[c].frequency == 0)
        {
            freq[c].index = i;
        }
        freq[c].frequency += 1;

        // printf("Char index: %d, Index: %d, Freqeuncy: %d\n", c, freq[c].index, freq[c].frequency);
    }


    // Traverse hasmap elements to find minimum index, do not     
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (freq[i].frequency == 1)
        {
            if (min_index == -1) // At least one unrepated char exists
            {
                min_index = MAX_CHARACTER;
            }

            if (min_index > freq[i].index)
            {
                min_index = freq[i].index;
            }
        }
    }

    printf("%d", min_index);

    return 0;
}


/*
- Complexity: O(n) + O(256)
*/