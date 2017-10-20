#!/bin/sh
cat $1 | grep -i ^Nicolas | grep -i Bauer | grep '[0-9]\{3\}-[0-9]\{4\}' | cut -c 15- | cut -f1 -d$'\t'
