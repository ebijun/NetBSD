* http://www.netside.co.jp/~mochid/comp/bsd44-build/

--- vm/ram.cpp	2021/12/12 22:51:37	1.1
+++ vm/ram.cpp	2021/12/12 22:52:05
@@ -375,7 +375,8 @@
 	}
 	if (mid_mismatch) {
 		warnx("%s \"%s\" machine id $%03x mismatch", __func__, name, mid);
-		return 0;
+#define AOUT_MID_HP300 0x12c	/* hp300 (68020+68881) BSD binary */
+		if (mid != AOUT_MID_HP300) return 0;
 	}
 
 	putmsg(1, "%s textsize    = %08x", __func__, aout.textsize);
