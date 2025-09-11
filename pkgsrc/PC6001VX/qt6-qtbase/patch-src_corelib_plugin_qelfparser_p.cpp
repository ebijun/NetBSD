* https://mail-index.netbsd.org/pkgsrc-bugs/2025/09/07/msg074314.html by tsutsui@ san.

--- src/corelib/plugin/qelfparser_p.cpp.orig	2024-10-01 10:46:30.000000000 +0000
+++ src/corelib/plugin/qelfparser_p.cpp
@@ -619,15 +619,15 @@ static QLibraryScanResult scanProgramHea
             // overflow check: calculate where the next note will be, if it exists
             T::Off next_offset = offset;
             next_offset += sizeof(T::Nhdr);          // can't overflow (we checked above)
-            next_offset += NoteAlignment - 3;        // offset is aligned, this can't overflow
-            if (qAddOverflow<T::Off>(next_offset, n_namesz, &next_offset))
+            // roundup n_namesz and n_descsz to NoteAlignment
+            const T::Off AlignOffset = T::Off(NoteAlignment - 1);
+            const T::Off AlignMask = ~AlignOffset;
+            const T::Off round_namesz = (T::Off(n_namesz) + AlignOffset) & AlignMask;
+            const T::Off round_descsz = (T::Off(n_descsz) + AlignOffset) & AlignMask;
+            if (qAddOverflow<T::Off>(next_offset, round_namesz, &next_offset))
                 break;
-            next_offset &= -NoteAlignment;
-
-            next_offset += NoteAlignment - 3;        // offset is aligned, this can't overflow
-            if (qAddOverflow<T::Off>(next_offset, n_descsz, &next_offset))
+            if (qAddOverflow<T::Off>(next_offset, round_descsz, &next_offset))
                 break;
-            next_offset &= -NoteAlignment;
             if (next_offset > end_offset)
                 break;
