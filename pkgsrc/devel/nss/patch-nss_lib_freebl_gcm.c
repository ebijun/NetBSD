--- nss/lib/freebl/gcm.c.orig	2020-01-24 07:22:25.000000000 +0900
+++ nss/lib/freebl/gcm.c	2020-04-21 13:40:49.562785558 +0900
@@ -21,8 +21,11 @@
 #if defined(__aarch64__) && defined(IS_LITTLE_ENDIAN) && \
     (defined(__clang__) || defined(__GNUC__) && __GNUC__ > 6)
 #define USE_ARM_GCM
-#elif defined(__arm__) && defined(IS_LITTLE_ENDIAN)
-/* We don't test on big endian platform, so disable this on big endian. */
+#elif defined(__arm__) && defined(IS_LITTLE_ENDIAN) && \
+    (defined(__ARM_NEON__) || defined(__ARM_NEON))
+/* We don't test on big endian platform, so disable this on big endian.
+ * Also, we don't check whether compiler support NEON well, so this uses
+ * that compiler uses -mfpu=neon only. */
 #define USE_ARM_GCM
 #endif
 
