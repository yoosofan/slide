#!/bin/bash
if [ ! $1 ]; then
  SRC_PATH=src/mystack/*.cpp
else
  SRC_PATH="$1"/*.cpp
fi
for filename in $SRC_PATH; do
  echo "$filename"
  g++ "$filename" 
done
rm a.out
