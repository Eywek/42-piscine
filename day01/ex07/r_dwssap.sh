#/bin/sh
cat /etc/passwd | grep -v '^#' | awk '{if(!(NR % 2))print $0}' | rev | cut -d ':' -f 7 | sort -r | awk '{if(NR >= '$FT_LINE1' && NR <= '$FT_LINE2')print $0}' | paste -sd ',' - | sed 's/,/, /g' | sed 's/[^.]$/&./' | tr -d "\n"
