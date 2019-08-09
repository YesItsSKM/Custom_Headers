#ifndef CHAR_QUEUE
#define CHAR_QUEUE

        #include <stdio.h>
        #include <malloc.h>

        typedef struct node{
            char value;
            struct node *next;
        } Char_Queue;

        void create_queue(Char_Queue **);
        void enqueue(Char_Queue **, char c);
        char dequeue(Char_Queue **);
        void print_queue(Char_Queue *);
        void free_queue(Char_Queue **);

        void create_queue(Char_Queue **queue){
            Char_Queue *new_node = (Char_Queue *) malloc(sizeof(Char_Queue));
            new_node = NULL;
            *queue = new_node;
        }

        void enqueue(Char_Queue **queue, char ch){
            Char_Queue *new_node = (Char_Queue *) malloc(sizeof(Char_Queue));
            new_node->next = NULL;
            new_node->value = ch;

            if(*queue == NULL)
                *queue = new_node;
            
            else{
                Char_Queue *temp = *queue;
                
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }

        char dequeue(Char_Queue **queue){
            if(*queue == NULL){
                printf("\nQueue is already empty.\n");
                return '\0';
            }
            
            else{
                Char_Queue *temp = *queue;
                char ch = temp->value;
                    *queue = (*queue)->next;

                free(temp);
                return ch;
            }
        }

        void print_queue(Char_Queue *queue){
            if(queue == NULL){
                printf("\nQueue is empty.");
                return;
            }
            
            else{
                printf("\n[ ");
                Char_Queue *temp = queue;
                
                while(temp != NULL){
                    if(temp->next != NULL)
                        printf("%c, ", temp->value);
                    
                    else
                        printf("%c", temp->value);
                    
                    temp = temp->next;
                }
                printf(" ]\n");
            }
        }

        void free_queue(Char_Queue **queue){
            if(*queue == NULL){
                printf("\nQueue is empty.");
                return;
            }
            
            else{
                Char_Queue *temp = *queue;
                Char_Queue *delete_this_node = NULL;

                while(temp != NULL){
                    delete_this_node = temp;
                    temp = temp->next;
                    free(delete_this_node);
                }
                
                printf("\nQueue deleted.");
            }

            *queue = NULL;
        }

#endif