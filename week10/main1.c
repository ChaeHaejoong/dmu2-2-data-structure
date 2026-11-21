#include <stdio.h>

typedef struct {
    int id;
    double score;
} element;

int main(void) {
    int *pi, i = 100;
    pi = &i;
    *pi += 5;
    printf("%d\n", *pi);

    element *pe, e;
    e.id = 10;
    e.score = 90.5;
    pe = &e;
    pe->id += 1;
    pe->score += 5;
    printf("id: %d, score: %.2lf\n", pe->id, pe->score);

    return 0;
}
