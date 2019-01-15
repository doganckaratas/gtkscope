/**
 * GTKScope Project
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#ifndef __GTKSCOPEWIN_H
#define __GTKSCOPEWIN_H

#include <gtk/gtk.h>
#include "core/gtkscope.h"

#define GTKSCOPE_WINDOW_TYPE (window_get_type())

struct _GtkScopeWindow
{
	GtkApplicationWindow parent;
};

struct _GtkScopeWindowPrivate
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

typedef struct _GtkScopeWindowPrivate GtkScopeWindowPrivate;

G_DECLARE_FINAL_TYPE(GtkScopeWindow, window, GTKSCOPE, WINDOW, GtkApplicationWindow);
//G_DEFINE_TYPE_WITH_PRIVATE(GtkScopeAppWindow, gtkscope_app_window, GTK_TYPE_APPLICATION_WINDOW);

GtkScopeWindow *window_new(GtkScope *app);
void window_open(GtkScopeWindow *win, GFile *file);

#endif
