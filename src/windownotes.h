/*
 ** Copyright (©) 2003-2009 Teus Benschop.
 **  
 ** This program is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 3 of the License, or
 ** (at your option) any later version.
 **  
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **  
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 **  
 */


#ifndef INCLUDED_WINDOW_NOTES_H
#define INCLUDED_WINDOW_NOTES_H


#include <gtk/gtk.h>
#include "ustring.h"
#include "floatingwindow.h"
#include "reference.h"
extern "C" {
#include <gtkhtml/gtkhtml.h>
}
#include "note_editor.h"
#include "displayprojectnotes.h"


class WindowNotes : public FloatingWindow
{
public:
  WindowNotes(GtkWidget * parent_layout, GtkAccelGroup *accelerator_group, bool startup);
  virtual ~WindowNotes();
  void go_to(Reference& reference);
  void new_note();
  void redisplay(bool immediately = false);
  void display(vector <unsigned int>& ids);
  void insert_standard_text(unsigned int selector);
  void get_references_from_note(vector<Reference>& references, vector<ustring>& messages);
  void cut();
  void copy();
  void paste();
  void undo();
  void redo();
  void decrease_indent();
  void increase_indent();
  bool note_being_edited();
  GtkWidget * references_available_signal_button;
  vector<Reference> available_references;
private:
  GtkWidget *notebook1;
  GtkWidget *scrolledwindow_notes;
  GtkWidget *htmlview_notes;
  GtkWidget *hbox14;
  GtkWidget *vbox_note_editor;
  GtkWidget *toolbar_note_editor;
  GtkWidget *toolitem_note_edit_font_size;
  GtkWidget *combobox_note_edit_font_size;
  GtkWidget *toolitem_note_edit_paragraph_style;
  GtkWidget *combobox_note_edit_paragraph_style;
  GtkWidget *toolitem_note_edit_bold;
  GtkWidget *togglebutton_note_edit_bold;
  GtkWidget *image29121;
  GtkWidget *toolitem_note_edit_italics;
  GtkWidget *togglebutton_note_edit_italics;
  GtkWidget *image29122;
  GtkWidget *toolitem_note_edit_underline;
  GtkWidget *togglebutton_note_edit_underline;
  GtkWidget *image29114;
  GtkWidget *toolitem_note_edit_strike_through;
  GtkWidget *togglebutton_note_edit_strike_through;
  GtkWidget *image29123;
  GtkWidget *toolitem_note_edit_left_justify;
  GtkWidget *togglebutton_note_edit_left_justify;
  GtkWidget *image29124;
  GtkWidget *toolitem_note_edit_center_justify;
  GtkWidget *togglebutton_note_edit_center_justify;
  GtkWidget *image29125;
  GtkWidget *toolitem_note_edit_right_justify;
  GtkWidget *togglebutton_note_edit_right_justify;
  GtkWidget *image29126;
  GtkWidget *toolitem_note_edit_decrease_indent;
  GtkWidget *button_note_edit_decrease_indent;
  GtkWidget *image29127;
  GtkWidget *toolitem_note_edit_increase_indent;
  GtkWidget *button_note_edit_increase_indent;
  GtkWidget *image29128;
  GtkWidget *toolitem_note_edit_color;
  GtkWidget *colorbutton_note_edit;
  GtkWidget *scrolledwindow_note_editor;
  GtkWidget *htmlview_note_editor;
  GtkWidget *scrolledwindow_controls;
  GtkWidget *vbox_controls;
  GtkWidget *hbox_ok_cancel;
  GtkWidget *button_note_ok;
  GtkWidget *button_note_cancel;
  GtkWidget *button_more;
  GtkWidget *alignment1;
  GtkWidget *hbox15;
  GtkWidget *image1;
  GtkWidget *label1;
  GtkWidget *label_note_category;
  GtkWidget *combobox_note_category;
  GtkWidget *label_note_references;
  GtkWidget *scrolledwindow8;
  GtkWidget *textview_note_references;

