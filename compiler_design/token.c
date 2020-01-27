#include "token.h"
#include <malloc.h>

int str_len(char* str){
	int i = 0;
	
	while(str[i++] != '\0');

 return i;
}

char* make_token(char *str, char delimiter){
	char *temp;
	int i, k = 0, start;
	int str_length = str_len(str);
	
	static int limiter = 0;
	
		start = limiter;
		
		for(i = start; str[i] != '\0'; i++){
			if(str[i] == delimiter){
				limiter = i + 1;
				break;
			}
		}
				
		temp = malloc(limiter - start);
		
		for(i = start; i < str_length-1; i++){
			if((str[i] == delimiter) || (str[i] == '\0'))
				break;
			else
				temp[k++] = str[i];
			}
		
		temp[k] = '\0';
		k = 0;
			
	 return temp;
}
