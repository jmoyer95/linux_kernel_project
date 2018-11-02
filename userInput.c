#include<stdio.h>
#include<gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}



static void initialize_window(GtkWidget* window)
{
  gtk_window_set_title(GTK_WINDOW(window),"KeyLogger");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 300); 
  g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL); 
}

  int main( int  argc,  char *argv[] )  
  {  
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *table;
    gtk_init (&argc, &argv);  
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    initialize_window(window);
    table = gtk_table_new (1, 2, TRUE);
    gtk_container_add (GTK_CONTAINER (window), table);
    label = gtk_label_new("Please enter the name of the file you want the keystrokes to print to");
    gtk_table_set_homogeneous(GTK_TABLE (table), TRUE);
  gtk_table_attach_defaults (GTK_TABLE (table), label, 1, 2, 0, 1);
  entry = gtk_entry_new ();
  gtk_entry_set_max_length (GTK_ENTRY (entry),0);
  gtk_table_attach_defaults (GTK_TABLE (table), entry, 0, 1, 0, 1);
    gtk_widget_show_all (window);  
    gtk_main ();  
    return 0;  
  }  

