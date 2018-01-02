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

#include "gtkscope.h"
#include "gtkscopewin.h"
#include "menu.h"

G_DEFINE_TYPE(GtkScopeApp, gtkscope_app, GTK_TYPE_APPLICATION);

static void gtkscope_app_init(GtkScopeApp *app);
static void gtkscope_app_activate(GtkScopeApp *app);
static void gtkscope_app_open(GtkScopeApp *app, GFile **files, gint n_files, const gchar *hint);
static void gtkscope_app_class_init(GtkScopeAppClass *class);

int main(int argc, char *argv[])
{
        return g_application_run(G_APPLICATION(gtkscope_app_new()), argc, argv);
}


static void gtkscope_app_init(GtkScopeApp *app)
{
        ;
}

static void gtkscope_app_activate(GtkScopeApp *app)
{
        struct menu m; 
        GtkScopeAppWindow *win;
        GtkWidget *box;
        
        gtkscope_app_menu_init(&m);
        gtkscope_app_menu_items(&m);
        gtkscope_app_menu(&m);

        win = gtkscope_app_window_new (GTKSCOPE_APP(app));
        box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
        gtk_box_pack_start(GTK_BOX(box), (&m)->menubar, FALSE, FALSE, 3);
        gtk_container_add(GTK_CONTAINER(win), box);

        gtk_window_set_default_size(GTK_WINDOW(win), DEFAULT_WIDTH, DEFAULT_HEIGHT);
        gtk_window_set_title(GTK_WINDOW(win), "GTKScope");
        g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtkscope_app_exit), NULL);
        gtk_window_present (GTK_WINDOW(win));
        gtk_widget_show_all(box);
}

static void gtkscope_app_open(GtkScopeApp *app, GFile **files, gint n_files, const gchar *hint)
{
	GList *windows;
	GtkScopeAppWindow *win;
	int i;

	windows = gtk_application_get_windows (GTK_APPLICATION (app));
	if (windows)
		win = GTKSCOPE_APP_WINDOW (windows->data);
	else
		win = gtkscope_app_window_new (GTKSCOPE_APP (app));

	for (i = 0; i < n_files; i++)
		gtkscope_app_window_open (win, files[i]);

	gtk_window_present (GTK_WINDOW (win));
}

static void gtkscope_app_class_init (GtkScopeAppClass *class)
{
	G_APPLICATION_CLASS (class)->activate = (void* ) gtkscope_app_activate;
	G_APPLICATION_CLASS (class)->open = (void* ) gtkscope_app_open;
}

GtkScopeApp *gtkscope_app_new (void)
{
	return g_object_new (GTKSCOPE_APP_TYPE, "application-id", "org.gtk.gtkscope", "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}

void gtkscope_app_exit(GtkWidget *gtk_widget) 
{
        g_print("Exit pressed\n");
        exit(0);
}

