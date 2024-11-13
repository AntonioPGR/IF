FILE=$1

gcc "$FILE.c" -o "${FILE}.out"

./"${FILE}.out"

rm -f "${FILE}.out"
