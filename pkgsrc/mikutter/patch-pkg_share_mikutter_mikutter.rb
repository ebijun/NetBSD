--- /usr/pkg/share/mikutter/mikutter.rb.org	2026-03-25 11:36:03.296084930 +0900
+++ /usr/pkg/share/mikutter/mikutter.rb	2026-03-25 11:37:41.774071940 +0900
@@ -59,7 +59,7 @@
 # _profile_ がtrueなら、プロファイリングした結果を一時ディレクトリに保存する
 def boot!(profile)
   begin
-    RubyVM::YJIT.enable if RUBY_VERSION.split('.') >= %w[3 3]
+    RubyVM::YJIT.enable if defined?(RubyVM::YJIT) && RUBY_VERSION.split('.') >= %w[3 3]
     if profile
       require 'ruby-prof'
       begin
