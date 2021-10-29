#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *nxt;
};
struct headnode
{
    struct node *start;
    struct node *end;
    int ct;
};
struct headnode h;
void insertfirst()
{
    int x;
    printf("Enter value to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = x;
    ptr->nxt = NULL;
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.ct = 1;
        return;
    }
    ptr->nxt = h.start;
    h.start = ptr;
    h.ct++;
}

void display()
{
    struct node *ptr = h.start;
    if (!ptr)
    {
        printf("! Empty List!\n");
        return;
    }
    printf("Dislpay Linked List:\n");
    while (ptr)
    {
        printf("%d ", ptr->val);
        ptr = ptr->nxt;
    }
    printf("\t");
}
void insertlast()
{
    int x;
    printf("Enter value to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = x;
    ptr->nxt = NULL;
    if (!h.start)
    {
        h.start = ptr;
        h.end = ptr;
        h.ct = 1;
        return;
    }
    struct node *p = h.start;
    while (p->nxt)
        p = p->nxt;
    p->nxt = ptr;
    h.end = ptr;
    h.ct++;
}
void deleteNode()
{
    int x;
    printf("Enter element to delete:");
    scanf("%d", &x);
    struct node *q = h.start;
    struct node *p = NULL;
    while (q && q->val != x)
    {
        p = q;
        q = q->nxt;
    }
    if (!q)
        return;
    if (!p)
        h.start = q->nxt;
    else
        p->nxt = q->nxt;
    if (h.end == q)
        h.end = p;
    free(q);
    h.ct--;
}
void search()
{
    int x;
    printf("Enter Element to search:");
    scanf("%d", &x);
    struct node *p = h.start;
    while (p)
    {
        if (p->val == x)
        {
            printf("!Element found in list!\n");
            return;
        }
        p = p->nxt;
    }
    printf("!Error-Element not found!\n");
}
void countNode()
{
    printf("Total No. of nodes in list :%d\n", h.ct);
}
int main()
{
    h.start = NULL;
    h.end = NULL;
    printf("DS LAB Assignment-15 Linked List with Headnode by Aayush Patel 2K20/CO/11\n");
    printf("\nChoose any operations:\n");
    h.ct = 0;
    int choice;

    while (1)
    {
        printf("1.Insert at Start\n");
        printf("2.Insert at End\n");
        printf("3.Display Linked list\n");
        printf("4.Search Element in List\n");
        printf("5.Delete node\n");
        printf("6.Count no. of nodes\n");
        printf("7.!Exit!\n");
        printf("Enter Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertfirst();
            printf("\n");
            break;
        case 2:
            insertlast();
            printf("\n");
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 5:
            deleteNode();
            printf("\n");
            break;
        case 4:
            search();
            printf("\n");
            break;
        case 6:
            countNode();
            printf("\n");
            break;
        case 7:
            exit(1);
            break;
        }
    }
    return 0;
}
