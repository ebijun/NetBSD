$NetBSD$

--- src/apppstatus.cc.orig	2013-10-18 04:07:42.000000000 +0000
+++ src/apppstatus.cc
@@ -82,7 +82,9 @@ NetStatus::NetStatus(mstring netdev, IAp
 }
 
 NetStatus::~NetStatus() {
-    delete[] color;
+    delete color[0];
+    delete color[1];
+    delete color[2];
     delete[] ppp_in;
     delete[] ppp_out;
     delete fUpdateTimer;
