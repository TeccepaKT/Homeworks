#!/bin/bash

# Войдите в папку contest-? и используйте ../add.sh, чтобы добавить в индекс файлы для ревью

addfile="$(pwd)/.add"
if ! [ -f $addfile ]; then
    echo "There are no .add file"
    exit 0
fi

files="$(cat "${addfile}")"
adds=""
for filename in ${files//?/& } ; do
    filename=$filename.cpp
    if [ -f "$filename" ]; then
        adds+="$filename "
    fi;
done

git add $adds
