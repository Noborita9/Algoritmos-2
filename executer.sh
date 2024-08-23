#!/bin/bash

TEST_DIR="./casos"
OUT_FILE="./results.txt"

echo "$(date -I)" > $OUT_FILE
echo "" >> $OUT_FILE

for code in $@
do
    arg=$(echo $code | cut -d '.' -f 1)
    echo "Testing $arg:" >> $OUT_FILE
    $(g++ $code -o $arg)
    correct=0
    files=0
    for file in $(ls $TEST_DIR | grep ".in.txt" | cut -d '.' -f 1)
    do
        files=$((files+1))
        ./$arg < "$TEST_DIR/$file.in.txt" > "$TEST_DIR/$file.out.txt"
        df=$(diff --strip-trailing-cr "$TEST_DIR/$file.out.txt" "$TEST_DIR/$file.out.txt")
        if $df ; then
            correct=$((correct+1))
            echo "Test $files: Ok" >> $OUT_FILE
        else
            echo "Test $files: FAILED" >> $OUT_FILE
        fi
    done
    echo "-----------------------" >> $OUT_FILE
    echo "$correct out of $files" >> $OUT_FILE
    echo "-----------------------" >> $OUT_FILE
done

