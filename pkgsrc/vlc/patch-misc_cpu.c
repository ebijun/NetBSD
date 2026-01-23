$NetBSD$

By removing VLC_ALTIVEC, the Altivec_test function reverts to being 
a plain static void function compiled with the standard C ABI. 
This resolves the compiler error, while the embedded asm volatile block 
still performs the Altivec instruction test correctly.

--- misc/cpu.c.org	2026-01-23 14:18:00.816652752 +0000
+++ misc/cpu.c
@@ -106,9 +106,13 @@ VLC_MMX static void ThreeD_Now_test (void)
 #endif
 
 #if defined (CAN_COMPILE_ALTIVEC)
-VLC_ALTIVEC static void Altivec_test (void)
+static void Altivec_test (void)
 {
-    asm volatile ("mtspr 256, %0\n" "vand %%v0, %%v0, %%v0\n" : : "r" (-1));
+    asm volatile (
+        "mtspr 256, %0\n"
+        "vand %%v0, %%v0, %%v0\n"
+        : : "r" (-1)
+    );
 }
 #endif
 
