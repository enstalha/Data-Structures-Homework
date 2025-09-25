//  HW1: Insertion, Deletion and, Search Operations 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node;

node *insert_data(node *head);
void print_list(node *head);
node *delete_data(node *head);
void search_data(node *head);

int main(){
	node *head = NULL;
	int choice;
	
	printf("\n========== Welcome ==========\n");
	while(1){
        printf("\nPlease choose an option:\n");
        printf("1 -> Add a new element to the list\n");
        printf("2 -> Delete an element from the list\n");
        printf("3 -> Find an element in the list\n");
        printf("4 -> Display the list\n");
        printf("Any other number -> Exit\n?");
        scanf("%d", &choice);
		
		switch(choice){
			case 1:
				head = insert_data(head);
				break;
			case 2:
			    head = delete_data(head);
			    break;
			case 3:
			    search_data(head);
			    break;
			case 4:
				print_list(head);
				break;
			default:
				printf("Goodbye :D\n");
				exit(1);
		}
	}
	
	return 0;
}

node *insert_data(node *head){
	int data; 
	printf("Enter the value to add: ");
	scanf("%d", &data);
	
	node *new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	
	new_node->data = data;
	new_node->next = NULL;
	
	if(head == NULL){
		return new_node;
	}
	
	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	
	return head;
}

void print_list(node *head){
	printf("\n========== List ==========\n");
	
	node *temp = head;
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("END\n");
}

node *delete_data(node *head){
	if(head == NULL){
		printf("List is empty. Nothing to delete.\n");
        return NULL;
	}
	
	int data;
	printf("Enter the value to delete: ");
	scanf("%d", &data);
	
	if(head->data == data){
		return head->next;
	}
	
	node *temp_1 = head;
	while(temp_1->next->data != data){
		temp_1 = temp_1->next;
	}
	node *temp_2 = temp_1->next;
	temp_1->next = temp_2->next;
	
	return head;
}

void search_data(node *head){
	if(head == NULL){
        printf("List is empty. Nothing to search.\n");
        return;
    }
	
	int data, count = 0;
	printf("Enter the value to search for: ");
	scanf("%d", &data);
	
	node *temp = head;
    while(temp != NULL){
        if(temp->data == data){
            count++;
        }
        temp = temp->next;
    }

    if(count == 0){
        printf("%d not found in the list.\n", data);
    } else {
        printf("%d appears %d time(s) in the list.\n", data, count);
    }
}

