/*
Copyright (c) 2015-2016, Apple Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
    in the documentation and/or other materials provided with the distribution.

3.  Neither the name of the copyright holder(s) nor the names of any contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LZVN_H
#define LZVN_H

#include <stddef.h>

size_t lzvn_decode_scratch_size(void);
size_t lzvn_encode_scratch_size(void);
size_t lzvn_encode_buffer(void *dst, size_t dst_size,
			  const void *src, size_t src_size,
			  void *work);
size_t lzvn_decode_buffer(void *dst, size_t dst_size,
			  const void *src, size_t src_size);

// MARK: - LZVN encode/decode interfaces

//  Minimum source buffer size for compression. Smaller buffers will not be
//  compressed; the lzvn encoder will simply return.
#define LZVN_ENCODE_MIN_SRC_SIZE ((size_t)8)

//  Maximum source buffer size for compression. Larger buffers will be
//  compressed partially.
#define LZVN_ENCODE_MAX_SRC_SIZE ((size_t)0xffffffffU)

//  Minimum destination buffer size for compression. No compression will take
//  place if smaller.
#define LZVN_ENCODE_MIN_DST_SIZE ((size_t)8)


#endif // end of LZVN_H
