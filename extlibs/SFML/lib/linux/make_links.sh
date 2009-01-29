#!/bin/bash
for file in `ls *.so.*`
do
	rm -f ${file/.?.?/}
	ln -s $file ${file/.?.?/}
done
