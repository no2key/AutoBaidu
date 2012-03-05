#include <stdlib.h>
#include <glib.h>
#include <config.h>

#include "autobaidu.h"
#include "baidu-user.h"



static gboolean _print_help_and_exit(const gchar *option_name, 
					const gchar *value, gpointer data,
					GError **error)
{
	g_print("%s %s\n", PACKAGE, VERSION);
	exit(EXIT_SUCCESS);
	return TRUE;
}

gboolean debug = FALSE;
gboolean verbose = FALSE;

GOptionEntry entries[] = 
{
	{"verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "open verbose mode", 
		NULL},
	{"debug", 'd', 0, G_OPTION_ARG_NONE, &debug, "open debug mode", NULL},
	{"version", 0, G_OPTION_FLAG_NO_ARG, G_OPTION_ARG_CALLBACK, 
		_print_help_and_exit, 
		"print the application's version", NULL},
	{NULL}
};




gint main(gint argc, gchar **argv)
{
	GError *error = NULL;
	GOptionContext *context;
	context = g_option_context_new(NULL);
	g_option_context_add_main_entries(context, entries, NULL);

	if (!g_option_context_parse(context, &argc, &argv, &error)) {
		g_print("option parsing failed: %s\n", error->message);
		exit(EXIT_FAILURE);
	}
	g_option_context_free(context);

	
	/* initialization */
	g_type_init();
	
	
	
	/* test */
	BaiduUser *user;
	user = baidu_user_new("crab2313", "xxxx");
	baidu_user_say_hello(user);
	return 0;
}
