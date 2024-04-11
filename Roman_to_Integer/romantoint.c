#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* string);

int main(void) {
    char* input_roman = malloc(15 * sizeof(char));

    printf("Roman number: ");
    scanf("%15s", input_roman);

    int output_int = romanToInt(input_roman);

    printf("Integer: %i\n", output_int);

    free(input_roman);
}

int romanToInt(char* string) {
    int value = 0;

    for (int i = 0, string_len = strlen(string); i < string_len; i++) {
        switch (string[i]) {
            case 'I':
                if (string[i + 1] &&
                    (string[i + 1] == 'V' || string[i + 1] == 'X')) {
                    value -= 1;
                } else {
                    value += 1;
                }

                break;

            case 'V':
                value += 5;
                break;

            case 'X':
                if (string[i + 1] &&
                    (string[i + 1] == 'L' || string[i + 1] == 'C')) {
                    value -= 10;
                } else {
                    value += 10;
                }

                break;

            case 'L':
                value += 50;
                break;

            case 'C':
                if (string[i + 1] &&
                    (string[i + 1] == 'D' || string[i + 1] == 'M')) {
                    value -= 100;
                } else {
                    value += 100;
                }

                break;

            case 'D':
                value += 500;
                break;

            case 'M':
                value += 1000;
                break;

            default:
                break;
        }
    }

    return value;
}
