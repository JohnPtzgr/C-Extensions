#include <stdlib.h>
#pragma once


#define __AUX_HASH_S_ULL_A__ 965637331582839863llu
#define __AUX_HASH_S_ULL_B__ 909344112013743667llu
#define __AUX_HASH_S_ULL_C__ 912041355637047187llu
#define __AUX_HASH_S_ULL_D__ 983320077192325787llu
#define __AUX_HASH_S_ULL_E__ 959850976430004887llu

#define __AUX_HASH_SINGLE__(X) (1 + (X + __AUX_HASH_S_ULL_A__) ^ __AUX_HASH_S_ULL_B__)

#define __AUX_16_BYTE_HASH_EXP__(A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S...) \
  (__AUX_HASH_SINGLE__(A) * __AUX_HASH_SINGLE__(B) * __AUX_HASH_SINGLE__(C) * __AUX_HASH_SINGLE__(D) * \
   __AUX_HASH_SINGLE__(E) * __AUX_HASH_SINGLE__(F) * __AUX_HASH_SINGLE__(G) * __AUX_HASH_SINGLE__(H) * \
   __AUX_HASH_SINGLE__(I) * __AUX_HASH_SINGLE__(J) * __AUX_HASH_SINGLE__(K) * __AUX_HASH_SINGLE__(L) * \
   __AUX_HASH_SINGLE__(M) * __AUX_HASH_SINGLE__(N) * __AUX_HASH_SINGLE__(O) * __AUX_HASH_SINGLE__(P) * \
   __AUX_HASH_SINGLE__(Q) * (R + 1llu))

#define __AUX_16_BYTE_HASH__(X...) (__AUX_16_BYTE_HASH_EXP__(__AUX_HASH_S_ULL_C__, X, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))

#define __AUX_16_BYTE_HASH_S__(R, X...) (__AUX_16_BYTE_HASH_EXP__(R, X, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))

#define _CE_HASH16(X) __AUX_16_BYTE_HASH__(X)

#define _CE_SHASH16(X) __AUX_16_BYTE_HASH_S__(S, X)

size_t hash_finalise(size_t);

size_t hash_byte_array(void*, size_t);

