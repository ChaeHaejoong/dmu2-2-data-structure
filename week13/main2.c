#include <stdio.h>
#include <stdlib.h>

#define INUM 5

int bsearch_stock(long s[][2], long key, int left, int right) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key > s[mid][0])
            left = mid + 1;
        else if (key < s[mid][0])
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

long stocksum(long s[][2], int n) {
    long sum = 0;
    int i;
    for (i = 0; i < n; i++)
        sum += s[i][1];
    return sum;
}

int main(int argc, char *argv[]) {
    FILE *stockdb;
    long stock[INUM][2], item_code;
    int k = 0, s;

    if ((stockdb = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open read file.. ..\n");
        exit(1);
    }
    while ((fscanf(stockdb, "%ld %ld", &stock[k][0], &stock[k][1])) != EOF) {
        printf("%ld\n", stock[k][0]);
        k++;
    }
    printf("검색할 item number 입력: ");
    scanf("%ld", &item_code);
    s = bsearch_stock(stock, item_code, 0, k - 1);
    if (s == -1)
        printf("재고물품이 없습니다\n");
    else
        printf("%ld의 재고개수 = %ld\n", stock[s][0], stock[s][1]);

    printf("전체 재고물품의 개수 합 = %ld\n", stocksum(stock, k));

    return 0;
}
