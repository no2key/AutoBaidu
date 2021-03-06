#ifndef __BAIDU_USER_H
#define __BAIDU_USER_H

#include <glib-object.h>
#include <libsoup/soup.h>

#define BAIDU_USER(obj)		G_TYPE_CHECK_INSTANCE_CAST(obj, \
					baidu_user_get_type(), BaiduUser)
#define BAIDU_USER_CLASS(c)	G_TYPE_CHECK_CLASS_CAST(c, \
					baidu_user_get_type(), BaiduUserClass)
#define BAIDU_IS_USER(obj)	G_TYPE_CHECK_INSTANCE_TYPE(obj, \
					baidu_user_get_type())

typedef struct _BaiduUser	BaiduUser;
typedef struct _BaiduUserClass	BaiduUserClass;




struct _BaiduUser {
	GObject parent;
	GString *name;
	GString *passwd;

	SoupSession *session;

};

struct _BaiduUserClass {
	GObjectClass parent;
};

GType baidu_user_get_type(void);

BaiduUser *baidu_user_new(const gchar *name, const gchar *passwd);

void baidu_user_say_hello(BaiduUser *user);

gboolean baidu_user_is_login(BaiduUser *user);
void baidu_user_login(BaiduUser *user);

void baidu_user_reply(BaiduUser *user);
void baidu_user_post(BaiduUser *user);

void baidu_user_get_verify_code(BaiduUser *user);


#endif /* __BAIDU_USER_H */
