#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

void PrintList(Node *head)
{
    Node *p = head->next;
    int ind = 0;
    while (p)
    {
        printf("node[%d] key: %d\n", ind, p->key);
        p = p->next;
        ind++;
    }
}

void ClearMemory(struct Node *head)
{
    Node *p = head->next;
    Node *tmp;
    int ind = 0;
    while (p)
    {
        tmp = p;
        p = p->next;
        printf("node[%d] deleted..\n", ind);
        free(tmp);
        ind++;
    }
}

void Insert_node_back(Node *head, Node *tail, const int newkey)
{
    Node *current_node = head;
    Node *next_node = head->next;
    Node *new_node;
    while (next_node)
    {
        current_node = next_node;
        next_node = next_node->next;
    }
    // create a new node
    new_node = (Node *)malloc(sizeof(Node));
    new_node->key = newkey;
    new_node->next = NULL;
    // adjust next pointer
    if (current_node == head) // empty now?
    {
        head->next = new_node;
    }
    else
    {
        current_node->next = new_node;
    }
    tail = new_node;
    head->key += 1; // num elements sotred here
}

int Delete_node_back(Node *head, Node *tail)
{
    Node *prev_node = head;
    Node *current_node = head;
    Node *next_node = head->next;
    while (next_node)
    {
        prev_node = current_node;
        current_node = next_node;
        next_node = next_node->next;
    }
    if (current_node == head) // empty now?
    {
        printf("[Linked List Underflow..!!]\n");
        return -1;
    }
    prev_node->next = NULL;
    tail = prev_node;
    int key = current_node->key;
    free(current_node);
    head->key -= 1; // num elements sotred here
    return key;
}

int Delete_node_front(
    Node *head,
    Node *tail)
{
    Node *current_node = head->next;
    if (current_node == NULL) // empty now?
    {
        printf("[Linked List Underflow..!!]\n");
        return -1;
    }
    Node *next_node = current_node->next;
    head->next = next_node;
    int key = current_node->key;
    free(current_node);
    head->key -= 1; // num elements sotred here
    return key;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->key = 0;
    head->next = NULL;
    Node *tail = (Node *)malloc(sizeof(Node));
    tail->key = 0;
    tail->next = NULL;
    for (int i = 0; i < 5; i++)
    {
        printf("//---Inserting Key : %d \n", i);
        Insert_node_back(head, tail, i);
        PrintList(head);
    }
    for (int i = 0; i < 6; i++)
    {
        int key = Delete_node_front(head, tail);
        printf("//---First Key : %d \n", key);
        PrintList(head);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("//---Inserting Key : %d \n", i);
        Insert_node_back(head, tail, i);
        PrintList(head);
    }
    for (int i = 0; i < 6; i++)
    {
        int key = Delete_node_back(head, tail);
        printf("//---Last Key : %d \n", key);
        PrintList(head);
    }
    printf("\nDeleting all nodes in the linked list..\n");
    ClearMemory(head);
    free(head);
    free(tail);
    return 0;
}