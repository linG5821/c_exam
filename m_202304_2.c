#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10 // 循环队列的最大容量

// 队列结构体
typedef struct {
    char name[20]; // 患者姓名
    int front; // 队头指针
    int rear; // 队尾指针
    char queue[MAX_SIZE][20]; // 队列
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue q) {
    return q.front == q.rear;
}

// 判断队列是否已满
int isFull(Queue q) {
    return (q.rear + 1) % MAX_SIZE == q.front;
}

// 入队
void enQueue(Queue *q, char name[]) {
    if (isFull(*q)) {
        printf("队列已满，无法入队！\n");
        return;
    }
    strcpy(q->queue[q->rear], name);
    q->rear = (q->rear + 1) % MAX_SIZE;
}

// 出队
void deQueue(Queue *q) {
    if (isEmpty(*q)) {
        printf("队列为空，无法出队！\n");
        return;
    }
    printf("%s出队！\n", q->queue[q->front]);
    q->front = (q->front + 1) % MAX_SIZE;
}

int main() {
    //clion 存在的问题需要添加与题目无关
    setbuf(stdout, 0);

    Queue ytys, yz, kq; // 三个科室的队列
    initQueue(&ytys);
    initQueue(&yz);
    initQueue(&kq);

    int choice = 0;
    char name[20];

    while (1) {
        printf("请选择操作：\n");
        printf("1. 挂号\n");
        printf("2. 就诊\n");
        printf("3. 退出\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("请输入患者姓名：\n");
                scanf("%s", name);

                printf("请选择挂号科室：\n");
                printf("1. 牙体牙髓科\n");
                printf("2. 牙周科\n");
                printf("3. 口腔科\n");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        enQueue(&ytys, name);
                        break;
                    case 2:
                        enQueue(&yz, name);
                        break;
                    case 3:
                        enQueue(&kq, name);
                        break;
                    default:
                        printf("无效的选项！\n");
                        break;
                }
                break;
            case 2:
                if (!isEmpty(ytys)) {
                    deQueue(&ytys);
                }
                if (!isEmpty(yz)) {
                    deQueue(&yz);
                }
                if (!isEmpty(kq)) {
                    deQueue(&kq);
                }
                if (isEmpty(ytys) && isEmpty(yz) && isEmpty(kq)) {
                    printf("队列已经为空！\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("无效的选项！\n");
                break;
        }
    }
}