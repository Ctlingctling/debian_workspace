#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int id;
	char name[32];
	int age;
	int height;
	struct node *next;
};

struct node *crt_list(int len);
struct node *move_after(struct node *head, int x, int y);
struct node *move_before(struct node *head, int x, int y);
struct node *delete_node(struct node *head, int x);

int main(void)
{
	int n, m;
	int i;
	int type, x, y;
	char buffer[256];
	struct node *head = NULL;
	struct node *curr;

	if (scanf("%d %d", &n, &m) != 2)
		return 0;
	getchar();

	head = crt_list(n);

	for (i = 0; i < m; i++) {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
			break;

		int args = sscanf(buffer, "%d %d %d", &type, &x, &y);
		
		if (type == 1 && args == 3) {
			head = move_after(head, x, y);
		} else if (type == 2 && args == 3) {
			head = move_before(head, x, y);
		} else if (type == 3 && args >= 2) {
			head = delete_node(head, x);
		}
	}

	if (head == NULL) {
		printf("Empty!\n");
	} else {
		curr = head;
		while (curr != NULL) {
			printf("%d %s %d %d\n", curr->id, curr->name, curr->age, curr->height);
			curr = curr->next;
		}
	}

	return 0;
}

struct node *crt_list(int len)
{
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *new_node = NULL;
	char line_buf[256];
	int i;

	for (i = 0; i < len; i++) {
		if (fgets(line_buf, sizeof(line_buf), stdin) == NULL)
			break;

		new_node = (struct node *)malloc(sizeof(*new_node));
		if (!new_node)
			exit(1);

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

struct node *detach_node(struct node *head, struct node *target, struct node *prev)
{
	if (target == head) {
		return head->next;
	} else if (prev) {
		prev->next = target->next;
		return head;
	}
	return head;
}

struct node *move_after(struct node *head, int x, int y)
{
	struct node *curr = head;
	struct node *node_x = NULL;
	struct node *prev_x = NULL;
	struct node *node_y = NULL;

	if (x == y) return head;

	while (curr) {
		if (curr->id == y) node_y = curr;
		if (curr->id == x) node_x = curr;
		if (curr->next && curr->next->id == x) prev_x = curr;
		
		curr = curr->next;
	}

	if (!node_x || !node_y) return head;
	if (node_y->next == node_x) return head;

	head = detach_node(head, node_x, prev_x);

	node_x->next = node_y->next;
	node_y->next = node_x;

	return head;
}

struct node *move_before(struct node *head, int x, int y)
{
	struct node *curr = head;
	struct node *node_x = NULL;
	struct node *prev_x = NULL;
	struct node *node_y = NULL;
	struct node *prev_y = NULL;

	if (x == y) return head;

	while (curr) {
		if (curr->id == y) node_y = curr;
		if (curr->id == x) node_x = curr;
		
		if (curr->next && curr->next->id == x) prev_x = curr;
		if (curr->next && curr->next->id == y) prev_y = curr;
		
		curr = curr->next;
	}

	if (!node_x || !node_y) return head;
	if (prev_y == node_x) return head;
	
	head = detach_node(head, node_x, prev_x);
	
	if (head == node_y) {
		node_x->next = head;
		head = node_x;
	} else {
		curr = head;
		struct node *new_prev_y = NULL;
		while (curr) {
			if (curr->next == node_y) {
				new_prev_y = curr;
				break;
			}
			curr = curr->next;
		}
		
		if (new_prev_y) {
			node_x->next = node_y;
			new_prev_y->next = node_x;
		}
	}

	return head;
}

struct node *delete_node(struct node *head, int x)
{
	struct node *curr = head;
	struct node *prev = NULL;

	if (!head) return NULL;

	if (head->id == x) {
		struct node *temp = head->next;
		free(head);
		return temp;
	}

	while (curr) {
		if (curr->id == x) break;
		prev = curr;
		curr = curr->next;
	}

	if (!curr) return head;

	prev->next = curr->next;
	free(curr);

	return head;
}

