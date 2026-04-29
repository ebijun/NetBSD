.. 
 Copyright (c) 2025 Jun Ebihara All rights reserved.
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=================================
stable-diffusion.cppを使ってみる
=================================

特徴
----

* キーワードから画像を生成します。
* NetBSD/amd64,NetBSD/aarch64で動作しています。

準備するもの
-------------

* NetBSD/amd64,NetBSD/aarch64
* 24GB程度の合計スワップ領域(8GB+16GBとか)
* pkgsrc/devel/cmake

スワップ領域の追加
-------------------

::

 swapctl -lg
 dd if=/dev/zero of=swap1 count=20000000
 chmod 600 swap101
 swapadd swap101
 swapctl -lg


cmakeのインストール
--------------

::

 cd /usr/pkgsrc/devel/cmake
 make package-install
 
stable-diffusion.cppのインストール
-----------------------------------

::

 git clone --recursive https://github.com/leejet/stable-diffusion.cpp
 cd stable-diffusion.cpp
 mkdir build
 cd build
 cmake ..
 cmake --build . --config Release


stable-diffusion-v3-2のダウンロード
-----------------------------------

::

 https://huggingface.co/stabilityai/stable-diffusion-3-medium
 Files and versionsタブをひらく
 https://huggingface.co/stabilityai/stable-diffusion-3-medium/blob/main/sd3_medium_incl_clips_t5xxlfp16.safetensors
 をダウンロードする。
 
画像の生成例
------------

::

 ./bin/sd -m ../../models/stable-diffusion-v3-2/sd3_medium_incl_clips_t5xxlfp16.safetensors
 --cfg-scale 5
 --steps 30
 --sampling-method euler
 --seed 42 
 -o test.png
 -b 2
 -p "A girl of about 17 years old, with blonde hair and blue eyes, 
 wearing a white dress, standing in a meadow, with the wind blowing. 
 She is raising her hair with one hand. 
 In the distance, mountains can be seen, 
 and in the foreground, a river is flowing. 
 The sunset is visible above the mountains, 
 and the girl is smiling in Kancolle style."
 
引数の説明
------------

.. csv-table:: 


 **./bin/sd**,stable-diffusion.cpp の実行ファイルへのパスです。
 **-m <モデルパス>**,使用するモデルファイル（Stable Diffusion 3 Medium）を指定ししています。
 **--cfg-scale**,生成される画像がプロンプトにどれだけ忠実になるかを調整するパラメータです。**6** という値は、一般的に自然でバランスの取れた画像を得るための標準的な範囲内です。                                             ,
 **--steps**,画像生成のステップ数を指定しています。**30** は、速さと品質のバランスが取れた一般的な設定です。                                                                            ,
 **--sampling-method**,使用するサンプラー（ノイズ除去アルゴリズム）を指定しています。`euler` は最も基本的なサンプラーの一つで、特に問題ありません。他の高速なサンプラー（例：`eulera`、`dpmpp_2m`など）を試すことも可能です。               ,
 **--seed**,乱数シードを指定しています。特定の画像を再現したり、似た画像を連続して生成したりするのに有用です。                                                                              ,
 **-o <出力パス>**,出力ファイル名を指定しています。 `\``date +%Y%m%d-%H%M`\`\`  の部分は、実行時に「年-月-日-時-分」の形式のタイムスタンプに置き換えられることを意図しており、連番のファイル名を自動生成する一般的なシェル技法として有効です。


