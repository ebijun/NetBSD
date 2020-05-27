#https://twitter.com/tsutsuii/status/1262429647364427783
#1) nono-0.0.3 をダウンロード
#https://twitter.com/isaki68k/status/1261646479816404992
#2) 展開して doc/index.html を読んでビルド
#3) liveimage をダウンロードして gunzip
#4) nono.cfg を作って置く
#https://gist.github.com/tsutsui/340546bdc064cee786ed2473fb510463
#
#5) wx/nono で実行
#6) Emulated ROM上で以下のコマンドを実行
#k
#[enter]
#[enter]
#d
#boot
#g
#x
#
TEO=http://teokurebsd.org/netbsd/liveimage/20200518-luna68k
IMAGE=liveimage-luna68k-raw-20200518.img.gz

#https://gist.github.com/tsutsui/340546bdc064cee786ed2473fb510463
CONFIG=https://gist.githubusercontent.com/tsutsui/340546bdc064cee786ed2473fb510463/raw/24f6f3312ea89509044792d3b5a915aaac971a06/nono.cfg

nono.cfg:
	ftp ${CONFIG}

fetch:
	ftp ${TEO}/${IMAGE}
	gunzip ${IMAGE}
