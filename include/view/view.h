#ifndef __VIEW_H
#define __VIEW_H

#include <gtk/gtk.h>

#include "menu.h"

void view_init(GtkScope *app, struct menu *m);
void view_args_init(GtkScope *app, struct menu *m);
#endif
