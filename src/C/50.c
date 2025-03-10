#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    double p = sqrt(n);
    if (n == 2)
    {
        return 1;
    }
    for (int i = 2; i < p + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node *PrimesUnder1M()
{
    struct Node *Primes = NULL;
    for (int k = 1000000; k > 1; k--)
    {
        if (is_prime(k) == 1)
        {
            insertAtBeginning(&Primes, k);
        }
    }
    return Primes;
}

int *SumBelowKelements(struct Node *List, int K)
{
    int sum = 0;
    struct Node *current = List;
    int count = 0;
    int store = 0;

    while (current != NULL && count < K)
    {
        sum += current->data;
        store = current->data;
        current = current->next;
        count++;
    }
     int* output = (int*)malloc(2 * sizeof(int));
    if (output == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    output[0] = sum;
    output[1] = store;

    return output;

}

int lengthOfLinkedList(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}


int main()
{
    struct Node *Primes = PrimesUnder1M();
    printList(Primes);
    int out = 0;
    int len = lengthOfLinkedList(Primes);
    printf("%d\n",len);
    /*for(int k = 2; k < len; k++){
        int* output = SumBelowKelements(Primes, k);
        if (is_prime(output[0])==1 && output[1] > out){
            out = output[1];
            printf("%d\n",out);
        }
    }

    printf("%d\n", out);
    */
    return 1;
}