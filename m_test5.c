//
// Created by YOLO on 2024/4/23.
//
#include <stdio.h>
#include <string.h>

// 连接字符串的函数
void string_cat(char *str_1, char *str_2) {
    if (strlen(str_1) >= strlen(str_2)) {
        strcat(str_1, str_2);
    } else {
        strcat(str_2, str_1);
        strcpy(str_1, str_2);
    }
}

// 测试函数
int string_cat_test(char *str_1, char *str_2, char *correct_result) {
    char result[100]; // 假设结果字符串的最大长度为100
    string_cat(str_1, str_2);
    if (strcmp(str_1, correct_result) == 0) {
        return 1; // 返回1表示正确
    } else {
        return 0; // 返回0表示错误
    }
}

int main() {
    setbuf(stdout, 0);

    char str_1[100], str_2[100], correct_result[200]; // 用于存储输入字符串和正确结果字符串
    printf("请输入第一个字符串：");
    scanf("%s", str_1);
    printf("请输入第二个字符串：");
    scanf("%s", str_2);
    printf("请输入正确结果字符串：");
    scanf("%s", correct_result);

    // 使用switch语句输出运行结果
    switch (string_cat_test(str_1, str_2, correct_result)) {
        case 1:
            printf("运行正确\n");
        break;
        case 0:
            printf("运行错误\n");
        break;
        default:
            printf("未知错误\n");
        break;
    }

    return 0;
}