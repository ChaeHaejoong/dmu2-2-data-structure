#include <stdio.h>

#define MAX_VERTICES 50

typedef struct vertex *vertex_pointer;
struct vertex {
    int vertex_num;
    vertex_pointer link;
};

vertex_pointer graph[MAX_VERTICES];
int already_visited[MAX_VERTICES] = {
    0,
};

void dfs(int s) {
    vertex_pointer v;
    already_visited[s] = 1;
    printf("%d:: ", s);
    for (v = graph[s]; v != NULL; v = v->link) {
        if (already_visited[v->vertex_num] == 0) {
            dfs(v->vertex_num);
        }
    }
}
