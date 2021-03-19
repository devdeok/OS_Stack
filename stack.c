/**********************************************************************
 * Copyright (c) 2021
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

/*====================================================================*/
/*          ****** DO NOT MODIFY ANYTHING FROM THIS LINE ******       */
#include <stdio.h>
#include "types.h"
#include "list_head.h"

/* Declaration for the stack instance defined in pa0.c */
extern struct list_head stack;

/* Entry for the stack */
struct entry {
	struct list_head list;
	char *string;
};
/*          ****** DO NOT MODIFY ANYTHING ABOVE THIS LINE ******      */
/*====================================================================*/

/*====================================================================*
 * The rest of this file is all yours. This implies that you can      *
 * include any header files if you want to ...                        */

#include <stdlib.h>                    /* like this */
#include <string.h>
#define MAX_BUFFER 80

struct entry *temp;
struct entry *cur;
struct entry *curn;

/**
 * push_stack()
 *
 * DESCRIPTION
 *   Push @string into the @stack. The @string should be inserted into the top
 *   of the stack. You may use either the head or tail of the list for the top.
 */

void push_stack(char *string)
{	
	/* TODO: Implement this function */
	char* tmpstr = malloc(sizeof(char)*MAX_BUFFER);
	strcpy(tmpstr,string);

	temp = (struct entry *)malloc(sizeof(struct list_head));
	temp->string = tmpstr;
	INIT_LIST_HEAD(&temp->list);
	list_add_tail(&temp->list,&stack);
}

/**
 * pop_stack()
 *
 * DESCRIPTION
 *   Pop a value from @stack and return it through @buffer. The value should
 *   come from the top of the stack, and the corresponding entry should be
 *   removed from @stack.
 *
 * RETURN
 *   If the stack is not empty, pop the top of @stack, and return 0
 *   If the stack is empty, return -1
 */
int pop_stack(char *buffer)
{
	/* TODO: Implement this function */

	// buffer에 string을 담고 stack의 top부분에 entry의 string을 pop한다.
	// stack이 비어있으면 -1을 return , 그러므로 stack이 비어있는지 체크해주어야함

	if(!list_empty(&stack)){ // stack이 비어있지 않다면
		list_for_each_entry_safe(cur,curn,&stack,list){ // top까지 순회
			if(list_is_last(&cur->list,&stack)){ // cur->list->next == stack
				// printf("top string : %s\n",cur->string);
				strcpy(buffer,cur->string); // 맞다면 string을 buffer에 복사하고
				list_del(&cur->list);
				// printf("complete delete!!\n");
			}
		}
		return 0;
	}

	return -1; /* Must fix to return a proper value when @stack is not empty */
}

/**
 * dump_stack()
 *
 * DESCRIPTION
 *   Dump the contents in @stack. Print out @string of stack entries while
 *   traversing the stack from the bottom to the top. Note that the value
 *   should be printed out to @stderr to get properly graded in pasubmit.
 */
void dump_stack(void)
{
	/* TODO: Implement this function */
	list_for_each_entry(cur,&stack,list){
		fprintf(stderr, "%s\n", cur->string);
	}
	 /* Example. 
											Print out values in this form */
}