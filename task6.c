/*
 * Условие: Удалить из массива все элементы с чётной суммой цифр.
 * Дополнительные массивы использовать нельзя. Вывести элементы массива
 * через пробел. Если массив пустой, вывести «EMPTY».
 */
#include <stdio.h>

int digit_sum(int value) {
    int sum = 0;
    if (value < 0) {
        value = -value;
    }
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int remove_even_digit_sum(int a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (digit_sum(a[i]) % 2 != 0) {
            a[j] = a[i];
            j += 1;
        }
    }
    return j;
}

void print_array(const int a[], int n) {
    if (n == 0) {
        printf("EMPTY\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    int a[] = {12, 13, 24, 5, 101, 77, 8, 39, 46, 2};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    n = remove_even_digit_sum(a, n);
    print_array(a, n);
    return 0;
}
