NetBSDでの無線LAN設定
------------------------

1.　WEPの時

::

 # ifconfig iwn0 ssid "sdfsdfdsfsdf" nwkey "sdfsfsdfsfs"
 # ifconfig iwn0 ssid "sdfsdfdsfsdf" nwkey "0x0123ABCDEF" 

2.　WPA-PSKの時

/etc/wpa_supplicant.confに設定内容を書く。

::

 ctrl_interface=/var/run/wpa_supplicant
 ctrl_interface_group=wheel
 
 network={
        ssid="oschiroshima_booth_xx"
        scan_ssid=1
        key_mgmt=WPA-PSK
        psk="osc2011hiroshima1"
 }

と書いて、

::

 # ifconfig iwn0 up
 # /usr/sbin/wpa_supplicant -dd  -i iwn0 -c /etc/wpa_supplicant.conf

でうまく動いたら-ddをとる。

