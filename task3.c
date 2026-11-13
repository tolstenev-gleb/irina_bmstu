/*
 * Условие: Целочисленный массив содержит максимум 15 элементов.
 * Если все элементы массива являются числами Фибоначчи, вывести «YES»,
 * в противном случае вывести «NO».
 */
#include <stdio.h>

int is_fibonacci(int value) {
    if (value < 0) {
        return 0;
    }
    int previous = 0;
    int current = 1;
    if (value == 0) {
        return 1;
    }
    while (current < value) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current == value;
}

int all_are_fibonacci(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!is_fibonacci(a[i])) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int a[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    puts(all_are_fibonacci(a, n) ? "YES" : "NO");
    return 0;
}
