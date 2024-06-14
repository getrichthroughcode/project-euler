#include <iostream>
#include <vector>
#include <cstdlib>

int LengthOfRecurringFactor(int n) {
    std::vector<int> marker(n, 0);
    int out = 0;
    int Dividend = 1;
    int Remainder = 1;

    while (marker[Dividend % n] == 0) {
        out++;
        Remainder = Dividend % n;
        Dividend = 10 * Remainder;
        std::cout << Dividend / n << std::endl;
        marker[Remainder] = 1;
    }

    return out;
}

int main() {
    int n = 1000; // Example value of n
    int max = 0;
    int result = 0;

    for (int k = 2; k < n; k++) {
        int length = LengthOfRecurringFactor(k);
        if (max < length) {
            max = length;
            result = k;
        }
    }

    std::cout << "Longest recurring cycle is obtained for this integer: " << result << std::endl;

    return 0;
}
