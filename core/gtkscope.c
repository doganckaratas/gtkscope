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
#include "view.h"
#include "menu.h"

G_DEFINE_TYPE(GtkScopeApp, gtkscope_app, GTK_TYPE_APPLICATION);

static void gtkscope_app_init(GtkScopeApp *app);
static void gtkscope_app_activate(GtkScopeApp *app);
static void gtkscope_app_open(GtkScopeApp *app, GFile **files, gint n_files, const gchar *hint);
static void gtkscope_app_class_init(GtkScopeAppClass *class);

/* TODO
 * XXX Move all view related things into view folder,
 * Provide nice and clean API just like menu.h
 * Add event handlers
 * GtkSourceView or Scintilla integration
 * XXX Fix destroy event, that cause killing all instances when closing single window
 */

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
	/* run with no arguments */
        struct menu m; 
        
        gtkscope_app_menu_init(&m);
        gtkscope_app_menu_items(&m);
        gtkscope_app_menu(&m);

	gtkscope_app_view_init(app, &m);
}

static void gtkscope_app_open(GtkScopeApp *app, GFile **files, gint n_files, const gchar *hint)
{
	/* run with arguments */
	/* FIXME: move this to view.c */
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
        return;
}

