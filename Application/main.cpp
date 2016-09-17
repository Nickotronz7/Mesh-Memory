/**
 * Created by Nickotronz7
 */

#include <gtk-3.0/gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}

static gboolean
on_delete_event (GtkWidget *widget,
                 GdkEvent  *event,
                 gpointer   data)
{
    g_print ("delete event occurred\n");

    return TRUE;
}

int main(int argc, char* argv[])
{
    GtkWidget *window;
    GtkWidget *boton;
    GtkWidget *grid;

    /*----------CSS----------*/
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*----------------------*/

    gtk_init(&argc, &argv);

/////////////////////////////////////////////////////////////////////////////

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Mesh Mem Manager Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 1280,720);
    gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

    g_signal_connect(window, "delete-event", G_CALLBACK(on_delete_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

/////////////////////////////////////////////////////////////////////////////

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

/////////////////////////////////////////////////////////////////////////////
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                     " GtkWindow {\n"
                                             "   background-image: url('/home/nickotronz7/Pictures/Wallpapers/eli.jpg');\n"
                                             "}\n", -1, NULL);
    g_object_unref (provider);
////////////////////////////////////////////////////////////////////////////////

    boton = gtk_button_new_with_label("Print Something");
    gtk_button_set_image_position(GTK_BUTTON(boton), GTK_POS_BOTTOM);
    g_signal_connect(boton, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped(boton, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), boton, 0, 1, 2, 1);

/////////////////////////////////////////////////////////////////////////////

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}