#include <stdio.h>
#include <string.h>

// Function to check if substring s1 is in s2
int isSubstring(char s2[], char s1[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i <= len2 - len1; i++) {
        int j;
        for (j = 0; j < len1; j++) {
            if (s2[i + j] != s1[j])
                break;
        }
        if (j == len1)
            return 1; // s1 is substring of s2
    }
    return 0; // not found
}

int main() {
    char str[100];
    printf("Enter a lowercase string: ");
    scanf("%s", str);
    
    int n = strlen(str);
    int possible = 0;

    // Try all possible splits into three parts: A, B, C
    // where A + B + C = str, each non-empty
    for (int i = 1; i < n - 1 && !possible; i++) {
        for (int j = i + 1; j < n && !possible; j++) {
            char A[100], B[100], C[100];
            
            // Extract substrings
            strncpy(A, str, i);
            A[i] = '\0';
            strncpy(B, str + i, j - i);
            B[j - i] = '\0';
            strcpy(C, str + j);

            // Check if one part is substring of both others
            if (isSubstring(A, B) && isSubstring(C, B)) {
                possible = 1;
            } else if (isSubstring(A, C) && isSubstring(B, C)) {
                possible = 1;
            } else if (isSubstring(B, A) && isSubstring(C, A)) {
                possible = 1;
            }
        }
    }

    if (possible)
        printf("YES, it's possible to split the string.\n");
    else
        printf("NO, it's not possible to split the string.\n");

    return 0;
}
