Raspberry PIのイメージをつくろう
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Raspberry　PIで動くイメージの作り方を説明します。

ISOイメージ取得
--------------------
NetBSDのISOイメージをダウンロードします。
ダウンロードには、以下のRubyスクリプトを使っています。

　https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/NewestISO

編集するところ：ftpサーバを選ぶ

FTP="nyftp.netbsd.org"
#FTP="ftp.jp.netbsd.org"
#FTP="ftp7.jp.netbsd.org"

編集するところ: アーキテクチャ選択

#ARCH="earmv7hf"
ARCH="earmv6hf"
#ARCH="earm"

コマンドを実行すると、指定したftpサーバが持っている最新のイメージをダウンロードするためのスクリプトを生成します。

./NewestISO

$ ./NewestISO 
wget ftp://nyftp.netbsd.org/pub/NetBSD-daily/HEAD/201511241720Z/images/NetBSD-7.99.21-evbarm-earmv6hf.iso
mv NetBSD-7.99.21-evbarm-earmv6hf.iso ./NetBSD-7.99.21-evbarm-earmv6hf-201511241720Z.iso

コマンドの出力結果をshに渡すとダウンロードを実行します。

$ ./NewestISO |sh

ダウンロードがうまくいくと、以下のようなisoイメージをダウンロードできます。
NetBSD-7.99.21-evbarm-earmv6hf-201511241720Z.iso


イメージ作成用Makefile
--------------------------

イメージファイルを作るためにMakefileを作っています。
https://github.com/ebijun/NetBSD/blob/master/RPI/RPIimage/Image/Makefile

編集するところ：
ARCH=earmv6hf
#ARCH=earmhf
#ARCH=earm
PKG_PATH=ftp://ftp.netbsd.org/pub/NetBSD/misc/jun/raspberry-pi/${ARCH}/2015-11-14/

# iso file information
IMAGE=/usr/release/images/NetBSD-7.99.21-evbarm-${ARCH}-201511091610Z.iso

PKGSRC=../../../pkgsrc/pkgsrc-2015Q3.tar.gz 
#	echo extract pkgsrc.
#	tar xzpf ${PKGSRC} -C ${MNT}/usr



make を実行するとイメージファイルができます。
make releaseを実行すると、初期設定ファイル等をコピーします。

make pkgを実行すると、パッケージをインストールするための準備ができます。

./Copy を実行して、パッケージをコピーします。

RPI2にさして、ブートするか確認します。

cd Package 
edit Install
./Install

パッケージをインストールします。

再起動して、fontconfigを実行しておきます。

RPIに差し替えて起動して、dmesgを出力しておきます。

イメージをもどして、backを実行します。
ディレクトリに2種類のdmesg,pkginfoができます。

make logclean
make release
を実行します。

ここでRPIにさして起動して、自動リサイズが正しく起動するか確認します。

rootでログインします。

startxを実行します。

mikutterを起動します。

認証し、ついーとしてみます。
あひる焼き

リリースメールを書きます。
dmesg/pkginfoを書きます。
通知します。
port-arm
RPIのフォーラム


