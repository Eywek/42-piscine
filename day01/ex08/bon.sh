#/bin/sh
ldapsearch -LLLQ sn='*bon*' sn | grep ^sn | wc -l | bc
