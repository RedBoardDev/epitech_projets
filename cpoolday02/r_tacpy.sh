sed -n 2~2p | cut -d ':' -f 1 | rev | sort -r | sed -n ${MY_LINE1}${MY_LINE2}p | sed 's/$/, /' | tr -d '\n' | sed 's/, $/./'
