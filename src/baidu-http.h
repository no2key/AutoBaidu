/* The main interface for network.Base on libsoup. */

#ifndef __BAIDU_HTTP_H
#define __BAIDU_HTTP_H

#include <glib.h>
#include <libsoup/soup.h>
#include <config.h>

#include "baidu-user.h"

/* use asynchronous session for multiuser */




Request *request_new();
void request_delete();

GString *request_to_gstring(Request *re);

void request_set_method(Request *re, const char *m);
void request_set_uri(Request *re, const char *uri);
void request_set_version(Request *re, const char *version);
void request_add_header(Request *re, const gchar *name, const gchar *value);

void request_set_default_headers(Request *r, const GString *name);

void request_append_message(Request *re, const gchar *msg, gsize len);


#endif /* __BAIDU_HTTP_H */
