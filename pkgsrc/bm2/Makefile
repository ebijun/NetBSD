# $NetBSD$

DISTNAME=	bm2src_20260125
PKGNAME=	bm2-20260125
CATEGORIES=	games
MASTER_SITES=	https://ver0.sakura.ne.jp/pc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ver0.sakura.ne.jp/pc/
COMMENT=	Hitachi Basic Master Jr. (MB-6885) emulator
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/bm2

INSTALLATION_DIRS=	bin share/examples/bm2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bm2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bm2config ${DESTDIR}${PREFIX}/share/examples/bm2

# Ensure SDL2 libraries are explicitly linked since the source Makefile
# may fail to resolve $(shell sdl2-config --libs) in the pkgsrc environment.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.SDL2}/lib -L${BUILDLINK_PREFIX.SDL2}/lib -lSDL2

# Include SDL2 build settings to resolve SDL.h header path and libraries
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../devel/SDL/buildlink3.mk"
