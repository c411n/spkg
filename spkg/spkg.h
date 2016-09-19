#include "../libspkg/libspkg.h"

#ifndef SPKG_H_INCLUDED
#define SPKG_H_INCLUDED

/* First define this to be used on config struct */
typedef enum
{
  SPKG_NONE,
  SPKG_SHOW_HELP,
  SPKG_CREATE_PKG,
  SPKG_EXTRACT_PKG,
  SPKG_INIT_DB,
  SPKG_QUERY_DB,
  SPKG_INSTALL_PKGS,
  SPKG_REMOVE_PKGS,
  SPKG_UPGRADE_PKGS
} spkg_command_t;

/* Runtime configuration struct */
typedef struct
{
  char* spkg_os_type;
  char* spkg_system_arch;
  long spkg_total_memory;
  int spkg_cpu_count;
  char* spkg_kernel_version;
  spkg_list_t* spkg_handle_archs;

  char* spkg_default_root;
  spkg_command_t spkg_runtime_command;
  spkg_bool_t spkg_check_run_deps;
  spkg_bool_t spkg_check_run_conflicts;
  spkg_bool_t spkg_check_run_suggests;
  spkg_bool_t spkg_run_pkg_script;
  spkg_bool_t spkg_run_force_flag;
  spkg_bool_t spkg_run_verbose_mode;
  spkg_bool_t spkg_run_silent_mode;
} spkg_config_t;

#define SPKG_SHORT_OPTIONS      "hc:x:IQ:i:r:u:"
#define SPKG_SHOW_HELP_SHORT    'h'
#define SPKG_SHOW_HELP_LONG     "help"
#define SPKG_CREATE_PKG_SHORT   'c'
#define SPKG_CREATE_PKG_LONG    "create"
#define SPKG_EXTRACT_PKG_SHORT  'x'
#define SPKG_EXTRACT_PKG_LONG   "extract"
#define SPKG_INIT_DB_SHORT      'I'
#define SPKG_INIT_DB_LONG       "initdb"
#define SPKG_QUERY_DB_SHORT     'Q'
#define SPKG_QUERY_DB_LONG      "query"
#define SPKG_INSTALL_PKGS_SHORT 'i'
#define SPKG_INSTALL_PKGS_LONG  "install"
#define SPKG_REMOVE_PKGS_SHORT  'r'
#define SPKG_REMOVE_PKGS_LONG   "remove"
#define SPKG_UPGRADE_PKGS_SHORT 'u'
#define SPKG_UPGRADE_PKGS_LONG  "upgrade"

#define SPKG_DEFAULT_ROOT       "/"
#define SPKG_CHECK_RUN_DEPS       SPKG_TRUE
#define SPKG_CHECK_RUN_CONFLICTS  SPKG_TRUE
#define SPKG_CHECK_RUN_SUGGESTS   SPKG_TRUE
#define SPKG_RUN_PKG_SCRIPT       SPKG_TRUE
#define SPKG_RUN_FORCE_FLAG       SPKG_FALSE
#define SPKG_RUN_VERBOSE_MODE     SPKG_FALSE
#define SPKG_RUN_SILENT_MODE      SPKG_FALSE

/* Config object initiator */
int spkg_init_config(spkg_config_t* config);

/* Show runtime help */
void spkg_show_help(void);

#endif
