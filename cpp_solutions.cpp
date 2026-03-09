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
*******************************************************************************/
#include <iostream>
#include <list>

int main()
{
    // Get received word from user input
    std::string received_word;
    std::cin >> received_word;
    int len_substring = 0;

    // Sliding Window Approach

    for (size_t i = 0; received_word[i] != '\0'; i++)
    {

    }


    printf("Received word: %s\n", received_word.c_str());

    return 0;
}