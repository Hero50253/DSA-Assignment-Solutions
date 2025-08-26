#include <stdio.h>
#include <string.h>

// 1) Concatenate str2 to str1
void concatenate(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0';
}

// 2) Reverse a string
void reverse_string(char str[]) {
    int len = 0, i;
    char temp;
    while (str[len] != '\0') len++;
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 3) Delete all vowels from a string
void delete_vowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            str[j++] = c;
        }
        i++;
    }
    str[j] = '\0';
}

// 4) Sort array of strings alphabetically
void sort_strings(char arr[][20], int n) {
    char temp[20];
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// 5) Convert uppercase char to lowercase
char to_lowercase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}

int main() {
    // 1) Concatenate
    char str1[100] = "Hello, ";
    char str2[] = "World!";
    concatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // 2) Reverse
    char revStr[] = "Hello";
    reverse_string(revStr);
    printf("Reversed string: %s\n", revStr);

    // 3) Delete vowels
    char noVowels[] = "Hello World";
    delete_vowels(noVowels);
    printf("String without vowels: %s\n", noVowels);

    // 4) Sort strings
    char arr[5][20] = {"banana", "apple", "mango", "grape", "orange"};
    sort_strings(arr, 5);
    printf("Sorted strings:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    // 5) Uppercase to lowercase
    char ch = 'A';
    printf("Lowercase of %c is %c\n", ch, to_lowercase(ch));

    return 0;
}
