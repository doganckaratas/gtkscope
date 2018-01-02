/**
 * GTKScope Project 
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#include <gtk/gtk.h>
#include "gtkscopewin.h"
#include "menu.h"

void gtkscope_app_menu_init(struct menu *m)
{
        m->menubar = gtk_menu_bar_new();
        m->file.m_file = gtk_menu_new();
        m->edit.m_edit = gtk_menu_new();
        m->help.m_help = gtk_menu_new();
}

void gtkscope_app_menu_items(struct menu *m)
{
        m->file.s_file = gtk_menu_item_new_with_label("File");
        m->file.items.quit = gtk_menu_item_new_with_label("Quit");
        m->edit.s_edit = gtk_menu_item_new_with_label("Edit");
        m->edit.items.cut = gtk_menu_item_new_with_label("Cut");
        m->edit.items.copy = gtk_menu_item_new_with_label("Copy");
        m->edit.items.paste = gtk_menu_item_new_with_label("Paste");
        m->edit.items.select_all = gtk_menu_item_new_with_label("Select All");
        m->help.s_help = gtk_menu_item_new_with_label("Help");
        m->help.items.about = gtk_menu_item_new_with_label("About");
}

void gtkscope_app_menu(struct menu *m)
{
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->file.s_file), m->file.m_file);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->file.s_file);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->file.m_file), m->file.items.quit);
        g_signal_connect(G_OBJECT(m->file.items.quit), "activate", G_CALLBACK(gtkscope_app_exit), NULL);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->edit.s_edit), m->edit.m_edit);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->edit.s_edit);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.cut);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.copy);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.paste);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.select_all);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->help.s_help), m->help.m_help);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->help.s_help);
        gtk_menu_shell_append(GTK_MENU_SHELL(m->help.m_help), m->help.items.about);
}

