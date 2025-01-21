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

