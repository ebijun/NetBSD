$NetBSD$

Add constexpr keyword to the member function.

--- js/src/jit/arm64/vixl/Registers-vixl.h.orig	2025-11-19 07:12:36.568771038 +0000
+++ js/src/jit/arm64/vixl/Registers-vixl.h
@@ -188,13 +188,13 @@ class CPURegister {
   bool IsRegister() const { return GetType() == kRegister; }
   bool IsVRegister() const { return GetType() == kVRegister; }
   bool IsZRegister() const { return GetType() == kZRegister; }
-  bool IsPRegister() const { return GetType() == kPRegister; }
+  constexpr bool IsPRegister() const { return GetType() == kPRegister; }
 
   bool IsNone() const { return GetType() == kNoRegister; }
 
   // `GetType() == kNoRegister` implies IsNone(), and vice-versa.
   // `GetType() == k<Foo>Register` implies Is<Foo>Register(), and vice-versa.
-  RegisterType GetType() const {
+  constexpr RegisterType GetType() const {
     switch (bank_) {
       case kNoRegisterBank:
         return kNoRegister;
