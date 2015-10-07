<div class="webpage">

<div id="top">

[Skip to main content.](#mainContent)

</div>

<div id="centralHeader">

<div id="logo">

[![\[NetBSD Logo\]](../../images/NetBSD-smaller.png)](../../)
<div id="name">

[The NetBSD Project](../../)

</div>

<div id="slogan">

[“Of course it runs NetBSD”](../../)

</div>

</div>

<div id="headerTools">

<div id="header-cse-search-form">

Google custom search

</div>

</div>

</div>

<div id="navBar" role="navigation">

<span class="doNotDisplay"> Navigation: </span>
-   [Home](../../)
-   [News & Media](../../)
    -   [Recent changes](../../changes/)
    -   [NetBSD blog](http://blog.NetBSD.org/)
    -   [Events](../../gallery/events.html)
    -   [Feeds](../../changes/rss.html)
-   [About](../../about/)
    -   [NetBSD](../../about/)
    -   [The NetBSD Foundation](../../foundation/)
    -   [Advocacy](../../gallery/)
-   [Documentation](../../docs/)
    -   [FAQ & HOWTOs](../../docs/misc/index.html)
    -   [The Guide](../../docs/guide/en/)
    -   [Manual pages](http://man.NetBSD.org/)
    -   [Wiki](http://wiki.NetBSD.org/)
-   [Support](../../support/)
    -   [Problem report guide](../../support/send-pr.html)
    -   [Report a bug](../../cgi-bin/sendpr.cgi?gndb=netbsd)
    -   [Query bug database](../../support/query-pr.html)
    -   [Security](../../support/security/)
-   [Community](../../community/)
    -   [Blogs](http://netbsd.fi/)
    -   [Mailing lists](../../mailinglists/)
    -   [List archives](http://mail-index.NetBSD.org/)
-   [Developers](../../developers/)
    -   [Browse source](http://cvsweb.NetBSD.org/)
    -   [Cross-reference](http://nxr.NetBSD.org/)
    -   [Release engineering](http://releng.NetBSD.org/)
    -   [Projects list](http://wiki.NetBSD.org/projects/)
-   [Ports](../../ports/)
    -   [History](../../ports/history.html)
    -   [Emulators](../../ports/emulators.html)
-   [Packages](http://www.pkgsrc.org/)
    -   [Browse packages](http://www.pkgsrc.se/)
    -   [Release
        engineering](http://releng.NetBSD.org/index-pkgsrc.html)

</div>

<div id="content">

<div class="fullWidth">

<div class="rowOfBoxes">

Announcing NetBSD 7.0
=====================

<div class="sect1">

<div class="titlepage">

<div>

<div>

Introduction {.title style="clear: both"}
------------

</div>

</div>

</div>

The NetBSD Project is pleased to announce NetBSD 7.0, the fifteenth
major release of the NetBSD operating system.

Some highlights of the NetBSD 7.0 release are:

<div class="itemizedlist">

-   DRM/KMS support brings accelerated graphics to x86 systems using
    Intel and Radeon devices
-   Multiprocessor ARM support
-   Support for many new ARM boards:
    <div class="itemizedlist">

    -   Raspberry Pi 2
    -   ODROID-C1
    -   BeagleBoard, BeagleBone, BeagleBone Black
    -   MiraBox
    -   Allwinner A20, A31: Cubieboard2, Cubietruck, Banana Pi, etc.
    -   Freescale i.MX50, i.MX51: Kobo Touch, Netwalker
    -   Xilinx Zynq: Parallela, ZedBoard

    </div>

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

</div>

[Please read below](#major-changes) for a full list of changes in NetBSD
7.0.

Complete source and binaries for NetBSD 7.0 are available for download
at many sites around the world. A list of download sites providing FTP,
AnonCVS, SUP, and other services may be found at
<http://www.NetBSD.org/mirrors/>. We encourage users who wish to install
via ISO or USB disk images to download via BitTorrent by using the
[torrent files](../../mirrors/torrents/) supplied in the images area. A
list of hashes for the NetBSD 7.0 distribution has been signed with the
well-connected PGP key for the NetBSD Security Officer:
<http://ftp.NetBSD.org/pub/NetBSD/security/hashes/NetBSD-7.0_hashes.asc>

NetBSD is free. All of the code is under non-restrictive licenses, and
may be used without paying royalties to anyone. Free support services
are available via our mailing lists and website. Commercial support is
available from a variety of sources. More extensive information on
NetBSD is available from our website:

<div class="blockquote">

> <http://www.NetBSD.org/>

</div>

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

Major Changes Between 6.0 and 7.0 {.title style="clear: both"}
---------------------------------

</div>

</div>

</div>

The complete list of changes can be found in the
[CHANGES](http://ftp.NetBSD.org/pub/NetBSD/NetBSD-7.0/CHANGES) and
[CHANGES-7.0](http://ftp.NetBSD.org/pub/NetBSD/NetBSD-7.0/CHANGES-7.0)
files in the top level directory of the NetBSD 7.0 release tree. An
abbreviated version is below:

<div class="sect2">

<div class="titlepage">

<div>

<div>

### General kernel {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   Add sendmmsg and recvmmsg support.
-   Import sljit and add BPF JIT compiler.
-   Add BPF coprocessor support (BPF\_COP/BPF\_COPX instructions).
-   Add fdiscard and posix\_fallocate system calls.
-   Add
    [clock\_nanosleep(2)](http://netbsd.gw.com/cgi-bin/man-cgi?clock_nanosleep+2+NetBSD-6.0+i386).
-   Add a new RLIMIT\_NTHR limit to limit the number of processes per
    user and the corresponding kern.maxlwp sysctl.
-   Expose kern.uidinfo.\* via sysctl.
-   Create an "options MODULAR\_DEFAULT\_AUTOLOAD" config option and add
    it to all kernel configs that contain "options MODULAR". This option
    turns on module autoloading by default (which is the
    current default). This allows people who don't want module
    autoloading on by default to disable it by simply
    removing/commentting this line.
-   kqueue: on NOTE\_EXIT, put the exit code of the process in data.
-   [sysmon\_pswitch(9)](http://netbsd.gw.com/cgi-bin/man-cgi?sysmon_pswitch+9+NetBSD-6.0+i386):
    Introduce a new switch type, PSWITCH\_TYPE\_RADIO, to be used to
    report to userland hardware radio switch changes.
    [powerd(8)](http://netbsd.gw.com/cgi-bin/man-cgi?powerd+8+NetBSD-6.0+i386)
    will call a "radio\_button" script to handle the event.
-   [envsys(4)](http://netbsd.gw.com/cgi-bin/man-cgi?envsys+4+NetBSD-6.0+i386):
    Add %rH (relative Humidity) to sensor framework.

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Networking {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   Add sysctls to avoid IPv6 DoS attacks (from OpenBSD):
    <div class="itemizedlist">

    -   net.inet6.ip6.neighborgcthresh = 2048
    -   net.inet6.ip6.maxifprefixes = 16
    -   net.inet6.ip6.maxifdefrouters = 16
    -   net.inet6.ip6.maxdynroutes = 4096

    </div>

-   Make
    [shmif(4)](http://netbsd.gw.com/cgi-bin/man-cgi?shmif+4+NetBSD-6.0+i386)
    work with bridges.
-   Add net.inet6.ip6.prefer\_tempaddr sysctl knob to prefer IPv6
    temporary addresses as the source address.
-   Add support for the TCP\_INFO socket option, which permits the
    caller to query certain information about a TCP connection.

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### File systems {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   ptyfs: Allow multiple mounts and support proper device visibility
    in chroots.
-   Enable support for UFS1 extended attributes in GENERIC and
    GENERIC-like kernels.
-   FFS: Don't fail mounting root if the WAPBL log is corrupt.
-   Add experimental support for the (mostly SSD specific) "discard", or
    ATA "TRIM" command to
    [wd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?wd+4+NetBSD-6.0+i386)
    and FFS.

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Security {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   [rnd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?rnd+4+NetBSD-6.0+i386):
    <div class="itemizedlist">

    -   Sensors can now be a source of entropy.
    -   Suck in much more entropy early in boot and thereafter: autoconf
        timings, all sysctl settings (including hostname), contents of
        early network packets, environmental sensor values generically
        rather than as per-driver special cases.

    </div>

-   [rnd(9)](http://netbsd.gw.com/cgi-bin/man-cgi?rnd+9+NetBSD-6.0+i386):
    <div class="itemizedlist">

    -   Add explicit enable/disable hooks for callout-driven sources (be
        more power friendly).
    -   Make "skew" source polled so it runs only when there is
        entropy demand.
    -   Adjust entropy collection from polled sources so it's
        processed sooner.

    </div>

-   viornd(4): Add driver for the VirtIO entropy source available on
    QEMU, KVM, and Google Compute Engine.
-   [cprng\_fast(9)](http://netbsd.gw.com/cgi-bin/man-cgi?cprng_fast+9+NetBSD-6.0+i386):
    Replace slow/broken mutex-protected kernel \_arc4random() with new
    cprng\_fast implemenation using per-cpu instances of chacha8.

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Drivers {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   Audio:
    <div class="itemizedlist">

    -   [ess(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ess+4+NetBSD-6.0+i386):
        Add support for Spatializer, 3D audio effects embedded in ES1869
        and ES1879.

    </div>

-   Graphics and Video:
    <div class="itemizedlist">

    -   Add accelerated support for Intel and Radeon devices on x86
        through a port of the Linux 3.15 DRM/KMS code.
    -   [genfb(4)](http://netbsd.gw.com/cgi-bin/man-cgi?genfb+4+NetBSD-6.0+i386):
        Add support for 32bit framebuffers.
    -   Add
        [gffb(4)](http://netbsd.gw.com/cgi-bin/man-cgi?gffb+4+NetBSD-6.0+i386),
        a driver for NVIDIA GeForce2 MX graphics controllers.
    -   Add
        [gmafb(4)](http://netbsd.gw.com/cgi-bin/man-cgi?gmafb+4+NetBSD-6.0+i386),
        a framebuffer driver for Intel Graphics
    -   Add
        [tifb(4)](http://netbsd.gw.com/cgi-bin/man-cgi?tifb+4+NetBSD-6.0+i386),
        an experimental driver for the Texas Instruments AM335x SoC's
        graphic controller.
    -   Add tdvfb, a 3Dfx Voodoo1 and Voodoo2 driver.
    -   udl(4): Add support for the BUFFALO GX-DVI/U2B DisplayLink
        USB-DVI box.

    </div>

-   Storage:
    <div class="itemizedlist">

    -   Recognize the Apple disk partitioning scheme, and
        auto-discover wedges. Fix iPod disk mounting.
    -   Add
        [mpii(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mpii+4+NetBSD-6.0+i386),
        a driver for LSI Logic Fusion-MPT Message Passing Interface II
        SAS controllers.
    -   [ata(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ata+4+NetBSD-6.0+i386):
        Add support for SATA Port MultiPliers (PMP).
    -   [mfi(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mfi+4+NetBSD-6.0+i386):
        <div class="itemizedlist">

        -   Add tagged queuing support.
        -   Add support for LSI SAS2208-based controllers.
        -   Make it possible to use the LSI MegaCLI Linux binary
            on NetBSD.

        </div>

    -   Add support for the
        [bio(4)](http://netbsd.gw.com/cgi-bin/man-cgi?bio+4+NetBSD-6.0+i386)
        API to the
        [mpt(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mpt+4+NetBSD-6.0+i386) driver.
    -   Make
        [ccd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ccd+4+NetBSD-6.0+i386)
        work with component and total sizes greater than 2TB.

    </div>

-   Networking:
    <div class="itemizedlist">

    -   Add
        [axen(4)](http://netbsd.gw.com/cgi-bin/man-cgi?axen+4+NetBSD-6.0+i386),
        a driver for ASIX AX88178a and AX88179 Ethernet devices. Ported
        from OpenBSD.
    -   Add
        [malo(4)](http://netbsd.gw.com/cgi-bin/man-cgi?malo+4+NetBSD-6.0+i386),
        a driver for Marvell Libertas IEEE 802.11b/g wireless
        network devices. Ported from OpenBSD.
    -   Add
        [run(4)](http://netbsd.gw.com/cgi-bin/man-cgi?run+4+NetBSD-6.0+i386),
        a driver for Ralink Technology RT2700U/RT2800U/RT3000U USB IEEE
        802.11a/b/g/n wireless network devices. Ported from OpenBSD.
    -   Add
        [usmsc(4)](http://netbsd.gw.com/cgi-bin/man-cgi?usmsc+4+NetBSD-6.0+i386),
        a driver for SMSC LAN95xx USB LAN devices. From FreeBSD/OpenBSD.
    -   Add
        [vmx(4)](http://netbsd.gw.com/cgi-bin/man-cgi?vmx+4+NetBSD-6.0+i386),
        a VMware VMXNET3 driver. Ported from OpenBSD.
    -   [alc(4)](http://netbsd.gw.com/cgi-bin/man-cgi?alc+4+NetBSD-6.0+i386):
        Add support for AR816x/AR817x chipsets.
    -   [bge(4)](http://netbsd.gw.com/cgi-bin/man-cgi?bge+4+NetBSD-6.0+i386):
        Add support for Altima AC1003, Apple BCM5701, Broadcom BCM5787F,
        BCM5787G, BCM5787F, BCM5719, BCM5720, BCM57762 (Apple
        Thunderbolt Gigabit Ethernet Adapter), BCM57766, BCM57782
        and BCM57786.
    -   [brgphy(4)](http://netbsd.gw.com/cgi-bin/man-cgi?brgphy+4+NetBSD-6.0+i386):
        Add support for BCM5756, BCM5717C, BCM5719C, BCM5720C
        and BCM57780.
    -   [iwn(4)](http://netbsd.gw.com/cgi-bin/man-cgi?iwn+4+NetBSD-6.0+i386):
        Add support for Centrino Wireless-N
        100/105/130/135/1030/2200/2230 and Centrino Advanced-N 6230.
    -   [ixg(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ixg+4+NetBSD-6.0+i386):
        <div class="itemizedlist">

        -   Add X540 support.
        -   Add TSO6 support.
        -   Add 100BaseTX support.

        </div>

    -   [micphy(4)](http://netbsd.gw.com/cgi-bin/man-cgi?micphy+4+NetBSD-6.0+i386):
        Add Micrel PHY (KSZ9021RN) support.
    -   [rgephy(4)](http://netbsd.gw.com/cgi-bin/man-cgi?rgephy+4+NetBSD-6.0+i386):
        Add support for RTL8211F and RTL8251.
    -   [u3g(4)](http://netbsd.gw.com/cgi-bin/man-cgi?u3g+4+NetBSD-6.0+i386):
        Add Huawei E353 support.
    -   [urtwn(4)](http://netbsd.gw.com/cgi-bin/man-cgi?urtwn+4+NetBSD-6.0+i386):
        Add support for Realtek RTL8188EUS and RTL8188ETV chipsets.
    -   [wm(4)](http://netbsd.gw.com/cgi-bin/man-cgi?wm+4+NetBSD-6.0+i386):
        Add support for I210, I211, I217, I218, and I354.

    </div>

-   USB:
    <div class="itemizedlist">

    -   Add support for SMP to the USB subsytem.
    -   Add dotg(4), a driver for Synopsys DesignWare USB OTG.
    -   Add
        [uatp(4)](http://netbsd.gw.com/cgi-bin/man-cgi?uatp+4+NetBSD-6.0+i386),
        a driver for USB Apple trackpads.
    -   [uftdi(4)](http://netbsd.gw.com/cgi-bin/man-cgi?uftdi+4+NetBSD-6.0+i386):
        Add BUFFALO PC-OP-RS1 support.
    -   [uhidev(4)](http://netbsd.gw.com/cgi-bin/man-cgi?uhidev+4+NetBSD-6.0+i386):
        Add support for Xbox One controllers.
    -   [umcs(4)](http://netbsd.gw.com/cgi-bin/man-cgi?umcs+4+NetBSD-6.0+i386)
        Fix support for two-port variants.

    </div>

-   Miscellaneous:
    <div class="itemizedlist">

    -   Add
        [hythygtemp(4)](http://netbsd.gw.com/cgi-bin/man-cgi?hythygtemp+4+NetBSD-6.0+i386),
        a driver for HYT-221/271/939 humidity and temperature
        I2C sensors.
    -   Add
        [ibmcd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ibmcd+4+NetBSD-6.0+i386),
        a driver for the IBM 4810 BSP cash drawer port.
    -   Add
        [mcp23s17gpio(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mcp23s17gpio+4+NetBSD-6.0+i386),
        a driver for Microchip MCP23S17 16-bit GPIO chips.
    -   Add
        [mcp980x(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mcp980x+4+NetBSD-6.0+i386),
        a driver for Microchip MCP9800/1/2/3 I2C temperature sensors.
    -   Add
        [mpl115a(4)](http://netbsd.gw.com/cgi-bin/man-cgi?mpl115a+4+NetBSD-6.0+i386),
        a driver for Freescale MPL115A2 I2C absolute pressure sensors.
    -   Add
        [msm6242b(4)](http://netbsd.gw.com/cgi-bin/man-cgi?msm6242b+4+NetBSD-6.0+i386),
        a driver for MI OKI MSM6242B time-of-day clocks.
    -   Add mcp48x1dac, a driver with preliminary support for the
        Microchip MCP48x1 family of Digital-to-Analog converters.
    -   Add
        [ptcd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ptcd+4+NetBSD-6.0+i386),
        a driver for the Protech PS3100 cash drawer port.
    -   Add
        [rtsx(4)](http://netbsd.gw.com/cgi-bin/man-cgi?rtsx+4+NetBSD-6.0+i386),
        a driver for Realtek
        RTL8402/RTL8411/RTL8411B/RTS5209/RTS5227/RTS5229 card readers.
    -   [ubsec(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ubsec+4+NetBSD-6.0+i386):
        Add support for AES-CBC modes and BCM586x chips.
    -   [vmt(4)](http://netbsd.gw.com/cgi-bin/man-cgi?vmt+4+NetBSD-6.0+i386):
        Synchronize the clock periodically to ensure it remains
        up-to-date even when the host is suspended.
    -   [wskbd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?wskbd+4+NetBSD-6.0+i386):
        Add belgian keyboard layouts (KB\_BE) to
        [pckbd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?pckbd+4+NetBSD-6.0+i386)
        and
        [ukbd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ukbd+4+NetBSD-6.0+i386).

    </div>

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Platforms {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   [alpha](../../ports/alpha/):
    <div class="itemizedlist">

    -   Add support for AlphaStation DS15.

    </div>

-   [amd64](../../ports/amd64/):
    <div class="itemizedlist">

    -   Add support for up to 256 CPUs.
    -   Add drivers for the Apple System Management Controller.

    </div>

-   [amiga](../../ports/amiga/):
    <div class="itemizedlist">

    -   Add clockport(4) layer and a driver for A1200 on-board
        clockport a1k2cp(4).
    -   Rework X-Surf driver as xsurf(4). Add support for clockport(4)
        on top of xsurf(4).
    -   A2000-style RTCs are now driven by the msm6242b(4) driver.
    -   Support software power-off with empm(4).
    -   Add initial support for Thylacine USB cards using slhci(4).
    -   gayle(4): Add support for newer 1200 models.
    -   Add
        [xsh(4)](http://netbsd.gw.com/cgi-bin/man-cgi?xsh+4+NetBSD-6.0+i386),
        a driver for the Individual Computers X-Surf 100 network
        interface card.
    -   Add
        [empm(4)](http://netbsd.gw.com/cgi-bin/man-cgi?empm+4+NetBSD-6.0+i386),
        a driver for the power manager present on Mediator 1200 TX and
        SX bridges.
    -   Add
        [empb(4)](http://netbsd.gw.com/cgi-bin/man-cgi?empb+4+NetBSD-6.0+i386),
        an ELBOX Mediator PCI 1200 driver.
    -   Add
        [z3rambd(4)](http://netbsd.gw.com/cgi-bin/man-cgi?z3rambd+4+NetBSD-6.0+i386),
        a Zorro III RAM board driver.
    -   Add
        [em4kv(4)](http://netbsd.gw.com/cgi-bin/man-cgi?em4kv+4+NetBSD-6.0+i386),
        a Mediator 4000 PCI bridge driver.
    -   Add
        [acafh(4)](http://netbsd.gw.com/cgi-bin/man-cgi?acafh+4+NetBSD-6.0+i386),
        an Individual Computers ACA500 driver.

    </div>

-   ARM:
    <div class="itemizedlist">

    -   Add support for SMP.
    -   Add Cortex-A9 support.
    -   ARMFPE support has been removed.
    -   Add NEON userland support.
    -   Userland FPA support replaced with VFP.
    -   All arm ports with a common MACHINE\_ARCH now generate the
        same userspace. All sets are the same except for etc.tgz.
    -   Switched to EABI.

    </div>

-   [epoc32](../../ports/epoc32/):
    <div class="itemizedlist">

    -   Add a new port, epoc32, supporting 32bit Psion EPOC PDAs,
        primarily the Series 5 (CL PS-711x), Series 5mx (Windermere) and
        Series 7 (StrongARM) models.

    </div>

-   [evbarm](../../ports/evbarm/):
    <div class="itemizedlist">

    -   Add support for the Raspberry Pi 2.
    -   Add support for the ODROID-C1
    -   Add support for the BeagleBone (TI AM335x-based board).
    -   Add support for the BeagleBoard-xM (TI DM37XX) board.
    -   Add support for the Kobo Touch (Freescale i.MX50).
    -   Add support for the BCM5301X SoC.
    -   Add support for OMAP4430.
    -   Add support for Freescale i.MX6.
    -   Add support for Marvell Armada XP SoCs.
    -   Full Raspberry Pi support.
    -   Add
        [tps65217pmic(4)](http://netbsd.gw.com/cgi-bin/man-cgi?tps65217pmic+4+NetBSD-6.0+i386),
        a driver with support for TPS65217 PMIC, as found on BeagleBone
        and other AM335x based boards.
    -   Add
        [tiotg(4)](http://netbsd.gw.com/cgi-bin/man-cgi?tiotg+4+NetBSD-6.0+i386),
        a driver for the Texas Instruments AM335x SoC's USB
        OTG controller.
    -   Add bcmgpio, a BCM2835 GPIO obio driver.
    -   Add trng, an AM335x TRNG driver.
    -   Add bcmdmac, a BCM2835 dma controller driver.
    -   Add edma, a driver for the Enhanced Direct Memory Access
        controller found in the AM335x SoC.
    -   Add Zynq (Xilinx) support.
    -   Raspberry Pi: Set CPU frequency to the value specified in
        firmware config (/boot/config.txt) at boot.

    </div>

-   [evbmips](../../ports/evbmips/):
    <div class="itemizedlist">

    -   Add support for Lemote Yeeloong Notebooks.

    </div>

-   [hppa](../../ports/hppa/):
    <div class="itemizedlist">

    -   Renamed the hp700 port to hppa.
    -   Add
        [ohci(4)](http://netbsd.gw.com/cgi-bin/man-cgi?ohci+4+NetBSD-6.0+i386)
        support for the National Semiconductor PC87560, as found in many
        hppa machines.
    -   Add
        [fenv(3)](http://netbsd.gw.com/cgi-bin/man-cgi?fenv+3+NetBSD-6.0+i386) support.

    </div>

-   [hp300](../../ports/hp300/):
    <div class="itemizedlist">

    -   Add arcofi(4), which supports the HP "Audio1" device found on
        HP9000/425e machines.
    -   Fixed broken apci console support in the bootloader.
    -   Add sti(4) at sgc screen console support to bootloader.
    -   Add HP9000/425e RTC support.
    -   Add proper consinit(9) support for sti(4) at sgc framebuffer
        on HP9000/425e.
    -   Add support for sti(4) framebuffer at sgc bus on some 425t.
    -   The Apollo Domain keyboard now works.

    </div>

-   [i386](../../ports/i386/):
    <div class="itemizedlist">

    -   Add a soekrisgpio driver for Soekris net6501 machines.
    -   Disable COMPAT\_FREEBSD by default.
    -   Remove vga@isa and pcdisplay@isa from GENERIC, and create a new
        LEGACY kernel config that includes them instead.

    </div>

-   [luna68k](../../ports/luna68k/):
    <div class="itemizedlist">

    -   Add preleminary support for 4bpp framebuffers.
    -   Add a native bootloader based on the 4.4BSD-Lite2/luna68k
        "Stinger" loader.
    -   Add netboot support.
    -   sysinst now creates a boot UFS partition and installs the native
        bootloader during installation.
    -   Add ANSI text color support for 8bpp color framebuffers.
    -   The wsfb Xserver now works as monochrome server even with
        4bpp/8bpp color framebuffers.
    -   The console ANSI color palette is now reset properly after
        returning to WSDISPLAYIO\_MODE\_EMUL (e.g., when exiting
        the Xserver).

    </div>

-   [macppc](../../ports/macppc/):
    <div class="itemizedlist">

    -   Add support for ppc601-based machines.

    </div>

-   m68k:
    <div class="itemizedlist">

    -   Add inverse trigonometric functions, hyperbolic arctangent,
        exponential and power functions to m68k FPE.

    </div>

-   [sparc](../../ports/sparc/):
    <div class="itemizedlist">

    -   Add hardware acceleration for cgfourteen(4) using SX.

    </div>

-   [sparc64](../../ports/sparc64/):
    <div class="itemizedlist">

    -   Switch to TOPDOWN\_VM.

    </div>

-   [x68k](../../ports/x68k/):
    <div class="itemizedlist">

    -   Add a network bootloader for Neptune-X and Nereid Ethernet.
    -   The bootloader now probes the actual memory size and warns if
        the memory size value stored in SRAM is different.
    -   Add a 'switch' command to the bootloader to display and modify
        SRAM parameters as NetBSD's memswitch(8) and Human68k's
        SWITCH.X commands.
    -   Switched to X.Org, including the X68k monolithic server.
    -   Add support for up to 1008 MB of extended memory on the
        XM6i emulator.
    -   Add support for formatting floppies.

    </div>

-   [xen](../../ports/xen/):
    <div class="itemizedlist">

    -   Add MODULAR infrastructure for Xen kernels.

    </div>

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Userland {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   Add
    [blacklistd(8)](http://netbsd.gw.com/cgi-bin/man-cgi?blacklistd+8+NetBSD-6.0+i386),
    a daemon that integrates with packet filters to dynamically protect
    other network daemons such as ssh, named, and ftpd from network
    break-in attempts.
-   Add
    [ekermit(1)](http://netbsd.gw.com/cgi-bin/man-cgi?ekermit+1+NetBSD-6.0+i386),
    which is BSD-licenced. Replaces gkermit.
-   Add
    [flock(1)](http://netbsd.gw.com/cgi-bin/man-cgi?flock+1+NetBSD-6.0+i386),
    a utility to provide locks to shell scripts similar to
    [shlock(1)](http://netbsd.gw.com/cgi-bin/man-cgi?shlock+1+NetBSD-6.0+i386).
-   Add
    [getaddrinfo(1)](http://netbsd.gw.com/cgi-bin/man-cgi?getaddrinfo+1+NetBSD-6.0+i386),
    a utility for querying the system's name resolver.
-   Add
    [midirecord(1)](http://netbsd.gw.com/cgi-bin/man-cgi?midirecord+1+NetBSD-6.0+i386),
    a program for recording MIDI files.
-   Add a service(8) command, based on the FreeBSD script.
-   Add
    [timeout(1)](http://netbsd.gw.com/cgi-bin/man-cgi?timeout+1+NetBSD-6.0+i386),
    a command to run a command with a time limit.
-   Add support for named wedges to the following commands:
    [ccdconfig(8)](http://netbsd.gw.com/cgi-bin/man-cgi?ccdconfig+8+NetBSD-6.0+i386),
    [installboot(8)](http://netbsd.gw.com/cgi-bin/man-cgi?installboot+8+NetBSD-6.0+i386),
    [fsck(8)](http://netbsd.gw.com/cgi-bin/man-cgi?fsck+8+NetBSD-6.0+i386),
    [newfs(8)](http://netbsd.gw.com/cgi-bin/man-cgi?newfs+8+NetBSD-6.0+i386).
-   [atactl(8)](http://netbsd.gw.com/cgi-bin/man-cgi?atactl+8+NetBSD-6.0+i386):
    Add support for ATA SECURITY commands including setting firmware
    passwords and erasing disks.
-   [cksum(1)](http://netbsd.gw.com/cgi-bin/man-cgi?cksum+1+NetBSD-6.0+i386):
    Add a -q option.
-   [dbsym(8)](http://netbsd.gw.com/cgi-bin/man-cgi?dbsym+8+NetBSD-6.0+i386):
    Add the -p option, to report the size of the kernel symbol table and
    the size of the db\_symtab space.
-   [dd(1)](http://netbsd.gw.com/cgi-bin/man-cgi?dd+1+NetBSD-6.0+i386):
    Add iflag and oflag operands.
-   [dkctl(8)](http://netbsd.gw.com/cgi-bin/man-cgi?dkctl+8+NetBSD-6.0+i386):
    Add makewedges option to autodiscover wedges from a changed label.
-   [etcupdate(8)](http://netbsd.gw.com/cgi-bin/man-cgi?etcupdate+8+NetBSD-6.0+i386):
    A colon-separated list of tgz files is no longer accepted; you must
    use multiple -s options instead.
-   [etcupdate(8)](http://netbsd.gw.com/cgi-bin/man-cgi?etcupdate+8+NetBSD-6.0+i386):
    Add destdir support.
-   [fstab(5)](http://netbsd.gw.com/cgi-bin/man-cgi?fstab+5+NetBSD-6.0+i386):
    Add NAME=wedgename for fs\_spec and routines to parse it. Now wedges
    can be used in /etc/fstab, even in dynamic environments where disks
    come and go and wedges get renumbered.
-   [gpt(8)](http://netbsd.gw.com/cgi-bin/man-cgi?gpt+8+NetBSD-6.0+i386):
    Complete overhaul, including adding follwing subcommands: type,
    resize, set, unset, backup, restore, and resizedisk.
-   [httpd(8)](http://netbsd.gw.com/cgi-bin/man-cgi?httpd+8+NetBSD-6.0+i386):
    Add Lua scripting for content creation.
-   [indent(1)](http://netbsd.gw.com/cgi-bin/man-cgi?indent+1+NetBSD-6.0+i386):
    Add -ut / -nut options, as in FreeBSD.
-   [makefs(8)](http://netbsd.gw.com/cgi-bin/man-cgi?makefs+8+NetBSD-6.0+i386):
    Add support for msdos and UDF, creating filesystems at an offset,
    and merging directories with common files.
-   [mkdep(1)](http://netbsd.gw.com/cgi-bin/man-cgi?mkdep+1+NetBSD-6.0+i386):
    Add the -P option to prepend the string given to every
    target filename.
-   [netstat(1)](http://netbsd.gw.com/cgi-bin/man-cgi?netstat+1+NetBSD-6.0+i386):
    Accept -faddress\_family\[,family ...\].
-   [patch(1)](http://netbsd.gw.com/cgi-bin/man-cgi?patch+1+NetBSD-6.0+i386):
    Drop SCCS support.
-   [pcictl(8)](http://netbsd.gw.com/cgi-bin/man-cgi?pcictl+8+NetBSD-6.0+i386):
    Add read and write subcommands.
-   [pr(1)](http://netbsd.gw.com/cgi-bin/man-cgi?pr+1+NetBSD-6.0+i386):
    Add support for POSIX -f and -p options.
-   [resize\_ffs(8)](http://netbsd.gw.com/cgi-bin/man-cgi?resize_ffs+8+NetBSD-6.0+i386):
    <div class="itemizedlist">

    -   Add -c to check to see if grow/shrink is required.
    -   Add a -p flag, which displays a progress bar.

    </div>

-   [systat(1)](http://netbsd.gw.com/cgi-bin/man-cgi?systat+1+NetBSD-6.0+i386):
    Accept shell patterns to select drives.
-   [tetris(6)](http://netbsd.gw.com/cgi-bin/man-cgi?tetris+6+NetBSD-6.0+i386):
    <div class="itemizedlist">

    -   Add a 'down' key, defaulting to 'n'. It moves the block down a
        line, if it fits.
    -   Add support for colors.

    </div>

-   [tset(1)](http://netbsd.gw.com/cgi-bin/man-cgi?tset+1+NetBSD-6.0+i386):
    Restore logic for setting the VERASE character. Use terminfo
    \_unless\_ the terminal does overstrike, and use terminfo data not
    only for an unset tty.
-   [units(1)](http://netbsd.gw.com/cgi-bin/man-cgi?units+1+NetBSD-6.0+i386):
    Add -l and -L options.
-   [vndcompress(1)](http://netbsd.gw.com/cgi-bin/man-cgi?vndcompress+1+NetBSD-6.0+i386)
    <div class="itemizedlist">

    -   Add support for restarting after interrupt.
    -   Add support for constant memory, so 32-bit systems should be
        able to compress or uncompress multi-terabyte disks.

    </div>

-   [zgrep(1)](http://netbsd.gw.com/cgi-bin/man-cgi?zgrep+1+NetBSD-6.0+i386):
    suppress the prefixing of filename on output when only one file is
    specified, to match grep(1)'s output.
-   Libraries:

    <div class="itemizedlist">

    -   libc:
        <div class="itemizedlist">

        -   Add a murmurhash2 function.
        -   Add
            [consttime\_memequal(3)](http://netbsd.gw.com/cgi-bin/man-cgi?consttime_memequal+3+NetBSD-6.0+i386)
            and
            [explicit\_memset(3)](http://netbsd.gw.com/cgi-bin/man-cgi?explicit_memset+3+NetBSD-6.0+i386)
            for crypto applications.
        -   Add
            [strtoi(3)](http://netbsd.gw.com/cgi-bin/man-cgi?strtoi+3+NetBSD-6.0+i386)
            and
            [strtou(3)](http://netbsd.gw.com/cgi-bin/man-cgi?strtou+3+NetBSD-6.0+i386).
        -   [arc4random(3)](http://netbsd.gw.com/cgi-bin/man-cgi?arc4random+3+NetBSD-6.0+i386):
            Use ChaCha20 instead of RC4.

        </div>

    -   libm: Add basic long double support for elementary functions.
        Most transcendent functions are stubbed out.
    -   librt: Add
        [shm\_open(3)](http://netbsd.gw.com/cgi-bin/man-cgi?shm_open+3+NetBSD-6.0+i386)
        and
        [shm\_unlink(3)](http://netbsd.gw.com/cgi-bin/man-cgi?shm_unlink+3+NetBSD-6.0+i386).
    -   [ossaudio(3)](http://netbsd.gw.com/cgi-bin/man-cgi?ossaudio+3+NetBSD-6.0+i386):
        Add initial OSSv4 support.
    -   Implement FUSE direct I/O.
    -   Add PUFFS support for fallocate and fdiscard operations, and add
        FUSE fallocate support.
    -   [puffs(3)](http://netbsd.gw.com/cgi-bin/man-cgi?puffs+3+NetBSD-6.0+i386):
        Add PUFFS\_KFLAG\_NOFLUSH\_META to prevent sending metadata
        flush to FUSE.

    </div>

-   3rd party software updates:

    <div class="itemizedlist">

    -   BIND 9.10.2-P4
    -   IPFilter 5.1.1
    -   LLVM 3.6.1
    -   OpenLDAP 2.4.39
    -   OpenSSH 6.8
    -   OpenSSL 1.0.1p
    -   SQLite 3.8.3.1
    -   [atf(7)](http://netbsd.gw.com/cgi-bin/man-cgi?atf+7+NetBSD-6.0+i386)
        0.20
    -   binutils 2.23.2
    -   byacc 20130304
    -   [bzip2(1)](http://netbsd.gw.com/cgi-bin/man-cgi?bzip2+1+NetBSD-6.0+i386)
        1.0.6
    -   dhcp 4.3.0
    -   [dhcpcd(8)](http://netbsd.gw.com/cgi-bin/man-cgi?dhcpcd+8+NetBSD-6.0+i386)
        6.7.1
    -   [file(1)](http://netbsd.gw.com/cgi-bin/man-cgi?file+1+NetBSD-6.0+i386)
        5.19
    -   flex 2.5.39
    -   [gcc(1)](http://netbsd.gw.com/cgi-bin/man-cgi?gcc+1+NetBSD-6.0+i386)
        4.8.4
    -   [gdb(1)](http://netbsd.gw.com/cgi-bin/man-cgi?gdb+1+NetBSD-6.0+i386)
        7.7.1
    -   [kerberos(8)](http://netbsd.gw.com/cgi-bin/man-cgi?kerberos+8+NetBSD-6.0+i386)
        Heimdal-1-5-branch
    -   [less(1)](http://netbsd.gw.com/cgi-bin/man-cgi?less+1+NetBSD-6.0+i386)
        458
    -   libevent 2.0.22-stable
    -   libpcap 1.5.2
    -   [lua(1)](http://netbsd.gw.com/cgi-bin/man-cgi?lua+1+NetBSD-6.0+i386)
        5.3.0
    -   mDNSResponder 258.14
    -   ntp 4.2.8p2
    -   [openpam(3)](http://netbsd.gw.com/cgi-bin/man-cgi?openpam+3+NetBSD-6.0+i386)
        20140912 (Ourouparia)
    -   openresolv 3.6.0
    -   pcc 1.1.0.DEVEL 20120325
    -   pppd 2.4.7
    -   [pigz(1)](http://netbsd.gw.com/cgi-bin/man-cgi?pigz+1+NetBSD-6.0+i386)
        2.3.1
    -   [postfix(1)](http://netbsd.gw.com/cgi-bin/man-cgi?postfix+1+NetBSD-6.0+i386)
        2.11.4
    -   [tcpdump(8)](http://netbsd.gw.com/cgi-bin/man-cgi?tcpdump+8+NetBSD-6.0+i386)
        4.5.1
    -   [tmux(1)](http://netbsd.gw.com/cgi-bin/man-cgi?tmux+1+NetBSD-6.0+i386)
        1.9a
    -   tzdata 2015f
    -   wpa\_supplicant/hostapd 2.4

    </div>

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Miscellaneous {.title}

</div>

</div>

</div>

<div class="itemizedlist">

-   /usr/share/doc: Install formatted docs instead of nroff sources,
    and reorganize.
-   New BUILDINFO variable may be passed to build.sh, and exposed in
    /etc/release, as well as in sysctl kern.buildinfo.
-   Process /etc/modules.conf (if present) at startup, before
    securelevel is raised, to allow module loading on ports without a
    module aware bootloader.
-   Add a resize\_root rc.d script. If resize\_root=YES in rc.conf (the
    default is NO) then the system attempts to resize the root file
    system to fill its partition prior to mounting read-write.

</div>

</div>

<div class="sect2">

<div class="titlepage">

<div>

<div>

### Components removed from NetBSD {.title}

</div>

</div>

</div>

In this release of NetBSD, the following software components have been
removed from the system. Some were not useful anymore, or their utility
did not justify the maintenance overhead. Others were not working
properly and there was a lack of interest in fixing them.

<div class="itemizedlist">

-   The window utility was removed in favor of tmux. window can be found
    in pkgsrc/misc/window.
-   OSI network stack support was removed.
-   FAST\_IPSEC is now named IPSEC. The old KAME IPSEC code is gone.

</div>

</div>

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

NetBSD mirror sites {.title style="clear: both"}
-------------------

</div>

</div>

</div>

Please use a mirror site close to you.

<div class="itemizedlist">

-   [FTP](../../mirrors/#ftp)
-   [ISO images](../../mirrors/#iso)
-   [Anonymous CVS](../../mirrors/#anoncvs)
-   [BitTorrent](../../mirrors/#bittorrent)
-   [SUP](../../mirrors/#sup)
-   [CVSup](../../mirrors/#cvsup)
-   [rsync](../../mirrors/#rsync)
-   [AFS](../../mirrors/#afs)

</div>

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

System families supported by NetBSD 7.0 {.title style="clear: both"}
---------------------------------------

</div>

</div>

</div>

The NetBSD 7.0 release provides supported binary distributions for the
following systems:

<div class="table">

  ------------------------------------------------ ---------------------------------------------------------------------------------------------------
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
  [NetBSD/news68k](../../ports/news68k/)           Sony's 68k-based <span class="quote">“<span class="quote">NET WORK STATION</span>”</span> series
  [NetBSD/newsmips](../../ports/newsmips/)         Sony's MIPS-based <span class="quote">“<span class="quote">NET WORK STATION</span>”</span> series
  [NetBSD/next68k](../../ports/next68k/)           NeXT 68k <span class="quote">“<span class="quote">black</span>”</span> hardware
  [NetBSD/ofppc](../../ports/ofppc/)               OpenFirmware PowerPC machines
  [NetBSD/pmax](../../ports/pmax/)                 Digital MIPS-based DECstations and DECsystems
  [NetBSD/prep](../../ports/prep/)                 PReP (PowerPC Reference Platform) and CHRP machines
  [NetBSD/rs6000](../../ports/rs6000/)             IBM RS/6000 MCA-based PowerPC machines.
  [NetBSD/sandpoint](../../ports/sandpoint/)       Motorola Sandpoint reference platform, including many PPC-based NAS boxes
  [NetBSD/sbmips](../../ports/sbmips/)             Broadcom SiByte evaluation boards
  [NetBSD/sgimips](../../ports/sgimips/)           Silicon Graphics' MIPS-based workstations
  [NetBSD/shark](../../ports/shark/)               Digital DNARD (<span class="quote">“<span class="quote">shark</span>”</span>)
  [NetBSD/sparc](../../ports/sparc/)               Sun SPARC (32-bit) and UltraSPARC (in 32-bit mode)
  [NetBSD/sparc64](../../ports/sparc64/)           Sun UltraSPARC (in native 64-bit mode)
  [NetBSD/sun2](../../ports/sun2/)                 Sun Microsystems Sun 2 machines with Motorola 68010 CPU
  [NetBSD/sun3](../../ports/sun3/)                 Motorola 68020 and 030 based Sun 3 and 3x machines
  [NetBSD/vax](../../ports/vax/)                   Digital VAX
  [NetBSD/x68k](../../ports/x68k/)                 Sharp X680x0 series
  [NetBSD/xen](../../ports/xen/)                   The Xen virtual machine monitor
  [NetBSD/zaurus](../../ports/zaurus/)             Sharp ARM PDAs
  ------------------------------------------------ ---------------------------------------------------------------------------------------------------

</div>

Ports available in source form only for this release include the
following:

<div class="table">

  ---------------------------------- ------------------------------
  [NetBSD/ia64](../../ports/ia64/)   Itanium family of processors
  ---------------------------------- ------------------------------

</div>

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

Acknowledgments {.title style="clear: both"}
---------------

</div>

</div>

</div>

The NetBSD Foundation would like to thank all those who have contributed
code, hardware, documentation, funds, colocation for our servers, web
pages and other documentation, release engineering, and other resources
over the years. More information on the people who make NetBSD happen is
available at:

<div class="blockquote">

> [http://www.NetBSD.org/people/](../../people/)

</div>

We would like to especially thank the University of California at
Berkeley and the GNU Project for particularly large subsets of code that
we use. We would also like to thank the Internet Systems Consortium Inc.
and the Network Security Lab at Columbia University's Computer Science
Department for current colocation services.

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

About NetBSD {.title style="clear: both"}
------------

</div>

</div>

</div>

NetBSD is a free, fast, secure, and highly portable Unix-like Open
Source operating system. It is available for a wide range of platforms,
from large-scale servers and powerful desktop systems to handheld and
embedded devices. Its clean design and advanced features make it
excellent for use in both production and research environments, and the
source code is freely available under a business-friendly license.
NetBSD is developed and supported by a large and vibrant international
community. Many applications are readily available through [pkgsrc, the
NetBSD Packages Collection.](http://pkgsrc.org)

</div>

<div class="sect1">

<div class="titlepage">

<div>

<div>

About the NetBSD Foundation {.title style="clear: both"}
---------------------------

</div>

</div>

</div>

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

Donations can be done via PayPal to `<paypal@NetBSD.org>`{.email}, or
via Google Checkout and are fully tax-deductible in the US. See
[http://www.NetBSD.org/donations/](http://www.NetBSD.org/donations/#how-to-donate)
for more information, or contact `<finance-exec@NetBSD.org>`{.email}
directly.

</div>

------------------------------------------------------------------------

Back to  *[NetBSD 7.x formal releases](./)*

</div>

</div>

</div>

<div class="navfoot">

</div>

<div id="footer">

<div id="footerContent">

<span
class="footfeed">[Contact](http://www.NetBSD.org/cgi-bin/feedback.cgi) |
</span><span class="footcopy">[Disclaimer](../../about/disclaimer.html)
| <span class="copyright">Copyright © 1994-2015 The NetBSD Foundation,
Inc. </span>ALL RIGHTS RESERVED.\
NetBSD^®^ is a registered trademark of The NetBSD Foundation,
Inc.</span>

</div>

</div>

</div>
