#/bin/sh
ifconfig | grep "ether" | cut -c 8- | rev | cut -c 2- | rev
