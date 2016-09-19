#include <libintl.h>

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifndef _
#define _(STRING) gettext(STRING)
#endif

#ifndef LIBSPKG_H_INCLUDED
#define LIBSPKG_H_INCLUDED

typedef enum
{
  SPKG_FALSE,
  SPKG_TRUE
} spkg_bool_t;

typedef enum
{
  SPKG_SUCCESS,
  SPKG_FAILED,
  SPKG_PERM_DENIED,
  SPKG_FILE_NOT_FOUND,
  SPKG_DIR_NOT_FOUND,
  SPKG_FAILED_TO_CREATE,
  SPKG_FAILED_TO_REMOVE
} spkg_return_t;

#endif
