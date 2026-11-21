#include <stdio.h>
#define MAXSIZE 5

typedef struct {
    int job_num;
    char grade;
} element;
element queue[MAXSIZE];

int rear = 0;
int front = 0;

void caddq(element item) {
    rear = (rear + 1) % MAXSIZE;
    if (rear == front)
        printf("Queue is full");
    else
        queue[rear] = item;
}

element cdeleteq() {
    if (rear == front) {
        printf("Queue is Empty");
    } else {
        front = (front + 1) % MAXSIZE;
        return queue[front];
    }
}

int main(void) {
    int i, job_num, out, cond = 1;
    element temp;

    while (cond) {
        printf("완료한 작업 수는?: ");
        scanf("%d", &job_num);

        printf("작업번호와 작업상태 입력:\n");
        for (i = 0; i < job_num; i++) {
            scanf("%d %c", &temp.job_num, &temp.grade);
            caddq(temp);
        }

        printf("몇 개의 작업을 출고하시겠습니까?");
        scanf("%d", &out);
        for (i = 0; i < out; i++) {
            temp = cdeleteq();
            printf("%d\t%c\n", temp.job_num, temp.grade);
        }

        printf("front = %d :: rear = %d\n", front, rear);
        printf("작업의 입출력을 계속하시겠습니까?(0/1)");
        scanf("%d", &cond);
    }

    return 0;
}
