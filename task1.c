/*
 * Условие: Целочисленный массив содержит максимум 15 элементов.
 * Подсчитать число элементов массива, которые являются степенями двойки.
 * Полученное число вывести на экран.
 */
#include <stdio.h>

int count_powers_of_two(const int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int power = 1;
        while (power < a[i]) {
            power *= 2;
        }
        if (power == a[i]) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int a[] = {1, 3, 4, 8, 10, 16, 0, 32, 7, 64};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    printf("%d\n", count_powers_of_two(a, n));
    return 0;
}
