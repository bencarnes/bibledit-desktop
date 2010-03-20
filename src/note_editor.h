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

#ifndef INCLUDED_NOTE_EDITOR_H
#define INCLUDED_NOTE_EDITOR_H

#include "libraries.h"
#include <gtk/gtk.h>
extern "C" {
#include <gtkhtml/gtkhtml.h>
}

class NoteEditor
// Used while a note is being edited.
{
public:
  NoteEditor(int dummy);
  ~NoteEditor();
  int id;
  bool newnote;
  unsigned int date_created;
  unsigned int date_modified;
  ustring created_by;
  GtkTextBuffer * textbuffer_references;
  ustring previous_category;
  ustring previous_project;
  void store_original_data (const ustring& data);
  void receive_data_from_html_editor(const char *data, unsigned int len);
  ustring clean_edited_data();
  bool data_was_edited ();
private:
  ustring original_data;
  ustring edited_data;
};

vector <ustring> note_editor_font_size_names_list ();
GtkHTMLFontStyle note_editor_font_size_name_to_enum (const ustring& style);
ustring note_editor_font_size_enum_to_name (GtkHTMLFontStyle style);
vector <ustring> note_editor_paragraph_style_names_list ();
GtkHTMLParagraphStyle note_editor_paragraph_style_name_to_enum (const ustring& style);
ustring note_editor_paragraph_style_enum_to_name (GtkHTMLParagraphStyle style);

#endif