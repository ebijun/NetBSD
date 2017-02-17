SONY VGN-NW50JB


観光ガイドが作れるような環境が欲しい。

スペック
--------
http://www.sony.jp/vaio/products/NW/


購入先：
----------
ハードオフ 8000円 OSなし

VAIOロゴが出ているときにF2を押すとBIOSに入れます。
http://www.sony.jp/support/vaio/products/manual/vgn-nw/contents/03_rec/bios/01/01.html


i386でブート：
有線LAN以外は見えている。

http://nycdn.netbsd.org/pub/NetBSD-daily/HEAD/201702170310Z/images/
からイメージをダウンロード。

gunzip < NetBSD-7.99.59-amd64-install.img.gz |dd of=/dev/rsd0d bs=4m


内蔵ディスク
----------

http://pc.watch.impress.co.jp/docs/2008/1119/toshiba.htm


dmesg
-----------

https://github.com/ebijun/NetBSD/blob/master/dmesg/amd64/SONY_VGN-NW50JB


ネットワーク
-------------
無線はiwn。有線はMarvell

11ab:4380 Ethernet controller: Marvell Technology Group Ltd. Device 4380

vendor 11ab product 4380 (ethernet network, revision 0x10) at pci1 dev 0 function 0 not configured
Marvell 

http://pcidatabase.com/search.php?device_search_str=marvell
0x4380	Marvell Yukon 88E8057 PCI-E Gigabit Ethernet Controller	0x11AB	Marvell Semiconductor

msk(5)

https://github.com/openbsd/src/blob/master/sys/dev/pci/if_msk.c

https://github.com/openbsd/src/commit/a9bacf6bcc33e232077f0561c1bafeded058863e#diff-a833694910ceb931647eabedd240478c


vendor 1180 product 0592 (miscellaneous system, revision 0x12) at pci4 dev 3 
function 2 not configured

https://www.amazon.co.jp/PowerSmart-VGN-NW50JB-VAIO-VGN-NW70JB-VAIO-VGN-NW91FS-VAIO-VGN-NW91GS-VAIO/dp/B00HTZXU10/ref=sr_1_1ie=UTF8&qid=1487336118&sr=8-1&keywords=VGN-NW50JB


