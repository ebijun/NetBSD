toukou:
	ftp https://teokurebsd.org/p6/toukoumiku/toukoumiku-PC6001.zip

mizu:
	#ftp https://bn-x.tripod.com/02tinymizu/tiny_mizuiro_prologue.wma
	ftp http://www.ceres.dti.ne.jp/tsutsui/p6/tiny_mizuiro/tiny_mizuiro_prologue_PSG.zip

echo:
	echo 画像変換 for PC-6001でVRAMをダウンロードして
	echo PC6001VXモニタモードで
	echo loadm ファイル名 0xe000 0xf9ff 
	echo out 0xb0 0xf2
	echo 事前に screen 3,2,2 とか screen 4,2,2 とか実行しておいて BASICで何かしら初期化したあとにデバッガで
	echo loadmem [ファイル名] 0xe000 0xf9ff
	echo でロードして、デバッガから戻って PAGEキー（PAGE UPキー）を押すとグラフィック画面出ると思います
