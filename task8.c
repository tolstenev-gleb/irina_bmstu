/*
 * Условие: Целочисленный массив содержит максимум 15 элементов.
 * Найти количество различных элементов в массиве и вывести его.
 */
#include <stdio.h>

int count_distinct(const int a[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int seen_before = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                seen_before = 1;
                break;
            }
        }
        if (!seen_before) {
            count++;
        }
    }

    return count;
}

int main(void) {
    int a[] = {4, 7, 4, 2, 9, 7, 1, 2, 5, 9, 3, 3, 8, 1, 6};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    printf("%d\n", count_distinct(a, n));
    return 0;
}
