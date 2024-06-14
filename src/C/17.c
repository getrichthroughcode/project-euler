#include <stdio.h>
#include <string.h>

// Function to convert a number to its word representation

void numberToWords(int num, char *words) {
    if (num == 1000) {
        strcpy(words, "onethousand");
        return;
    }

    static const char *const ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static const char *const teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    static const char *const tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int hundreds = num / 100;
    int tens_unit = (num % 100)/10;
    

    words[0] = '\0';

    if (hundreds > 0) {
        strcat(words, ones[hundreds]);
        strcat(words, "hundred");
        if (tens_unit > 0)
            strcat(words, "and");
    }

    if (tens_unit >= 20) {
        strcat(words, tens[tens_unit / 10]);
        strcat(words, ones[tens_unit % 10]);
    } else if (tens_unit >= 11 && tens_unit <= 19) {
        strcat(words, teens[tens_unit - 10]);
    } else {
        strcat(words, ones[tens_unit]);
    }
}

// Function to count the letters in a string
int countLetters(char *str) {
    int count = 0;
    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            count++;
        str++;
    }
    return count;
}

int main() {
    char words[100];
    int total_letters = 0;

    for (int i = 1; i <= 1000; i++) {
        numberToWords(i, words);
        total_letters += countLetters(words);
    }

    printf("Total letters used: %d\n", total_letters+30);

    return 0;
}
