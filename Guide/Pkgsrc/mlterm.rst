mlterm-fbを使ってみる
---------------------
 リソースが限られているマシンでは、Xを起動するのも大変な場合があります。
Xを起動しない状態で、日本語を表示するために、pkgsrc経由でmlterm-fbを
インストールして、使ってみます。

mlterm-fb向けオプション設定
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 /etc/mk.confに、mlterm-fb向けのオプションを追加します。

::

 # vi /etc/mk.conf
 PKG_OPTIONS.mlterm=xft2 mlterm-fb

mlterm-fbをインストール
~~~~~~~~~~~~~~~~~~~~~~~~
 pkgsrcからmltermをインストールします。

::

 # cd /usr/pkgsrc/x11/mlterm
 # make package-install
 # which /usr/pkg/bin/mlterm-fb
 /usr/pkg/bin/mlterm-fb                ..... /usr/pkg/bin/以下にインストール

起動
~~~~
 コンソール画面からmlterm-fbを起動します。

::

 % mlterm-fb

テスト画像表示
~~~~~~~~~~~~~~
 mlterm-fbを起動した状態で、catを利用して、画像イメージを表示します。

::

 % ftp http://mlterm.sourceforge.net/vimperator.six
 % cat vimperator.six

mltermについて
~~~~~~~~~~~~~~~
 *http://mlterm.sourceforge.net/* に、より詳しい情報があります。

