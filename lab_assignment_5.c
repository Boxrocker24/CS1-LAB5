#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    if(head == NULL)
    {
        exit(1);
    }
    int total = 0;
    node* ptemp = head;
    while(ptemp!=NULL)
    {
        ptemp = ptemp->next;
        total++;
    }
    return total;
}

//  parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc(sizeof(char)*(len+1));
    
    node* ptemp = head;
    for(int i = 0 ; i<length(head); i++)
    {
        str[i] = ptemp->letter;
        ptemp = ptemp->next;
    }
    str[len] = '\0';
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        exit(1);
    }
    newNode->letter = c;
    newNode->next = NULL;

    if(*pHead == NULL)
    {
        *pHead = newNode;
        return;
    }
    node* ptemp = *pHead;
    while(ptemp -> next != NULL)
    {
        ptemp = ptemp->next;
    }
    ptemp->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}