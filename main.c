#include <unistd.h>
#include <glib/gprintf.h>
#include <i3ipc-glib/i3ipc-glib.h>

void sendCmd(i3ipcConnection *conn, char *str, int s) {
  gchar *reply;
  reply = i3ipc_connection_message(conn, I3IPC_MESSAGE_TYPE_COMMAND, str, NULL);
  g_printf("%s | %s\n", str, reply);
  g_free(reply);
  usleep(s * 1000);
}

void focusRoot(i3ipcConnection *conn) {
  sendCmd(conn, "focus parent",     0);
  sendCmd(conn, "focus parent",     0);
  sendCmd(conn, "focus parent",     0);
}

gint main() {
  i3ipcConnection *conn;
  conn = i3ipc_connection_new(NULL, NULL);

  focusRoot(conn);

  sendCmd(conn, "split h",          0);
  sendCmd(conn, "exec kitty --directory ~/ledger/ledger-live-mobile",     500);
  sendCmd(conn, "split v",          0);
  sendCmd(conn, "exec kitty --directory ~/ledger/ledger-live-mobile",     500);
  sendCmd(conn, "focus parent",   300);
  sendCmd(conn, "split h",        500);

  sendCmd(conn, "exec emulator -avd Pixel_2_API_28",     5000);
  sendCmd(conn, "exec kitty --directory ~/ledger/ledger-live-mobile",     500);
  sendCmd(conn, "split v",          0);
  sendCmd(conn, "exec kitty --directory ~/ledger/ledger-live-mobile",     500);

  g_object_unref(conn);
  return 0;
}
