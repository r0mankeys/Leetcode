// A program that takes in two string, s and t, and returns true if t is an anagram of s, and false otherwise.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Im thinking of using a hash table to store the frequency of each character in s and t
// Then I will compare the hash tables to see if they are equal

// Another smart solution that does not require me to create
// a hash table in C (which is long) 
// is to have every character in the alphabet map to a prime number
// then take the product of the prime numbers of each character in s and t
// if they are the same then they are anagrams

typedef unsigned long long ull;

int hash(char c);
bool is_anagram(char *s, char *t);

int hash(char c)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; ++i) 
    {
        if (alphabet[i] == c)
        {
            return primes[i];
        } else 
        {
            continue;
        }
    }
    return -1;
}

bool is_anagram(char *s, char *t)
{
    ull result_s = 1;
    ull result_t = 1;
    if (strlen(s) != strlen(t))
    {
        return false;
    }
    for (int i = 0; s[i] != '\0'; ++i)
    {
        result_s *= hash(s[i]);
        result_t *= hash(t[i]);
    }
    return result_s == result_t;
}

int main(int argc, char *argv[])
{
    char *test1_s = "anagram";
    char *test1_t = "nagaram";
    char *test2_s = "rat";
    char *test2_t = "car";
    char *test3_s = "a";
    char *test3_t = "ab";

    printf("Test 1: %s\n", is_anagram(test1_s, test1_t) ? "true" : "false"); // true
    printf("Test 2: %s\n", is_anagram(test2_s, test2_t) ? "true" : "false"); // false
    printf("Test 3: %s\n", is_anagram(test3_s, test3_t) ? "true" : "false"); // false

    return 0;
}

// This solution would work in a production environment.
// However there are some edge cases:
// 1. If the product of the prime numbers is too large, it will overflow
// 2. Non-alphabet characters will not be handled

// Time complexity: O(n)
// Space complexity: O(1)

// Aside from using a hash table I am happy with this solution
