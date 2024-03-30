#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x);

int main(void) {
    int* input_num = malloc(sizeof(int));

    printf("Number: ");
    scanf("%i", input_num);

    if (isPalindrome(*input_num)) {
        printf("%i is a palindrome\n", *input_num);
    } else {
        printf("%i is not a palindrome\n", *input_num);
    }

    free(input_num);
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long int n = x, reverse = 0;
    int remainder = 0;

    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    if (x == reverse) {
        return true;
    }

    return false;
}