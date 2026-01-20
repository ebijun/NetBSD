--- nss/lib/dbm/src/h_page.c	2026/01/17 05:38:42	1.1
+++ nss/lib/dbm/src/h_page.c	2026/01/17 05:40:25
@@ -32,6 +32,8 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/endian.h>
+
 #if defined(unix)
 #define MY_LSEEK lseek
 #else
