#!/usr/bin/bash

EXECUTABLE=Mergesort
INPUTFOLDER=$HOME/postgrad/Mergesort/input

clear

rm -f Mergesort
gcc Mergesort.c -o $EXECUTABLE

if [[ -f "$EXECUTABLE" ]]; then
    echo $'\n'"$EXECUTABLE compiled with no errors."$'\n'
    Mergesort $INPUTFOLDER/Sample1
else
    echo $'\n'"$EXECUTABLE not compiled successfully."$'\n'
fi

echo