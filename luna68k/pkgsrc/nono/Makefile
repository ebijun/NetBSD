# $NetBSD$

DISTNAME=	nono-0.1.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pastel-flower.jp/~isaki/nono/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pastel-flower.jp/~isaki/nono/
COMMENT=	OMRON LUNA-I emulator
LICENSE=	nono-license

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

GCC_REQD+=	7

DEPENDS+=	wxGTK30-[0-9]*:../../x11/wxGTK30

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS+=	share/doc/nono

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}/${PREFIX}/share/doc/nono
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}/${PREFIX}/share/doc/nono

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
