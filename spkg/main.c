#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

#include "../libspkg/libspkg.h"
#include "../libspkg/list.h"
#include "spkg.h"


int main(int argc, char* argv[])
{
  spkg_config_t config;
  if ( (spkg_init_config(&config)) != 0 )
  {
    printf(_("Failed to fill runtime config\n"));
    exit(SPKG_FAILED);
  }


  unsigned short int action = 0;
  short int next_opt;
  char* short_opts = SPKG_SHORT_OPTIONS;
  const struct option long_opts[] =
  {
  	{SPKG_SHOW_HELP_LONG,      0, NULL, SPKG_SHOW_HELP_SHORT},
    {SPKG_INIT_DB_LONG,        0, NULL, SPKG_INIT_DB_SHORT  },
  	{NULL,		                 0, NULL,                    0}
  };

  while(1)
  {
  	next_opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
  	if(next_opt == -1)
  		break;

    switch(next_opt)
    {
      case SPKG_SHOW_HELP_SHORT:
        config.spkg_runtime_command = SPKG_SHOW_HELP;
        break;
      case SPKG_INIT_DB_SHORT:
        config.spkg_runtime_command = SPKG_INIT_DB;
        break;
      case '?':
        exit(SPKG_FAILED);
    }
  }

  if (config.spkg_runtime_command == SPKG_NONE)
  {
  	printf(_("No main options was selected\n"));
  	exit(EXIT_FAILURE);
  }

  if (config.spkg_runtime_command == SPKG_SHOW_HELP)
  {
    spkg_show_help();
  	exit(SPKG_SUCCESS);
  }

	int i=0, c=0;

	spkg_list_t* pkgv = spkg_new_list();
  if (optind < argc && optind > 1)
	{
		for (i=optind; i<argc; i++)
		{
      spkg_append_to_list(pkgv, argv[i]);
			c++;
		}
	}

  return SPKG_SUCCESS;
}
