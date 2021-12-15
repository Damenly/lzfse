#!/bin/sh
#

rm ./lzfse_strip -rf
mkdir lzfse_strip

for f in ./src/*.[ch]; do
    echo $f | grep main -q && continue
    cp $f lzfse_strip/
done

find lzfse_strip -name "*.[ch]" -exec sed -i 's/<stddef.h>/<linux\/stddef.h>/g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/<stdint.h>/<linux\/types.h>/g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/<string.h>/<linux\/string.h>/g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/#include <stdlib.h>//g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/#include <limits.h>//g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/#include <assert.h>//g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/assert*//g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/"lzfse.h"/<linux\/lzfse.h>/g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/"lzvn.h"/<linux\/lzvn.h>/g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/LZFSE_API //g'  {} +

find lzfse_strip -name "*.[ch]" -exec sed -i 's/INT32_MAX/S32_MAX/g'  {} +

sed -i 's/()/(void)/g' lzfse_strip/lzfse.h
sed -i 's/()/(void)/g' lzfse_strip/lzvn.h
