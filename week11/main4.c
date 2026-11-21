#include <stdio.h>
#include <stdlib.h>
typedef struct BookNode {
    int bookNo;
    char title[100];
    char status;
    struct BookNode *llink;
    struct BookNode *rlink;
} BookNode;
BookNode *head = NULL;
void insertFront(BookNode *node, BookNode *book) {
    book->llink = node;
    book->rlink = node->rlink;
    node->rlink->llink = book;
    node->rlink = book;
}
void deleteBook(BookNode *book) {
    if (head == book) {
        printf("Deletion of head node not permitted.\n");
    } else {
        book->llink->rlink = book->rlink;
        book->rlink->llink = book->llink;
        free(book);
    }
}
void printBooks() {
    BookNode *book = head->rlink;
    while (book != head) {
        printf("도서 번호: %d\n", book->bookNo);
        printf("도서 제목: %s\n", book->title);
        printf("대출 여부: %c\n", book->status);
        printf("--------------------\n");
        book = book->rlink;
    }
}
int main(void) {
    BookNode *book;
    int i;
    head = (BookNode *)malloc(sizeof(BookNode));
    head->llink = head->rlink = head;
    for (i = 0; i < 3; i++) {
        book = (BookNode *)malloc(sizeof(BookNode));
        printf("도서 번호, 제목(공백 없이), 대출 여부(y/n) 입력: ");
        scanf("%d %s %c", &book->bookNo, book->title, &book->status);
        insertFront(head, book);
    }
    printf("\n[도서 등록 후 출력]\n");
    printBooks();
    deleteBook(head->rlink);
    printf("\n[첫번째 도서 삭제 후 출력]\n");
    printBooks();
    return 0;
}
