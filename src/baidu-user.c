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
		t = g_type_register_static(G_TYPE_INTERFACE, "BaiduUser", 
				&info, 0);
	}
	return t;
}

BaiduUser *baidu_user_new(const gchar *name, const gchar *passwd)
{
	return BAIDU_USER(g_object_new(baidu_user_get_type(),
				"name", name,
				"passwd", passwd,
				NULL));
}

static void baidu_user_init(BaiduUser *baidu_user) 
{

}

static void baidu_user_class_init(BaiduUserClass *class)
{

}
