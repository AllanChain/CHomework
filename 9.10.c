#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    int score;
    struct Student *next;
};

void print_stu(struct Student *a) {
    while (a) {
        printf("student %10d: %10d\n", a->id, a->score);
        a = a->next;
    }
}
void cmp_swap(struct Student* a) {
    struct Student *n=a->next, *nn=a->next->next;
    if (n->id > nn->id) {
        a->next=nn;
        n->next=nn->next;
        nn->next=n;
        printf("%d %d %d\n", a->id, a->next->id, a->next->next->id);
    }
}
struct Student* comb_sort(struct Student* a, struct Student* b) {
    struct Student *p=a, *end=NULL, *head=a;
    while (p->next) p=p->next;
    p->next = b;
    while (head->next->next != end) {
        p = head;
        printf("%d\n", p->id);
        while (p->next->next != end) {
            cmp_swap(p);
            p=p->next;
        }
        end=p->next;
        if (head->id > head->next->id) {
            /* final goal:
             * new_head = head->next
             * new_head->next = head
             * new_head->next->next = head->next->next*/
            p=head;
            head=head->next;
            p->next=head->next;
            head->next=p;
        }
    }
    return head;
}
int main(void)
{
    struct Student *prev=NULL, *p=NULL, *a=NULL, *b=NULL;

    srand(7);
    for (short i=0; i<10; i++){
        p = (struct Student *)malloc(sizeof(struct Student));
        p->score = rand(); p->id = rand(); p->next = NULL;
        if (i == 0) a = p;
        else if (i == 5) b = p;
        else prev->next = p;
        prev = p;
    }
    print_stu(a);
    printf("-------------------\n");
    print_stu(b);
    printf("-------------------\n");
    print_stu(comb_sort(a, b));
    return 0;
}
