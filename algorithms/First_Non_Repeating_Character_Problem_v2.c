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

#define ASCII_SIZE 256
#define MAX_CHARACTER 100000

int main()
{
    char received_word[MAX_CHARACTER];
    int freq[ASCII_SIZE] = {0};

    scanf("%99999s", received_word);

    // Count the frequency of each character in the string
    for (int i = 0; received_word[i] != '\0'; i++)
    {
        freq[(unsigned char)received_word[i]] += 1;
    }

    // Find first uniqeu
    for (int i = 0; received_word[i] != '\0'; i++)
    {
        if (freq[(unsigned char)received_word[i]] == 1)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("-1\n");

    return 0;
}


/*
- Time Complexity: O(n) where n is the length of the input string. We traverse the string twice: once to count frequencies and once to find the first non-repeating character.
- Space Complexity: O(1) since the frequency array has a fixed size of 256 for ASCII characters, regardless of the input string length.
*/