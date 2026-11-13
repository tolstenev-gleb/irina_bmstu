/*
 * Условие: Реализовать функцию циклического сдвига элементов массива
 * вправо на один элемент. С помощью функции поместить максимальный
 * элемент массива на последнее место. Если максимумов несколько,
 * на последнем месте должен оказаться первый. Вывести массив через пробел.
 */
#include <stdio.h>

void shift_right_one(int a[], int n) {
    int last = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = last;
}

void move_first_max_to_end(int a[], int n) {
    int index_max = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[index_max]) {
            index_max = i;
        }
    }
    for (int i = index_max; i < n - 1; i++) {
        shift_right_one(a, n);
    }
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
    int a[] = {4, 9, 2, 9, 7, 1, 5, 3, 9, 6};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    move_first_max_to_end(a, n);
    print_array(a, n);
    return 0;
}
