#include <stdio.h>
#include <stdlib.h>
#include "libspkg.h"
#include "list.h"

spkg_list_t* spkg_new_list(void)
{
	spkg_list_t* list = malloc(sizeof(spkg_list_t));

	list->size = 0;
	list->vector = malloc(sizeof(char**)*0);
	list->vector[0] = NULL;

	return list;
}

spkg_return_t spkg_append_to_list(spkg_list_t* list, char* member)
{
	size_t new_size = list->size + 1;
	char** new_vector = realloc(list->vector,new_size*sizeof(char*));
	size_t index = (new_size > 0) ? new_size -1 : new_size;

	list->size = new_size;
	list->vector = new_vector;
	list->vector[index] = member;

	return SPKG_SUCCESS;
}

spkg_return_t spkg_print_list(spkg_list_t* list)
{
	if(list->size > 0)
	{
		for(int i=0; i<list->size; i++)
			printf("%s\n", list->vector[i]);
	}

	return SPKG_SUCCESS;
}

spkg_return_t spkg_destroy_list(spkg_list_t* list)
{
	free(list->vector);
	free(list);

	return SPKG_SUCCESS;
}
