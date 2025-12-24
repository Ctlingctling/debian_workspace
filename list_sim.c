#include <stdio.h>
#include <stdlib.h>

struct node {
        char ele;
        struct node * next;
};

struct node *crt_list      (int len);
struct node *del_list_head (struct node *head);
struct node *del_list_tail (struct node *head);
struct node *reverse_list  (struct node *head);
struct node *del_from_tail (struct node *head, int n);
struct node *josephes      (struct node *head, int n);

int main()
{
        printf("debug.");
}

struct node *crt_list (int len) 
{
        
        struct node *head = NULL;
        struct node *tail = NULL;
        struct node *new_node  = NULL;
        int i;

        for (i = 0; i < len; i++) {
                /* now malloc a space, size of the node.*/
                new_node = (struct node *) malloc (sizeof(struct node));
                if (!new_node)
                        exit(1);
                /* if theres no input,ignore it*/
                if (scanf(" %c", &new_node->ele) != 1)
                        exit(0);

                /* the new node have to be the last one,pointing nothing.*/
                new_node->next = NULL;

                /**
                 * --the core part of the program.--
                 */

                if (head == NULL) {
                        head = new_node;
                        tail = new_node;
                } else {
                        tail->next = new_node;
                        tail = new_node;
                }
        }
        return head;
}

struct node *del_list_head(struct node* head)
{
        if (head == NULL)
                return NULL;
        struct node *new_head = head->next;
        free(head);
        return new_head;
}

struct node *del_list_tail(struct node *head)
{
        if (head == NULL) return NULL;
        if (head->next == NULL) {
                free(head);
                return NULL;
        }
        struct node *temp = head;
        while (temp->next->next != NULL) {
                temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
}

struct node *reverse_list(struct node *head)
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

struct node *sort_min(struct node *head)
{
        struct node *cur1;
        struct node *cur2;
        struct node *mptr;
        char tmp;

        if (!head || !head->next)
                return head;

        for (cur1 = head; cur1 != NULL; cur1 = cur1->next) {
                mptr = cur1;

                for (cur2 = cur1->next; cur2 != NULL; cur2 = cur2->next) {
                        if (cur2->ele < mptr->ele)
                                mptr = cur2;
                }

                if (mptr != cur1) {
                        tmp = cur1->ele;
                        cur1->ele = mptr->ele;
                        mptr->ele = tmp;
                }
        }

        return head;
}

struct node *del_from_tail(struct node *head, int n)
{
        struct node *fast = head;
        struct node *slow = head;
        struct node *pre_slow = NULL;
        int i;

        if (!head || n <= 0)
                return head;

        for (i = 0; i < n; i++) {
                if (fast == NULL)
                        return head;
                fast = fast->next;
        }

        if (fast == NULL) {
		struct node *new_head = head->next;
		free(head);
		return new_head;
	}

        while (fast->next != NULL) {
                fast     = fast->next;
                pre_slow = slow;
                slow     = slow->next;
        }
        if (pre_slow) {
                pre_slow->next = slow->next;
                free(slow);
        }

        return(head);
}

struct node *josephes(struct node *head, int n)
{
        if (head == NULL)
                return NULL;
        if (head->next == NULL)
                return head;
        if (n <= 0)
                return head;


        int count = 1;
        struct node *tail = head;
        while (tail->next != NULL) {
                tail = tail->next;
                count++;
        }


        tail->next = head;

        struct node *curr = head;
        struct node *prev = tail;


        while (count > 1) {

                int steps = (n - 1) % count;
                for (int i = 0; i < steps; i++) {
                        prev = curr;
                        curr = curr->next;
                }

                prev->next = curr->next;
                struct node *to_free = curr;
                curr = prev->next;
                free(to_free);
                count--;
        }


        curr->next = NULL;
        return curr;
}

