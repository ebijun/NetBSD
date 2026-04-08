$NetBSD$

Fix include path for SDL2 in sdlxpm.c to match pkgsrc structure.

--- sdlxpm.c.orig	2014-02-01 02:59:36.000000000 +0000
+++ sdlxpm.c
@@ -5,7 +5,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include "SDL.h"
+#include <SDL2/SDL.h>
 #include "sdlxpm.h"
 
 #define FALSE	0
