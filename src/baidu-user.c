#include "autobaidu.h"
#include "baidu-user.h"

static void baidu_user_init(BaiduUser *user);
static void baidu_user_class_init(BaiduUserClass *class);

GType baidu_user_get_type(void)
{
	static GType t = 0;
	if (!t) {
		const GTypeInfo info = {
			sizeof(BaiduUserClass),
			NULL,
			NULL,
			(GClassInitFunc)baidu_user_class_init,
			NULL,
			NULL,
			sizeof(BaiduUser),
			0,
			(GInstanceInitFunc)baidu_user_init,
		};
		t = g_type_register_static(G_TYPE_OBJECT, "BaiduUser", 
				&info, 0);
	}
	return t;
}

BaiduUser *baidu_user_new(const gchar *name, const gchar *passwd)
{
	BaiduUser *user = g_object_new(baidu_user_get_type(), NULL);
	user->name = g_string_new(name);
	user->passwd = g_string_new(passwd);
	return user;
}

static void baidu_user_init(BaiduUser *baidu_user) 
{
	baidu_user->session = soup_session_sync_new();
}

static void baidu_user_class_init(BaiduUserClass *class)
{

}

void baidu_user_say_hello(BaiduUser *user)
{
	g_print("Baidu User %s, say hello!\n", user->name->str);
}

gboolean baidu_user_is_login(BaiduUser *user)
{
	SoupMessage *msg;
	SoupBuffer  *buffer;

	msg = soup_message_new_from_uri(soup_uri_new(TBS_URL));
	soup_message_headers_append(msg->request_header, "Cookie2", "");
	soup_message_headers_append(msg, "");
	soup_session_send_message(user->session, msg);
}

void baidu_user_login(BaiduUser *user)
{
	
}
