#include <stdio.h>
#include <stdbool.h>

// 判断一个数是否为水仙花数
bool isNarcissistic(int num) {
    int hundreds, tens, ones;
    // 分解百位、十位、个位数字
    hundreds = num / 100;
    tens = (num / 10) % 10;
    ones = num % 10;
    
    // 判断是否为水仙花数
    if (num == hundreds*hundreds*hundreds + tens*tens*tens + ones*ones*ones) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int i;
    printf("所有的3位水仙花数：\n");
    for (i = 100; i < 1000; i++) {
        if (isNarcissistic(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}