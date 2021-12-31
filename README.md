LZFSE
=====

This is a reference C implementation of the LZFSE compressor introduced in the
[Compression library](https://developer.apple.com/library/mac/documentation/Performance/Reference/Compression/index.html) with OS X 10.11 and iOS 9.

LZFSE is a Lempel-Ziv style data compression algorithm using Finite State Entropy coding.
It targets similar compression rates at higher compression and decompression speed compared to deflate using zlib.

Usage:
1) git clone https://github.com/Damenly/lzfse /usr/src/lzfse-0.1
2) dkms add -m lzfse -v 0.1
3) dkms build -m lzfse -v 0.1
4) dkms install -m lzfse -v 0.1
5) modprobe lzfse
