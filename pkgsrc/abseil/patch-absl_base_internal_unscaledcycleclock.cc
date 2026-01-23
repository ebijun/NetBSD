$NetBSD$

To retrieve the CPU frequency on NetBSD by making a system call (sysctlbyname)
 to access kernel information (hw.cpufrequency). 
It returns the actual frequency if successful, 
 or 0.0 as a default fallback if the operation fails.

--- absl/base/internal/unscaledcycleclock.cc.org	2026-01-23 10:40:01.204136664 +0000
+++ absl/base/internal/unscaledcycleclock.cc
@@ -14,6 +14,12 @@
 
 #include "absl/base/internal/unscaledcycleclock.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#endif
+
 #if ABSL_USE_UNSCALED_CYCLECLOCK
 
 #if defined(_WIN32)
@@ -102,6 +108,13 @@ double UnscaledCycleClock::Frequency() {
                  &length, nullptr, 0);
   });
   return timebase_frequency;
+#elif defined(__NetBSD__)
+  long long freq = 0;
+  size_t len = sizeof(freq);
+  if (sysctlbyname("hw.cpufrequency", &freq, &len, NULL, 0) == 0) {
+    return static_cast<double>(freq);
+  }
+  return 0.0;
 #else
 #error Must implement UnscaledCycleClock::Frequency()
 #endif
