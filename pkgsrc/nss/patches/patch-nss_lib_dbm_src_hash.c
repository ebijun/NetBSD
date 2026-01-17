--- nss/lib/dbm/src/hash.c	2026/01/17 05:44:26	1.1
+++ nss/lib/dbm/src/hash.c	2026/01/17 05:44:52
@@ -32,6 +32,8 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/endian.h>
+
 #if defined(LIBC_SCCS) && !defined(lint)
 static char sccsid[] = "@(#)hash.c  8.9 (Berkeley) 6/16/94";
 #endif /* LIBC_SCCS and not lint */
