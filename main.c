#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE * next;
};
typedef struct NODE NODE;

struct LIST{
    NODE * head;
};
typedef struct LIST SLC;

void printList(SLC * l)
{
    NODE * current;
    if(l->head == NULL)
        printf("The list is empty.\n");
    else{
        current = l->head;
        while(current != NULL){
            printf(" %d ",current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void insertFront(SLC * l)
{
    NODE * newNode;

    newNode = malloc(sizeof(NODE));
    printf("Data : ");
    scanf("%d",&newNode->data);
    newNode->next = l->head;
    l->head = newNode;
}

void insertMiddle(SLC * l)
{
    NODE * newNode, *current;
    int i, position;

    printf("Position : ");
    scanf("%d",&position);
    if(position < 1)
        insertFront(l);
    else{
        newNode = malloc(sizeof(NODE));
        printf("Data : ");
        scanf("%d",&newNode->data);
        current = l->head;
        for(i = 0; i < position-1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertEnd(SLC * l)
{
    NODE * current, * newNode;
    if(l->head == NULL)
        insertFront(l);
    else{
        current = l->head;
        while(current->next != NULL)
            current = current->next;

        newNode = malloc(sizeof(NODE));
        printf("Data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        current->next = newNode;
    }
}

void deleteFront(SLC * l)
{
    NODE * del;
    if(l->head == NULL)
        printf("The list is empty.\n");
    else{
        del = l->head;
        l->head = l->head->next;
        free(del);
    }
}

void deleteMiddle(SLC * l)
{
    NODE * del, * current;
    int i, position;
    if(l->head == NULL)
        printf("The list is empty.\n");
    else{
        printf("Position : ");
        scanf("%d",&position);
        if(position < 1)
            deleteFront(l);
        else{
            current = l->head;
            for(i = 0; i < position-1; i++)
                current = current->next;
            del = current->next;
            current->next = current->next->next;
            free(del);
        }
    }
}

void deleteEnd(SLC * l)
{
    NODE * del, * current;
    if(l->head == NULL)
        printf("The list is empty.\n");
    else{
        current = l->head;
        while(current->next->next != NULL)
            current = current->next;
        del = current->next;
        current->next = current->next->next;
        free(del);
    }
}

void deleteList(SLC * l)
{
    NODE * del;
    while(l->head != NULL){
        del = l->head;
        l->head = l->head->next;
        free(del);
    }
}

void swap(SLC * l, NODE * n1, NODE * n2)
{
    NODE *i, *j, *help;
    if(l->head == n1){
        if(n1->next == n2){
            n1->next = n2->next;
            n2->next = n1;
            l->head = n2;
        }
        else{
            i = l->head;
            while(i->next != n2)
                i = i->next;
            help = n1->next;
            n1->next = n2->next;
            n2->next = help;
            i->next = n1;
            l->head = n2;
        }

    }
    else{
        if(n1->next == n2){
            i = l->head;
            while(i->next != n1)
                i = i->next;
            n1->next = n2->next;
            n2->next = n1;
            i->next = n2;
        }
        else{
            i = l->head;
            while(i->next != n1)
                i = i->next;
            j = l->head;
            while(j->next != n2)
                j = j->next;
            help = n1->next;
            n1->next = n2->next;
            n2->next = help;
            j->next = n1;
            i->next = n2;
        }

    }
}

void sortList(SLC * l)
{
    NODE *i, *j, *min;
    int k, position = 0;
    if(l->head == NULL)
        printf("The list is empty.\n");
    else{
        i = l->head;
        while(i->next != NULL){
            min = i;
            j = i->next;
            while(j != NULL){
                if(min->data > j->data)
                    min = j;
                j = j->next;
            }
            if(min != NULL)
                if(i->data > min->data)
                    swap(l, i, min);
            position++;
            i = l->head;
            for(k = 0; k < position; k++)
                i = i->next;
        }
    }
}

int main()
{
    SLC * l;
    int menu;
    while(1){
        printf("1 - Initializer.\n");
        printf("2 - Print.\n");
        printf("3 - Insert at the front.\n");
        printf("4 - Insert at the middle.\n");
        printf("5 - Insert at the end.\n");
        printf("6 - Delete at the front.\n");
        printf("7 - Delete in the middle.\n");
        printf("8 - Delete at end.\n");
        printf("9 - Delete the list.\n");
        printf("10- Sort the list.\n");
        printf("11- Exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&menu);
        switch(menu)
        {
        case 1:
            l = malloc(sizeof(SLC));
            l->head = NULL;
            break;
        case 2:
            printList(l);
            break;
        case 3:
            insertFront(l);
            break;
        case 4:
            insertMiddle(l);
            break;
        case 5:
            insertEnd(l);
            break;
        case 6:
            deleteFront(l);
            break;
        case 7:
            deleteMiddle(l);
            break;
        case 8:
            deleteEnd(l);
            break;
        case 9:
            deleteList(l);
            break;
        case 10:
            sortList(l);
            break;
        case 11:
            free(l);
            exit(0);
            break;
        }
    }
    return 0;
}
