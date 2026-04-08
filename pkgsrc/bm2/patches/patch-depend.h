$NetBSD$

Fix include path for SDL2. In pkgsrc, SDL2 headers are located 
under 'SDL2/' directory. This patch updates the include directive 
to correctly locate 'SDL2/SDL.h'.

--- depend.h.orig	2024-12-07 23:58:43.000000000 +0000
+++ depend.h
@@ -6,7 +6,7 @@
 #if !defined(DEPEND_H)
 #define DEPEND_H
 
-#include "SDL.h"
+#include <SDL2/SDL.h>
 
 #if SDL_MAJOR_VERSION == 2
 #define printf	SDL_Log
