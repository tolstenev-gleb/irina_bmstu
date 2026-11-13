/*
 * Условие: Реализовать функцию обращения (реверса) массива.
 * Использовать её для циклического сдвига массива на K позиций влево:
 * реверс первой части [0, K - 1], реверс второй части [K, n - 1],
 * затем реверс всего массива.
 */
#include <stdio.h>

void reverse(int a[], int left, int right) {
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
}

void shift_left(int a[], int n, int k) {
    k %= n;
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    reverse(a, 0, n - 1);
}

void print_array(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int k = 3;
    shift_left(a, n, k);
    print_array(a, n);
    return 0;
}
