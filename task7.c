/*
 * Условие: В массиве не более 10 чисел. После каждого элемента массива,
 * являющегося полным квадратом, вставить число, из которого этот квадрат
 * получен. Для проверки полного квадрата использовать целочисленный
 * алгоритм (функции pow и sqrt использовать нельзя).
 */
#include <stdio.h>

int square_root_if_exact(int value) {
    if (value < 0) {
        return -1;
    }
    if (value == 0) {
        return 0;
    }
    int root = 1;
    while (root <= value / root) {
        root++;
    }
    root--;
    if (root * root == value) {
        return root;
    }
    return -1;
}

int insert_square_roots(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int root = square_root_if_exact(a[i]);
        if (root >= 0) {
            for (int j = n; j > i + 1; j--) {
                a[j] = a[j - 1];
            }
            a[i + 1] = root;
            n++;
            i++;
        }
    }

    return n;
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
    int a[20] = {4, 3, 16, 0, 25, 7, 9, 2, 1, 36};
    int n = 10;
    n = insert_square_roots(a, n);
    print_array(a, n);
    return 0;
}
