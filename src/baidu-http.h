#ifndef __BAIDU_HTTP_H
#define __BAIDU_HTTP_H


typedef struct {
	GString *version;
	GString *status;
	GString *reson;

	GTree *headers;
	GString *msg;
} Response;


typedef struct {
	GString *method;
	GString *uri;
	GString *version;

	GTree *headers;
	GString *msg;
} Request;

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
