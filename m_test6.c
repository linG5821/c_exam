//
// Created by YOLO on 2024/4/23.
//
#include <stdio.h>
#include <string.h>

// 定义结构体存储人员信息
struct Person {
    char id[19]; // 身份证号码
    char name[50]; // 姓名
    int age; // 年龄
};

int calcAge(struct Person people) {
    return  2024 - (((people.id[6] - '0') * 1000) + ((people.id[7] - '0') * 100)
    + ((people.id[8] - '0') * 10) + (people.id[9] - '0'));
}

// 找出年龄与身份证号码计算的年龄不一致的人员信息
void age_wrong(struct Person people[], int n, struct Person wrong_people[], int *count) {
    *count = 0;
    for (int i = 0; i < n; i++) {
        // 计算身份证号码中的年龄
        int id_age = calcAge(people[i]);
        if (id_age != people[i].age) {
            wrong_people[*count] = people[i];
            (*count)++;
        }
    }
}

// 计算所有人员的平均年龄
float average_age(struct Person people[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += people[i].age;
    }
    return (float)sum / n;
}

int main() {
    struct Person people[100]; // 最多存储100个人员信息
    struct Person wrong_people[100]; // 存储年龄与身份证号码不一致的人员信息
    int n = 0; // 记录输入的人员数量
    int wrong_count = 0; // 记录年龄与身份证号码不一致的人员数量

    // 从键盘输入人员信息，以' 0 N 0' 作为输入结束标志
    printf("请输入人员信息（身份证号码 姓名 年龄），以'0 N 0'作为结束标志：\n");
    while (1) {
        scanf("%s", people[n].id);
        if (strcmp(people[n].id, "0") == 0) break; // 输入'0'结束输入
        scanf("%s%d", people[n].name, &people[n].age);
        n++;
    }

    // 找出年龄与身份证号码计算的年龄不一致的人员信息并输出
    age_wrong(people, n, wrong_people, &wrong_count);
    printf("年龄与身份证不一致的有 %d 人，分别是：\n", wrong_count);
    for (int i = 0; i < wrong_count; i++) {
        printf("姓名：%s， 身份证号码：%s， 年龄：%d\n", wrong_people[i].name, wrong_people[i].id, wrong_people[i].age);
    }

    // 计算所有人员的平均年龄并输出
    printf("平均年龄: %.2f岁\n", average_age(people, n));

    return 0;
}
