#ifndef __MARKER_EDITOR_WINDOW_H__
#define __MARKER_EDITOR_WINDOW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MARKER_TYPE_EDITOR_WINDOW (marker_editor_window_get_type ())

G_DECLARE_FINAL_TYPE(MarkerEditorWindow,
                     marker_editor_window,
                     MARKER,
                     EDITOR_WINDOW,
                     GtkApplicationWindow)

typedef enum
{
    HTML,
    PDF,
    RTF,
    EPUB,
    ODT,
    DOCX,
    LATEX
} MarkerFileFormat;

typedef struct
{
    MarkerFileFormat file_type;
    char* style_sheet;
} MarkerExportSettings;

MarkerEditorWindow*
marker_editor_window_new(GtkApplication* app);

MarkerEditorWindow*
marker_editor_window_new_from_file(GtkApplication* app,
                                   GFile*          file);

void
marker_editor_window_refresh_web_view(MarkerEditorWindow* window);

void
marker_editor_window_open_file(MarkerEditorWindow* window,
                               GFile*              file);

void
marker_editor_window_save_file_as(MarkerEditorWindow* window,
                                  GFile*              file);
                                  
void
marker_editor_window_export_file_as(MarkerEditorWindow*  window,
                                    GFile*               file,
                                    MarkerExportSettings settings);

void
marker_editor_window_set_css_theme(MarkerEditorWindow* window,
                                      char*               theme);
                                    
void
marker_editor_window_set_syntax_theme(MarkerEditorWindow* window,
                                      char*               theme);
                                      
void
marker_editor_window_try_close(MarkerEditorWindow* window);

void
marker_editor_window_set_show_line_numbers(MarkerEditorWindow* window,
                                           gboolean            line_nums);

void                                           
marker_editor_window_set_highlight_current_line(MarkerEditorWindow* window,
                                                gboolean            highlight);

void                                           
marker_editor_window_show_right_margin(MarkerEditorWindow* window,
                                       gboolean            margin);

G_END_DECLS

#endif

