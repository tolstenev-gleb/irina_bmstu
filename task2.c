/*
 * Условие: Целочисленный массив содержит максимум 15 элементов.
 * Найти индекс максимального элемента массива среди тех элементов,
 * произведение цифр которых отлично от нуля. Значение индекса вывести.
 */
#include <stdio.h>

int all_digits_nonzero(int value) {
    if (value < 0) {
        value = -value;
    }
    if (value == 0) {
        return 0;
    }
    while (value > 0) {
        if (value % 10 == 0) {
            return 0;
        }
        value /= 10;
    }
    return 1;
}

int find_index_max_with_nonzero_digits(const int a[], int n) {
    int index_max = -1;
    for (int i = 0; i < n; i++) {
        if (all_digits_nonzero(a[i]) &&
            (index_max == -1 || a[i] > a[index_max])) {
            index_max = i;
        }
    }

    return index_max;
}

int main(void) {
    int a[] = {12, 105, 88, 73, 9, 41, 30, 27, 6, 52};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    /* Индекс выводится с нуля; -1 означает, что подходящих элементов нет. */
    printf("%d\n", find_index_max_with_nonzero_digits(a, n));
    return 0;
}
