#include "baidu-http.h"

static void get_cookie();

void request_add_header(Request *req, const gchar *name, const gchar *value)
{
	if (req == NULL || name == NULL)
		return;
	GString *k = g_string_new(name);
	GString *v = g_string_new(value);
	g_tree_insert(req->headers, k, v);
}


