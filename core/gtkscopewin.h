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
#include "gtkscope.h"


#define GTKSCOPE_APP_WINDOW_TYPE (gtkscope_app_window_get_type ())

G_DECLARE_FINAL_TYPE(GtkScopeAppWindow, gtkscope_app_window, GTKSCOPE, APP_WINDOW, GtkApplicationWindow);
//G_DEFINE_TYPE_WITH_PRIVATE(GtkScopeAppWindow, gtkscope_app_window, GTK_TYPE_APPLICATION_WINDOW);

GtkScopeAppWindow       *gtkscope_app_window_new       (GtkScopeApp *app);
void                    gtkscope_app_window_open      (GtkScopeAppWindow *win, GFile *file);

#endif
