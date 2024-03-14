#include <math.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <stdio.h>

#define PROJECT_NAME "c_list"


struct entry
{
    int seq;
    float data;
    LIST_ENTRY(entry) entries;
};


LIST_HEAD(listhead, entry);


int main(int argc, char **argv) {
    struct entry *n, *nx, *np;
    struct listhead head;
    LIST_INIT(&head);

    // Allocate memory for entry
    for(int i = 0; i<10; i++) {
        n = (struct entry *)malloc(sizeof(struct entry));
        LIST_INSERT_HEAD(&head, n, entries);
    }

    // Set fields for entry
    int i = 0;
    LIST_FOREACH(np, &head, entries) {
        np->seq = i++;
        np->data = rand();
    }

    // Display entry
    LIST_FOREACH(np, &head, entries) {
        printf("Item %d has data %lf\n", np->seq, np->data);
    }

    // Remove entry
    n = LIST_FIRST(&head);
    while (n != NULL)
    {
        nx = LIST_NEXT(n, entries);
        free(n);
        n = nx;
    }

    LIST_INIT(&head);

    return EXIT_SUCCESS;
}
