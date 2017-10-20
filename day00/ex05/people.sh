#!/bin/sh
ldapsearch -xLLL "(uid=z*)" cn | grep ^cn | cut -c 5- | sort -f -d -r
