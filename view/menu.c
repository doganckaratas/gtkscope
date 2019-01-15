/**
 * GTKScope Project
 * v0.1 - 12/2017
 * Dogan C. Karatas
 *
 * This code is released under GNU/GPL v3 License.
 * For more info, check out LICENSE file
 */

#include <gtk/gtk.h>
#include "view/window.h"
#include "view/menu.h"

void menu_init(struct menu *m)
{
	m->menubar = gtk_menu_bar_new();
	m->file.m_file = gtk_menu_new();
	m->edit.m_edit = gtk_menu_new();
	m->tools.m_tools = gtk_menu_new();
	m->help.m_help = gtk_menu_new();
}

void menu_show(struct menu *m)
{
	menu_file(m);
	menu_edit(m);
	menu_tools(m);
	menu_help(m);
}


void menu_file(struct menu *m)
{
	/* set label */
	m->file.s_file = gtk_menu_item_new_with_label("File");
	m->file.items.quit = gtk_menu_item_new_with_label("Quit");

	/* connect action */
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->file.s_file), m->file.m_file);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->file.s_file);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->file.m_file), m->file.items.quit);
	g_signal_connect(G_OBJECT(m->file.items.quit), "activate", G_CALLBACK(gtkscope_exit), NULL);
}

void menu_edit(struct menu *m)
{
	m->edit.s_edit = gtk_menu_item_new_with_label("Edit");
	m->edit.items.cut = gtk_menu_item_new_with_label("Cut");
	m->edit.items.copy = gtk_menu_item_new_with_label("Copy");
	m->edit.items.paste = gtk_menu_item_new_with_label("Paste");
	m->edit.items.select_all = gtk_menu_item_new_with_label("Select All");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->edit.s_edit), m->edit.m_edit);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->edit.s_edit);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.cut);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.copy);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.paste);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->edit.m_edit), m->edit.items.select_all);
}

void menu_tools(struct menu *m)
{
	m->tools.s_tools = gtk_menu_item_new_with_label("Tools");
	m->tools.items.preferences = gtk_menu_item_new_with_label("Preferences");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->tools.s_tools), m->tools.m_tools);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->tools.s_tools);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->tools.m_tools), m->tools.items.preferences);
}

void menu_help(struct menu *m)
{
	m->help.s_help = gtk_menu_item_new_with_label("Help");
	m->help.items.about = gtk_menu_item_new_with_label("About");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(m->help.s_help), m->help.m_help);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->menubar), m->help.s_help);
	gtk_menu_shell_append(GTK_MENU_SHELL(m->help.m_help), m->help.items.about);
}