  bool project_notes_editable;

  NoteEditor * note_editor;
  void notes_fill_edit_screen(int id, bool newnote);

  // Formatting
  static void on_combobox_note_edit_font_size_changed(GtkComboBox *combobox, gpointer user_data);
  void combobox_note_edit_font_size_changed();
  static void on_note_editor_insertion_font_style_changed(GtkHTML * html, GtkHTMLFontStyle style, gpointer user_data);
  void note_editor_insertion_font_style_changed(GtkHTMLFontStyle style);
  static void on_combobox_note_edit_paragraph_style_changed(GtkComboBox *combobox, gpointer user_data);
  void combobox_note_edit_paragraph_style_changed();
  static void on_note_editor_current_paragraph_style_changed(GtkHTML * html, GtkHTMLParagraphStyle style, gpointer user_data);
  void note_editor_current_paragraph_style_changed(GtkHTMLParagraphStyle style);
  static void on_togglebutton_note_edit_bold_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_bold_toggled();
  static void on_togglebutton_note_edit_italics_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_italics_toggled();
  static void on_togglebutton_note_edit_underline_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_underline_toggled();
  static void on_togglebutton_note_edit_strike_through_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_strike_through_toggled();
  static void on_togglebutton_note_edit_left_justify_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_left_justify_toggled();
  static void on_togglebutton_note_edit_center_justify_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_center_justify_toggled();
  static void on_togglebutton_note_edit_right_justify_toggled(GtkToggleButton *togglebutton, gpointer user_data);
  void togglebutton_note_edit_right_justify_toggled();
  static void on_current_paragraph_alignment_changed(GtkHTML *html, GtkHTMLParagraphAlignment new_alignment, gpointer user_data);
  void current_paragraph_alignment_changed(GtkHTMLParagraphAlignment new_alignment);
  static void on_button_note_edit_decrease_indent_clicked(GtkButton *button, gpointer user_data);
  static void on_button_note_edit_increase_indent_clicked(GtkButton *button, gpointer user_data);
  static void on_current_paragraph_indentation_changed(GtkHTML *html, guint new_indentation, gpointer user_data);
  void current_paragraph_indentation_changed(guint new_indentation);
  static void on_colorbutton_note_edit_color_set(GtkColorButton *colorbutton, gpointer user_data);
  void colorbutton_note_edit_color_set(GtkColorButton *colorbutton);
  static void on_insertion_color_changed(GtkHTML *html, GdkColor *color, gpointer user_data);
  void insertion_color_changed(GdkColor *color);

  guint redisplay_source_id;
  static bool on_redisplay_timeout(gpointer data);
  void redisplay_timeout();
  void stop_displaying_more_notes();
  DisplayProjectNotes * displayprojectnotes;

  guint gui_source_id;
  static bool on_gui_timeout(gpointer data);
  void on_gui();

  static void on_button_cancel_clicked(GtkButton *button, gpointer user_data);
  void on_notes_button_cancel();
  static void on_button_ok_clicked(GtkButton *button, gpointer user_data);
  void on_notes_button_ok();
  void on_notes_button_ok_cancel();
  static gboolean note_save_receiver(const HTMLEngine * engine, const char *data, unsigned int len, void *user_data);

  void get_references_from_id(gint id);

  static gboolean on_html_link_clicked(GtkHTML *html, const gchar * url, gpointer user_data);
  void html_link_clicked(GtkHTML *html, const gchar * url);
  void delete_ids(const vector<gint>& ids);

  static void on_button_more_clicked(GtkButton *button, gpointer user_data);
  void on_button_more();
  vector <ustring> projects;
  ustring project;
  ustring created_on;
  ustring created_by;
  ustring edited_on;
  ustring logbook;
  
  unsigned int edited_note_id;
};

#endif