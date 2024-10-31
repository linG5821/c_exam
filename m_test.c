//
// Created by linG on 2023/10/17.
//
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // 标记当前趟是否有交换
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // 标记有交换
            }
        }
        // 输出每一趟排序结果
        printf("第 %d 趟排序结果: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // 如果这一趟没有交换，说明已经排好序
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {17, 18, 60, 40, 7, 32, 73, 65, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始序列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("排序后的序列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}