#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

int areAnagrams(char str1[], char str2[]) {
    int count1[MAX_CHAR] = {0};
    int count2[MAX_CHAR] = {0};
    int i;

    if (strlen(str1) != strlen(str2))
        return 0; // Different lengths can't be anagrams

    // Count frequency of each character in str1
    for (i = 0; str1[i] != '\0'; i++) {
        count1[str1[i] - 'a']++;
    }

    // Count frequency of each character in str2
    for (i = 0; str2[i] != '\0'; i++) {
        count2[str2[i] - 'a']++;
    }

    // Compare the frequency arrays
    for (i = 0; i < MAX_CHAR; i++) {
        if (count1[i] != count2[i])
            return 0; // Not anagrams
    }

    return 1; // Are anagrams
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2))
        printf("YES, the strings are anagrams.\n");
    else
        printf("NO, the strings are not anagrams.\n");

    return 0;
}
