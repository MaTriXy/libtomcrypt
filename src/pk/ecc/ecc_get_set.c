/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 */

#include "tomcrypt.h"

#ifdef LTC_MECC

int ecc_get_curve_by_name(const char* name, const ltc_ecc_curve** cu)
{
   int i;

   LTC_ARGCHK(cu != NULL);
   LTC_ARGCHK(name != NULL);

   *cu = NULL;

   for (i = 0; ltc_ecc_curves[i].prime != NULL; i++) {
      if (XSTRCMP(ltc_ecc_curves[i].name, name) == 0) {
         *cu = &ltc_ecc_curves[i];
         return CRYPT_OK;
      };
   }

   return CRYPT_INVALID_ARG; /* not found */
}

#endif

/* ref:         $Format:%D$ */
/* git commit:  $Format:%H$ */
/* commit time: $Format:%ai$ */
