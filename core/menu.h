#ifndef __MENU_H
#define __MENU_H

#include <gtk/gtk.h>

struct menu {
        GtkWidget *menubar;
        struct {
                GtkWidget *m_file;
                GtkWidget *s_file;
                struct {
                        GtkWidget *quit;
                } items;
        } file;
       
        struct {
                GtkWidget *m_edit;
                GtkWidget *s_edit;
                struct {
                        GtkWidget *cut;
                        GtkWidget *copy;
                        GtkWidget *paste;
                        GtkWidget *select_all;
                } items;
        } edit;

        struct {
                GtkWidget *m_help;
                GtkWidget *s_help;
                struct {
                        GtkWidget *about;
                } items;
        } help;
};

void gtkscope_app_menu_init(struct menu *m);
void gtkscope_app_menu_items(struct menu *m);
void gtkscope_app_menu(struct menu *m);

#endif 
