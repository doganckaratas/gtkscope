/**
 * GTKScope Project
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#ifndef __GTKSCOPE_H
#define __GTKSCOPE_H

#include <gtk/gtk.h>

#define DEFAULT_WIDTH 1024
#define DEFAULT_HEIGHT 768
#define GTKSCOPE_APP_TYPE (gtkscope_get_type())

struct _GtkScope {
	GtkApplication parent;
};

G_DECLARE_FINAL_TYPE (GtkScope, gtkscope, GTKSCOPE, APP, GtkApplication)

GtkScope *gtkscope_new(void);
void gtkscope_exit(GtkWidget *gtk_widget);

#endif
