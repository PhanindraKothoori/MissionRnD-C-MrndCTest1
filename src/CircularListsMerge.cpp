/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void normalize(struct node *head){
	struct node *temp = head;
	while (temp->next != head){
		temp = temp->next;

	}
	temp->next = NULL;
}
void swap(struct node **head1, struct node **head2){
	struct node *temp;
	temp = *head1;
	*head1 = *head2;
	*head2 = temp;
}
int lenOfLL(struct node *head){
	int len = 0;
	struct node *temp=head;
	while (temp){
		len++;
		temp = temp->next;
	}
	return len;
}

struct node* mergeHelper(struct node *head1, struct node *head2){
	struct node *temp = head1;
	while (head1 != NULL && head2 != NULL){
		while (head1->data < head2->data){
			if (head1 && head2){
				temp->next = head1;
				temp = head1;
				head1 = head1->next;
			}
		}

		while (head1 && head2 && head1->data >= head2->data){
			temp->next = head2;
			temp = head2;
			head2 = head2->next;
		}

	}
	while (head1){
		temp->next = head1;
		temp = head1;
		head1 = head1->next;
	}
	while (head2){
		temp->next = head2;
		temp = head2;
		head2 = head2->next;
	}
	return head1;
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (head1 && head2 && *head1 && *head2){
		int length=0;
		normalize(*head1);
		normalize(*head2);
		struct node *temp1 = *head1, *temp2=*head2;
		if (temp1->data > temp2->data){
			swap(head1, head2);
		}
		*head1 = mergeHelper(*head1, *head2);
		struct node *temp = *head1;
		while (temp->next){
			temp = temp->next;
		}
		temp->next = *head1;
		return lenOfLL(*head1);
	}
	else{
		return -1;
	}
}