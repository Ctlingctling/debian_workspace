#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
        int  id;
        char name[32];
        int  age;
        int  height;
        struct node * next;
};

int main()
{
        int n;
        int m;

        struct node *head = crt_list(n);
        head = command(m);

        for (; head->next != NULL; head = head->next) {
                printf("%d %s %d %d", head->id, head->name, head->age, head->height);
        }
}

struct node *crt_list(int len)
{
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *new_node = NULL;
	char line_buf[256];
	int i;

	for (i = 0; i < len; i++) {
		/* Read line first ensures we don't malloc if input is empty */
		if (fgets(line_buf, sizeof(line_buf), stdin) == NULL)
			break;

		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			exit(1);

		/* Parsing: %31s ensures we don't overflow name[32] */
		if (sscanf(line_buf, "%d %31s %d %d", 
			   &new_node->id, new_node->name, 
			   &new_node->age, &new_node->height) != 4) {
			free(new_node);
			continue;
		}

		new_node->next = NULL;

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

struct node* del_list_head(struct node* head)
{
        if (head == NULL)
                return NULL;
        struct node* new_head = head->next;
        free(head);
        return new_head;
}

struct node *insert(struct node *head, int x, int y)
{
	struct node *curr = head;
	struct node *node_x = NULL;
	struct node *prev_x = NULL;
	struct node *node_y = NULL;

	/* Search phase */
	while (curr) {
		if (curr->id == y)
			node_y = curr;
		
		if (curr->id == x)
			node_x = curr;
		else if (curr->next && curr->next->id == x)
			prev_x = curr; /* prev_x found */

		curr = curr->next;
	}

	/* Validation phase */
	if (!node_x || !node_y || node_x == node_y)
		return head;
	
	/* Detach phase */
	if (node_x == head)
		head = node_x->next;
	else if (prev_x)
		prev_x->next = node_x->next;
	else
		return head; /* Error: x found but cannot detach */

	/* Insert phase */
	node_x->next = node_y->next;
	node_y->next = node_x;

	return head;
}

struct node *delete(struct node *head, int num)
{
        struct node *prev = NULL;
        struct node *curr = head;

        if (!head)
                return NULL;

        if (curr->id == num) {
                struct node *temp = curr->next;
                free(curr);
                return temp;
        }

        while (curr) {
                if (curr-> id == num)
                        break;
                prev = curr;
                curr = curr->next;
        }

        prev->next = curr->next;
        free(curr);

        return head;
}

struct node *command(struct node *head, int m)
{
        char buffer[256];
        int type;
        int numx;
        int numy;

        for (int i = 0; i < m; i++) {
                if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                        break;
                }

                if (sscanf(buffer, "%d %d %d", &type, &numx, &numy) != 3) {
                        if (sscanf(buffer, "%d %d", &type, &numx) != 2) {
                                continue;
                        }
                }

                if (type == 1) head = insert (head, numx, numy);
                if (type == 2) head = insert (head, numx, numy - 1);
                if (type == 3) head = delete (head, numx);
        }
        return head;
}
