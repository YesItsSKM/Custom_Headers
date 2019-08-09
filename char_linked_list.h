#ifndef CHAR_LINKED_LIST
#define CHAR_LINKED_LIST

	#include <stdio.h>      // For basic I/O.
	#include <malloc.h>     // For malloc(), free() - Memory allocation and deallocation.

	// Creating a linked list stucture (typedef) -  Linked_list is now a user defined datatype.
	typedef struct linked_list{
		char value;
		struct linked_list *next;
	}Linked_list;

	/*
		Function declarations/prototypes to be used(or defined later).
		Double pointer(**) ensures that [pointer to -> [pointer to] -> structure variable] is passed, so any changes in the structure pointer will be
		reflected globally.
	*/
	void add(Linked_list **, char);
	void create_list(Linked_list **);
	void free_list(Linked_list **);
	void print_list(Linked_list *);

	/*
		Catching the reference of the list variable(which is a pointer itself) using a double pointer or double indirection/dereferencing.
		It will make sure that every/any change(s) to the pointer varible of the Linked_list will be directly reflected back, no need of returning
		in this case.
	*/
	void create_list(Linked_list **list){
		Linked_list *new_node = (Linked_list *) malloc(sizeof(Linked_list)); // Creating a new (basically first) node. Allocating memory to it.
		new_node = NULL;    // Initialising it to NULL, because it points to nothing. List is only initialised at the moment, no data is added yet.
		*list = new_node;   // Assigning the new_node (here, first) to the original list for further implementation.
	}

	// Appending a new node to existing list with the provided data.
	void add(Linked_list **list, char ch){
		// Creating a new node and then initialising the [next pointer] to NULL and assigning the data.
		Linked_list *new_node = (Linked_list *) malloc(sizeof(Linked_list));
		new_node->next = NULL;  // Beacuse this node will be the last node in the list, which means there is no next node attached to it. So NULL it is.
		new_node->value = ch;   // Data provided by the user is assigned to the node here.

		// If the list is empty (NULL) then directly add the new_node.
		if(*list == NULL)
		    *list = new_node;
		
		// else, if the list is not empty (NULL) then traverse to the end to the list end attach the new_node.
		else{
		    Linked_list *temp = *list;  // Creating a temporary variable to traverse the list.
		    /* 
		        Traversing till the last node. Because last node means there is no next node attached to it. So temp->next must be NULL so that temp
		        should be last.
		    */
		    while(temp->next != NULL){
		        temp = temp->next;
		    }
		    temp->next = new_node;  // Adding the node at last position.
		}
	}

	// Here we don't need a double indirection becuase we are only reading (displaying) the data present in the list.
	void print_list(Linked_list *list){
		// If list is empty (NULL) then give message that list is empty and return to main().
		if(list == NULL){
		    printf("\nList is empty.");
		    return;
		}
		
		// else, if list is not empty traverse through each node and display its data.
		else{
		    printf("\n[ "); // Printing the opening bracket for displaying list content enclosed in square brackets '[ ]'.
		    Linked_list *temp = list;   // Defining a temp variable to traverse through the list.
		    
		    // While temp is not NULL, or no longer a part of the list or crossed the last node (because next to last node is NULL or nothing).
		    while(temp != NULL){
		        // if the current node (temp) is not the last node then print the data then a comma(,) to seperate values.
		        if(temp->next != NULL)
		            printf("%c, ", temp->value);
		        // else if the current node (temp) is the last node then print the data only.
		        else
		            printf("%c", temp->value);
		        
		        // Data is printed now point to next node.
		        temp = temp->next;
		    }
		    printf(" ]\n");   // Printing the closing square bracket ].
		}
	}

	/*  
		Deleting every node present in the list one at a time in order to delete the whole list. Double pointer is needed because we are making changes
		to the list, in fact we are deleteing it.
	*/
	void free_list(Linked_list **list){
		// If list is already empty, then just promt a message that list is empty.
		if(*list == NULL){
		    printf("\nList is empty.");
		    return;
		}
		
		// else if list is not empty, then traverse through the list store current node in a variable (or point to it) in order to delete that node.
		else{
		    Linked_list *temp = *list;   // Defining a temp variable to traverse through the list.
		    Linked_list *delete_this_node = NULL;   // Defining the current variable as NULL because traversing is not yet started.
		    while(temp != NULL){
		        delete_this_node = temp;    // Assigning the value/node to be deleted.
		        temp = temp->next;  // Change/point to next node.
		        free(delete_this_node); // Delete the current node.
		    }
		    // Now every node is deleted.
		    printf("\nList deleted.");
		}

		*list = NULL;   // Set list content to NULL, because now list is empty.
	}

#endif
