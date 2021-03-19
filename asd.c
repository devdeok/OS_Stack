#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list_head.h"

LIST_HEAD(stack);

struct entry {
	struct list_head list;
	char *string;
};

struct entry *temp;
struct entry *cur;
struct entry *curn;

void push_stack(char *);
int pop_stack(char *);
void dump_stack(void);

int main(void){

    struct entry *cur;
    struct entry *node;
	char* buffer = malloc(sizeof(char)*10);

	char* str[6] = {"a","b","c","d","e","f"};

    //앞에 추가
	for(int i =0;i<6;i++){
		push_stack(str[i]);
	}dump_stack();


	pop_stack(buffer);
	printf("buffer : %s\n", buffer);
    dump_stack();

	free(buffer);
    return 0;
}

void push_stack(char *string)
{	// 들어오는 string이 독립적인 메모리를 할당받을 수 있게 해야됨
    // 메모리공간 공유 X
	/* TODO: Implement this function */
	
	

	temp = (struct entry *)malloc(sizeof(struct list_head));
	temp->string = string;
	INIT_LIST_HEAD(&temp->list);
	list_add_tail(&temp->list,&stack);
}

int pop_stack(char *buffer)
{
	/* TODO: Implement this function */

	// buffer에 string을 담고 stack의 top부분에 entry의 string을 pop한다.

	if(!list_empty(&stack)){ // stack이 비어있지 않다면
		list_for_each_entry_safe(cur,curn,&stack,list){ // top까지 순회
			printf("cur.next address   : %p\n", &cur->list.next);

			if(list_is_last(&cur->list,&stack)){ // cur->list->next == stack
				printf("stack address : %p\n", &stack);
				printf("cur->next     : %p\n", &cur->list.next);
				strcpy(buffer,cur->string); // 맞다면 string을 buffer에 복사하고
				list_del(&cur->list);
				// printf("complete delete!!\n");
			}
		}
		return 0;
	}

	return -1; /* Must fix to return a proper value when @stack is not empty */
}


void dump_stack(void)
{
	/* TODO: Implement this function */
	struct entry *cur;
	
	list_for_each_entry(cur,&stack,list){
		fprintf(stderr, "dump : %s\n", cur->string);
	}
	 /* Example. 
											Print out values in this form */
}
