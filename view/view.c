/**
 * GTKScope Project
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <gtk/gtk.h>

#include "view/window.h"
#include "view/view.h"
#include "view/menu.h"

void view_init(GtkScope *app, struct menu *m)
{
	GtkWidget *view;
	GtkTextBuffer *buffer;
	GtkScopeWindow *win;
	GtkWidget *box;

	/* Dummy View */
	view = gtk_text_view_new();
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	gtk_text_buffer_set_text(buffer, "", -1);

	win = window_new(GTKSCOPE_APP(app));
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_box_pack_start(GTK_BOX(box), (m)->menubar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), view, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(win), box);

	gtk_window_set_default_size(GTK_WINDOW(win), DEFAULT_WIDTH, DEFAULT_HEIGHT);
	gtk_window_set_title(GTK_WINDOW(win), "GTKScope");
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtkscope_exit), NULL);
	gtk_window_present (GTK_WINDOW(win));
	gtk_widget_show_all(box);
}

void view_args_init(GtkScope *app, struct menu *m)
{
#if 0
	GtkWidget *view;
	GtkTextBuffer *buffer;
	GtkScopeAppWindow *win;
	GtkWidget *box;

	/* Dummy View */
	view = gtk_text_view_new();
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	gtk_text_buffer_set_text(buffer, "", -1);

	win = gtkscope_app_window_new (GTKSCOPE_APP(app));
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_box_pack_start(GTK_BOX(box), (m)->menubar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), view, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(win), box);

	gtk_window_set_default_size(GTK_WINDOW(win), DEFAULT_WIDTH, DEFAULT_HEIGHT);
	gtk_window_set_title(GTK_WINDOW(win), "GTKScope");
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtkscope_app_exit), NULL);
	gtk_window_present (GTK_WINDOW(win));
	gtk_widget_show_all(box);
#endif
}
