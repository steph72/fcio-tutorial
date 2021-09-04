#!/bin/sh

set -e
DISCNAME="fcdemo.d81"

cat c65bin/c65toc64wrapper.prg bin/fcdemo.c64 > bin/autoboot.c65

mkdir -p res
for filename in img-src/*.png; do
  echo $filename
  python3 tools/png2fci.py -vr $filename res/$(basename $filename .png).fci
done

mkdir -p disc
c1541 -format fcdemo,sk d81 disc/$DISCNAME

for filename in res/*; do
  c1541 disc/$DISCNAME -write $filename
done

c1541 disc/$DISCNAME -write bin/autoboot.c65
