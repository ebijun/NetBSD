$NetBSD$

Fix include path for SDL2. In pkgsrc, SDL2 headers are located 
under 'SDL2/' directory.

--- sdlxpm.h.orig	2026-04-09 05:50:39.000000000 +0900
+++ sdlxpm.h
@@ -5,5 +5,5 @@
 #ifndef SDLXPM_H
 #define SDLXPM_H
 
-#include "SDL.h"
+#include <SDL2/SDL.h>
 SDL_Surface *SDL_CreateRGBSurfaceFromXpm(char *[], Uint8 *);
