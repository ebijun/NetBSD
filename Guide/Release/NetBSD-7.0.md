Introduction {#announcing}
============

The NetBSD Project is pleased to announce NetBSD 7.0, the fifteenth
major release of the NetBSD operating system.

Some highlights of the NetBSD 7.0 release are:

-   DRM/KMS support brings accelerated graphics to x86 systems using
    Intel and Radeon devices

-   Multiprocessor ARM support

-   Support for many new ARM boards:

    -   Raspberry Pi 2

    -   ODROID-C1

    -   BeagleBoard, BeagleBone, BeagleBone Black

    -   MiraBox

    -   Allwinner A20, A31: Cubieboard2, Cubietruck, Banana Pi, etc.

    -   Freescale i.MX50, i.MX51: Kobo Touch, Netwalker

    -   Xilinx Zynq: Parallela, ZedBoard

-   Major NPF improvements: switched to BPF with just-in-time (JIT)
    compilation by default, support for dynamic rules, support for
    static (stateless) NAT, support for IPv6-to-IPv6 Network Prefix
    Translation (NPTv6) as per RFC 6296, support for CDB based tables
    (uses perfect hashing and guarantees lock-free O(1) lookups), syntax
    changes, many bug fixes and performance improvements.

-   Added multiprocessor support to the USB subsystem

-   Numerous improvements in the handling of disk wedges

-   GPT support in sysinst via the extended partitioning menu

-   Lua kernel scripting

-   Added a new port, epoc32, supporting Psion EPOC PDAs

-   GCC updated to 4.8

-   Optional fully BSD-licensed C/C++ runtime env: compiler\_rt, libc++,
    libcxxrt

[Please read below](#major-changes) for a full list of changes in NetBSD
7.0.

Complete source and binaries for NetBSD 7.0 are available for download
at many sites around the world. A list of download sites providing FTP,
AnonCVS, SUP, and other services may be found at
[](http://www.NetBSD.org/mirrors/). We encourage users who wish to
install via ISO or USB disk images to download via BitTorrent by using
the [torrent files](../../mirrors/torrents/) supplied in the images
area. A list of hashes for the NetBSD 7.0 distribution has been signed
with the well-connected PGP key for the NetBSD Security Officer:
[](http://ftp.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-7.0_hashes.asc)

NetBSD is free. All of the code is under non-restrictive licenses, and
may be used without paying royalties to anyone. Free support services
are available via our mailing lists and website. Commercial support is
available from a variety of sources. More extensive information on
NetBSD is available from our website:

> <http://www.NetBSD.org/>

NetBSD mirror sites {#mirrors}
===================

Please use a mirror site close to you.

-   FTP
-   ISO images
-   Anonymous CVS
-   BitTorrent
-   SUP
-   CVSup
-   rsync
-   AFS

System families supported by NetBSD 7.0 {#system-families}
=======================================

The NetBSD 7.0 release provides supported binary distributions for the
following systems:

  ------------------------------------------------ -----------------------------------------------------------------------------------
  [NetBSD/acorn26](../../ports/acorn26/)           Acorn Archimedes, A-series and R-series systems
  [NetBSD/acorn32](../../ports/acorn32/)           Acorn RiscPC/A7000, VLSI RC7500
  [NetBSD/algor](../../ports/algor/)               Algorithmics, Ltd. MIPS evaluation boards
  [NetBSD/alpha](../../ports/alpha/)               Digital/Compaq Alpha (64-bit)
  [NetBSD/amd64](../../ports/amd64/)               AMD family processors like Opteron, Athlon64, and Intel CPUs with EM64T extension
  [NetBSD/amiga](../../ports/amiga/)               Commodore Amiga and MacroSystem DraCo
  [NetBSD/amigappc](../../ports/amigappc/)         PowerPC-based Amiga boards.
  [NetBSD/arc](../../ports/arc/)                   MIPS-based machines following the Advanced RISC Computing spec
  [NetBSD/atari](../../ports/atari/)               Atari TT030, Falcon, Hades
  [NetBSD/bebox](../../ports/bebox/)               Be Inc's BeBox
  [NetBSD/cats](../../ports/cats/)                 Chalice Technology's CATS and Intel's EBSA-285 evaluation boards
  [NetBSD/cesfic](../../ports/cesfic/)             CES FIC8234 VME processor board
  [NetBSD/cobalt](../../ports/cobalt/)             Cobalt Networks' MIPS-based Microservers
  [NetBSD/dreamcast](../../ports/dreamcast/)       Sega Dreamcast game console
  [NetBSD/emips](../../ports/emips/)               The Extensible MIPS architecture from Microsoft Research
  [NetBSD/epoc32](../../ports/epoc32/)             Psion EPOC PDAs
  [NetBSD/evbarm](../../ports/evbarm/)             Various ARM-based evaluation boards and appliances
  [NetBSD/evbmips](../../ports/evbmips/)           Various MIPS-based evaluation boards and appliances
  [NetBSD/evbppc](../../ports/evbppc/)             Various PowerPC-based evaluation boards and appliances
  [NetBSD/evbsh3](../../ports/evbsh3/)             Various Hitachi Super-H SH3 and SH4-based evaluation boards and appliances
  [NetBSD/ews4800mips](../../ports/ews4800mips/)   NEC's MIPS-based EWS4800 workstation
  [NetBSD/hp300](../../ports/hp300/)               Hewlett-Packard 9000/300 and 400 series
  [NetBSD/hp700](../../ports/hp700/)               Hewlett-Packard 9000 Series 700 workstations
  [NetBSD/hpcarm](../../ports/hpcarm/)             StrongARM based Windows CE PDA machines
  [NetBSD/hpcmips](../../ports/hpcmips/)           MIPS-based Windows CE PDA machines
  [NetBSD/hpcsh](../../ports/hpcsh/)               Hitachi Super-H based Windows CE PDA machines
  [NetBSD/i386](../../ports/i386/)                 IBM PCs and PC clones with i486-family processors and up
  [NetBSD/ibmnws](../../ports/ibmnws/)             IBM Network Station 1000
  [NetBSD/iyonix](../../ports/iyonix/)             Castle Technology's Iyonix ARM based PCs
  [NetBSD/landisk](../../ports/landisk/)           SH4 processor based NAS appliances
  [NetBSD/luna68k](../../ports/luna68k/)           OMRON Tateisi Electric's LUNA series
  [NetBSD/mac68k](../../ports/mac68k/)             Apple Macintosh with Motorola 68k CPU
  [NetBSD/macppc](../../ports/macppc/)             Apple PowerPC-based Macintosh and clones
  [NetBSD/mipsco](../../ports/mipsco/)             MIPS Computer Systems Inc. family of workstations and servers
  [NetBSD/mmeye](../../ports/mmeye/)               Brains mmEye multimedia server
  [NetBSD/mvme68k](../../ports/mvme68k/)           Motorola MVME 68k Single Board Computers
  [NetBSD/mvmeppc](../../ports/mvmeppc/)           Motorola PowerPC VME Single Board Computers
  [NetBSD/netwinder](../../ports/netwinder/)       StrongARM based NetWinder machines
  [NetBSD/news68k](../../ports/news68k/)           Sony's 68k-based “NET WORK STATION” series
  [NetBSD/newsmips](../../ports/newsmips/)         Sony's MIPS-based “NET WORK STATION” series
  [NetBSD/next68k](../../ports/next68k/)           NeXT 68k “black” hardware
  [NetBSD/ofppc](../../ports/ofppc/)               OpenFirmware PowerPC machines
  [NetBSD/pmax](../../ports/pmax/)                 Digital MIPS-based DECstations and DECsystems
  [NetBSD/prep](../../ports/prep/)                 PReP (PowerPC Reference Platform) and CHRP machines
  [NetBSD/rs6000](../../ports/rs6000/)             IBM RS/6000 MCA-based PowerPC machines.
  [NetBSD/sandpoint](../../ports/sandpoint/)       Motorola Sandpoint reference platform, including many PPC-based NAS boxes
  [NetBSD/sbmips](../../ports/sbmips/)             Broadcom SiByte evaluation boards
  [NetBSD/sgimips](../../ports/sgimips/)           Silicon Graphics' MIPS-based workstations
  [NetBSD/shark](../../ports/shark/)               Digital DNARD (“shark”)
  [NetBSD/sparc](../../ports/sparc/)               Sun SPARC (32-bit) and UltraSPARC (in 32-bit mode)
  [NetBSD/sparc64](../../ports/sparc64/)           Sun UltraSPARC (in native 64-bit mode)
  [NetBSD/sun2](../../ports/sun2/)                 Sun Microsystems Sun 2 machines with Motorola 68010 CPU
  [NetBSD/sun3](../../ports/sun3/)                 Motorola 68020 and 030 based Sun 3 and 3x machines
  [NetBSD/vax](../../ports/vax/)                   Digital VAX
  [NetBSD/x68k](../../ports/x68k/)                 Sharp X680x0 series
  [NetBSD/xen](../../ports/xen/)                   The Xen virtual machine monitor
  [NetBSD/zaurus](../../ports/zaurus/)             Sharp ARM PDAs
  ------------------------------------------------ -----------------------------------------------------------------------------------

Ports available in source form only for this release include the
following:

  ---------------------------------- ------------------------------
  [NetBSD/ia64](../../ports/ia64/)   Itanium family of processors
  ---------------------------------- ------------------------------

Acknowledgments {#acknowledgements}
===============

The NetBSD Foundation would like to thank all those who have contributed
code, hardware, documentation, funds, colocation for our servers, web
pages and other documentation, release engineering, and other resources
over the years. More information on the people who make NetBSD happen is
available at:

> [http://www.NetBSD.org/people/](../../people/)

We would like to especially thank the University of California at
Berkeley and the GNU Project for particularly large subsets of code that
we use. We would also like to thank the Internet Systems Consortium Inc.
and the Network Security Lab at Columbia University's Computer Science
Department for current colocation services.

About NetBSD
============

NetBSD is a free, fast, secure, and highly portable Unix-like Open
Source operating system. It is available for a wide range of platforms,
from large-scale servers and powerful desktop systems to handheld and
embedded devices. Its clean design and advanced features make it
excellent for use in both production and research environments, and the
source code is freely available under a business-friendly license.
NetBSD is developed and supported by a large and vibrant international
community. Many applications are readily available through [pkgsrc, the
NetBSD Packages Collection.](http://pkgsrc.org)

About the NetBSD Foundation {#about-foundation}
===========================

The [NetBSD Foundation](../../foundation/) was chartered in 1995, with
the task of overseeing core NetBSD project services, promoting the
project within industry and the open source community, and holding
intellectual property rights on much of the NetBSD code base. Day-to-day
operations of the project are handled by volunteers.

As a non-profit organization with no commercial backing, the NetBSD
Foundation depends on donations from its users, and we would like to ask
you to consider [making a donation](../../donations/) to the NetBSD
Foundation in support of continuing production of our fine operating
system. Your generous donation would be particularly welcome to help
with ongoing upgrades and maintenance, as well as with operating
expenses for the NetBSD Foundation.

Donations can be done via PayPal to <paypal@NetBSD.org>, or via Google
Checkout and are fully tax-deductible in the US. See
[http://www.NetBSD.org/donations/](http://www.NetBSD.org/donations/#how-to-donate)
for more information, or contact <finance-exec@NetBSD.org> directly.
