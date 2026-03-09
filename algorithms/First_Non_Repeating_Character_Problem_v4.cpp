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

You may only scan the string once.
- Single pass: O(n) - You cannot do two passes.

Algorithm:

1. Increase frequency
2. Push char to queue if first seen
3. While queue front has freq > 1
       pop it
*******************************************************************************/

#include <iostream>
#include "queue.hpp"  // Basic custom data structures lib to be used for algorithm workspace

#define ASCII_SIZE 256 // Static memeory allocation for ASCII characters
#define MAX_CHARACTER 100000

typedef struct
{
    int index;
    int frequency;
} int_HashMap;

int main()
{
    char received_word[MAX_CHARACTER];
    DataStructures::Queue<unsigned char> queue;
    int_HashMap freq[ASCII_SIZE] = {0};

    std::cin >> received_word;

    // Count the frequency of each character in the string and assign them to a hashmap
    for (int i = 0; received_word[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)received_word[i];
        if (freq[c].frequency == 0)
        {
            freq[c].index = i;
            queue.enqueue(c);
        }
        freq[c].frequency += 1;

        // printf("Char index: %d, Index: %d, Freqeuncy: %d\n", c, freq[c].index, freq[c].frequency);
    }

    while(!queue.isEmpty())
    {
        unsigned char value = queue.dequeue(); // Pop from front FIFO

        if (freq[value].frequency == 1)
        {
            printf("%d\n", freq[value].index);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}

/*
- Complexity: O(n) + O(256)
*/