/**
 * GTKScope Project
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#include <gtk/gtk.h>

#include "core/gtkscope.h"
#include "view/window.h"

G_DEFINE_TYPE(GtkScopeWindow, window, GTK_TYPE_APPLICATION_WINDOW);

static void window_init(GtkScopeWindow *app)
{
	return;
}

static void window_class_init(GtkScopeWindowClass *class)
{
	return;
}

GtkScopeWindow *window_new(GtkScope *app)
{
	return g_object_new (GTKSCOPE_WINDOW_TYPE, "application", app, NULL);
}

void window_open(GtkScopeWindow *win, GFile *file)
{
	return;
}
