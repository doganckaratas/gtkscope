/**
 * GTKScope Project 
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#include <gtk/gtk.h>

#include "gtkscope.h"
#include "gtkscopewin.h"

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
