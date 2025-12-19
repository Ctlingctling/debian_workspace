#include <stdio.h>
#include <stdlib.h>

struct node {
        char ele;
        struct node * next;
};

int main()
{
        printf("debug.");
}

struct node* crt_list (int len) 
{
        /**
         * --Nodes--
         *  We only need three nodes to creat a list.
         */
        
        struct node* head = NULL;
        struct node* new_node  = NULL;
        struct node* tail = NULL;

        /**
         * --A for loop--
         * alloc space for each node,notice that the space isnt continuous.
         * Since we malloc for a new node every time.
         */

        for (int i = 0; i < len; i++) {
                /* now malloc a space, size of the node.*/
                new_node = (struct node*)malloc(sizeof(struct node));
                /* if theres no input,ignore it*/
                if (scanf("%c", &(*new_node).ele) != 1)
                        exit(0);

                /* the new node have to be the last one,pointing nothing.*/
                new_node -> next = NULL;

                /**
                 * --the core part of the program.--
                 */

                if (head == NULL) {
                        head = new_node;
                        tail = new_node;
                } else {
                        tail -> next = new_node;
                        tail = new_node;
                }
        }
        return head;
}

struct node* del_list_head(struct node* head)
{
        if (head == NULL)
                return NULL;
        struct node* new_head = head->next;
        free(head);
        return new_head;
}

/**
 * struct node* del_list_tail(struct node* head, int len)
 * {
 *        if (head == NULL)
 *                return NULL;
 *        int count = 0;
 *        struct node* pre_node = head;
 *        while (count != len - 1) {
 *                pre_node = pre_node->next;
 *                count++;
 *        }
 *        free(pre_node->next);
 *        pre_node->next = NULL;
 *        return pre_node;
 * }
 */

struct node* del_list_tail(struct node* head)
{
        if (head == NULL) return NULL;
        if (head->next == NULL) {
                free(head);
                return NULL;
        }
        struct node* temp = head;
        while (temp->next->next != NULL) {
                temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
}

struct node* reverse_list(struct node *head)
{
        if (head       == NULL) return NULL;
        if (head->next == NULL) return head;
        
        struct node *pre  = NULL;
        struct node *curr = head;
        struct node *temp;
        while (curr != NULL) {
                temp = curr->next;
                curr->next = pre;
                pre  = curr;
                curr = temp;
        }
        return pre;
}

struct node* sort_min(struct node *head)
{
        if (head       == NULL)
                return NULL;
        if (head->next == NULL)
                return head;

        struct node *cur1 = head;
        struct node *cur2 = head;
        struct node *mptr = head;
        struct node *temp;

        char min = 60;
        
        for (;cur1 != NULL; cur1 = cur1->next) {
                for (cur2 = cur1; cur2 != NULL; cur2 = cur2->next) {
                        
                }
        }
}
