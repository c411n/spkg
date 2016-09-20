#include <stdlib.h>
#include "libspkg.h"

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct
{
	size_t size;
	char** vector;
} spkg_list_t;

spkg_list_t* spkg_new_list(void);
spkg_return_t spkg_append_to_list(spkg_list_t* list, char* member);
spkg_return_t spkg_print_list(spkg_list_t* list);
spkg_return_t spkg_destroy_list(spkg_list_t* list);

#endif
