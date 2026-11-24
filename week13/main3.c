#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PNUM 100
typedef struct {
    long id;
    char name[20];
    unsigned score;
} PTYPE;

int bsearch_name(PTYPE a[], int n, char sname[20]);

int main(int argc, char *argv[]) {
    char sname[20];
    long sid;
    PTYPE plist[MAX_PNUM];
    FILE *pfile;
    int i = 0, n, sresult;

    if ((pfile = fopen(argv[1], "r")) == NULL) {
        printf("데이터 파일을 열 수 없습니다 \n");
        exit(1);
    }

    while (fscanf(pfile, "%ld%s%u", &(plist[i].id), plist[i].name,
                  &(plist[i].score)) != EOF) {
        i++;
    }
    n = i;

    printf("검색할 이름 입력: ");
    scanf("%s", sname);
    sresult = bsearch_name(plist, n, sname);
    if (sresult != -1)
        printf("%s님은 합격하셨습니다.\n", sname);
    else
        printf("%s님은 다음에 다시 응시하여 주시기 바랍니다.\n", sname);

    return 0;
}

int bsearch_name(PTYPE a[], int n, char sname[20]) {
    int mid;
    int left = 0, right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(sname, a[mid].name) > 0)
            left = mid + 1;
        else if (strcmp(sname, a[mid].name) < 0)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}
