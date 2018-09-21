/*
 ** Copyright (©) 2016-2018 Matt Postiff.
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

#ifndef INCLUDED_WINDOW_TABBED_H
#define INCLUDED_WINDOW_TABBED_H

#include <gtk/gtk.h>
#include "ustring.h"
#include "reference.h"
#include "floatingwindow.h"
#include "htmlwriter2.h"
#include "editor.h"
#include <webkit2/webkit2.h>
#include "webview_simple.h"

//----------------------------------------------------------------------------------
// The tabbed window is a GTK notebook that can display information about the text
// or various built-in Bible versions. The first tab I created for this type window 
// was the concordance function, specifically the word frequency list. Eventually
// I would like to move the references, related verses, keyterms, and perhaps
// others into this structure to consolidate the view of things. The ultimate intent
// is to have multiple tabbed windows open at once.
//----------------------------------------------------------------------------------

class WindowTabbed; // forward declaration

// A tabbed (notebook) window can contain any number of SingleTab's. Each "thing" 
// that is intended to go into a tab should inherit from this class. For instance,
// a concordance tab "is" a SingleTab.
class SingleTab : webview_simple
{
public:
    SingleTab(const ustring &_title, HtmlWriter2 &html, GtkWidget *notebook, WindowTabbed *_parent);
    ~SingleTab();
    void updateHtml(HtmlWriter2 &html);
    GtkWidget *tab_label; // owned by the notebook, I think
    GtkWidget *webview; // owned by notebook
private:
    ustring title;
    WindowTabbed *parent;
    friend class WindowTabbed;
    
    // Callbacks. These routines are replicated several times throughout the code base. Any way to refactor so as to simplify?
    // You might think in the floating window base class, but some windows are webviews, and others are other custom things,
    // so that might not work too well!
    static gboolean
      on_decide_policy_cb (WebKitWebView           *web_view,
			   WebKitPolicyDecision    *decision,
			   WebKitPolicyDecisionType decision_type,
			   gpointer                 user_data);

    // void decide_policy_cb (called by above) is provided by the base class webview_simple
    // and the following has to be implemented by this class.
    void webview_process_navigation (const gchar * url);
    Reference get_reference (const ustring& text); // There is a to do here; see .cpp file
};

class WindowTabbed : public FloatingWindow
{
    friend class SingleTab;
public:
    WindowTabbed(ustring _title, GtkWidget * parent_layout, GtkAccelGroup *accelerator_group, bool startup);
    virtual ~WindowTabbed();
    void newTab(const ustring &tabTitle, HtmlWriter2 &tabHtml);    // create a new tab, fill with given content
    void updateTab(const ustring &tabTitle, HtmlWriter2 &tabHtml); // update existing tab, all new content
    GtkWidget * signalVerseChange;
    Reference *newReference; // for when a click in this window wants to navigate the program to a new Bible verse
  protected:
    ustring active_url;  
    Reference myreference;
  private:
    ustring title;
    GtkWidget *vbox;
    GtkWidget *notebook;
    vector<SingleTab *> tabs;
};

#endif
