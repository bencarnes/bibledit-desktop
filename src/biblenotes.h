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


#ifndef INCLUDED_BIBLENOTES_H
#define INCLUDED_BIBLENOTES_H


#include "libraries.h"
#include "types.h"


ustring biblenotes_get_note_marker (NoteType notetype);
NoteType biblenotes_get_note_type (const ustring& text);
ustring biblenotes_get_note_caller (NumberingType numberingtype, char * character);
void biblenotes_get_note_numbering (const ustring& caller, NumberingType& numberingtype, ustring& character);
void biblenotes_extract_note_opener_caller_closer (const ustring& text, 
                                                   ustring& opener, ustring& caller, ustring& closer);
ustring biblenotes_extract_note_body (ustring text);
void biblenotes_switch_markers (ustring& bodytext, gchar * from_marker, gchar * to_marker);


#endif