#include <gtk/gtk.h>

#include "gtkscope.h"
#include "gtkscopewin.h"

struct _GtkScopeAppWindow
{
	GtkApplicationWindow parent;
};

struct _GtkScopeAppWindowPrivate
{
	GSettings *settings;
	GtkWidget *stack;
	GtkWidget *search;
	GtkWidget *searchbar;
	GtkWidget *searchentry;
	GtkWidget *gears;
	GtkWidget *sidebar;
	GtkWidget *words;
	GtkWidget *lines;
	GtkWidget *lines_label;
};

typedef struct _GtkScopeAppWindowPrivate GtkScopeAppWindowPrivate;

G_DEFINE_TYPE(GtkScopeAppWindow, gtkscope_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void gtkscope_app_window_init (GtkScopeAppWindow *app)
{
	return;
}

static void gtkscope_app_window_class_init (GtkScopeAppWindowClass *class)
{
	return;
}

GtkScopeAppWindow * gtkscope_app_window_new (GtkScopeApp *app)
{
	return g_object_new (GTKSCOPE_APP_WINDOW_TYPE, "application", app, NULL);
}

void gtkscope_app_window_open (GtkScopeAppWindow *win, GFile *file)
{
	return;
}