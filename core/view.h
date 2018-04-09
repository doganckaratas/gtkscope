#ifndef __VIEW_H
#define __VIEW_H

#include <gtk/gtk.h>

#include "menu.h"

void gtkscope_app_view_init(GtkScopeApp *app, struct menu *m);
void gtkscope_app_view_args_init(GtkScopeApp *app, struct menu *m);
#endif
