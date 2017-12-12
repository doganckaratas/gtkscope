#ifndef __GTKSCOPE_H
#define __GTKSCOPE_H

#include <gtk/gtk.h>


#define GTKSCOPE_APP_TYPE (gtkscope_app_get_type ())
G_DECLARE_FINAL_TYPE (GtkScopeApp, gtkscope_app, GTKSCOPE, APP, GtkApplication)

GtkScopeApp     *gtkscope_app_new       (void);

#endif
