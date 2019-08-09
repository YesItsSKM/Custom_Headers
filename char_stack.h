#ifndef CHAR_STACK
#define CHAR_STACK

        #include <stdio.h>
        #include <malloc.h>

        typedef struct node{
            char value;
            struct node *next;
        } Char_Stack;

        void create_stack(Char_Stack **);
        void push(Char_Stack **, char c);
        char pop(Char_Stack **);
        void print_stack(Char_Stack *);
        void free_stack(Char_Stack **);
        int isEmpty(Char_Stack *);

        void create_stack(Char_Stack **stack){
            Char_Stack *new_node = (Char_Stack *) malloc(sizeof(Char_Stack));
            new_node = NULL;
            *stack = new_node;
        }

        void push(Char_Stack **stack, char ch){
            Char_Stack *new_node = (Char_Stack *) malloc(sizeof(Char_Stack));
            new_node->next = NULL;
            new_node->value = ch;

            if(*stack == NULL)
                *stack = new_node;
            
            else{
                new_node->next = *stack;
                (*stack) = new_node;
            }
        }

        char pop(Char_Stack **stack){
            if(*stack == NULL){
                // printf("\nStack is already empty.\n");
                return '\0';
            }
            
            else{
                Char_Stack *temp = *stack;
                char ch = temp->value;
                    *stack = (*stack)->next;

                free(temp);
                return ch;
            }
        }

        void print_stack(Char_Stack *stack){
            if(stack == NULL){
                printf("\nStack is empty.");
                return;
            }
            
            else{
                Char_Stack *temp = stack;
                
                printf("\n[%c] <--- Top\n", temp->value);

                temp = temp->next;
                while(temp != NULL){
                    printf(" %c\n", temp->value);
                    temp = temp->next;
                }
            }
        }

        void free_stack(Char_Stack **stack){
            if(*stack == NULL){
                printf("\nStack is empty.");
                return;
            }
            
            else{
                Char_Stack *temp = *stack;
                Char_Stack *delete_this_node = NULL;

                while(temp != NULL){
                    delete_this_node = temp;
                    temp = temp->next;
                    free(delete_this_node);
                }
                
                printf("\nStack deleted.");
            }

            *stack = NULL;
        }

        int isEmpty(Char_Stack *stack){
            if(stack == NULL)
                return 1;
            else
                return -1;
        }

#endif