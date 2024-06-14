package main

import (
    "fmt"
)

func LengthOfRecurringFactor(n int) int {
    marker := make([]int, n)
    out := 0
    Dividend := 1
    Remainder := 1

    for marker[Dividend%n] == 0 {
        out++
        Remainder = Dividend % n
        Dividend = 10 * Remainder
        fmt.Println(Dividend / n)
        marker[Remainder] = 1
    }

    return out
}

func main() {
    n := 1000 // Example value of n
    max := 0
    result := 0

    for k := 2; k < n; k++ {
        length := LengthOfRecurringFactor(k)
        if max < length {
            max = length
            result = k
        }
    }

    fmt.Printf("Longest recurring cycle is obtained for this integer: %d\n", result)
}
