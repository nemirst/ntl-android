
#include <NTL/ZZX.h>
#include <NTL/ZZ_pX.h>
#include <NTL/lzz_pX.h>
#include <NTL/GF2X.h>

#include <NTL/version.h>

NTL_CLIENT


#define make_string_aux(x) #x
#define make_string(x) make_string_aux(x)

int SmallModulusTest(long p, long n)
{
   zz_pBak bak;

   bak.save();


   zz_p::init(p);

   zz_pX a, b, c, cc;

   random(a, n);
   random(b, n);
   PlainMul(c, a, b);
   FFTMul(cc, a, b);

   int res;
   res = (c != cc);

   bak.restore();

   return res;
}


int GF2X_test()
{
   GF2X a, b, c, c1;

   long n;

#ifdef NTL_GF2X_LIB
   for (n = 32; n <= (1L << 18); n = n << 1) {
      random(a, n);
      random(b, n);
      OldMul(c, a, b);
      mul(c1, a, b);
      if (c1 != c) return 1;
   }
#endif

   return 0;
}

void GF2X_time()
{
   long n = 1000000L;
   long iter;

   GF2X a, b, c;

   double t;
   long i;

   random(a, n);
   random(b, n);

   mul(c, a, b);

   iter = 0;
   do {
      iter = iter ? (2*iter) : 1;
      t = GetTime();
      for (i = 0; i < iter; i++)
         mul(c, a, b);
      t = GetTime() - t;
   } while (t < 0.5);

   printf("time to multiply polynomials over GF(2) \n   of degree < 1000000: %fs\n",(t/iter));

#ifdef NTL_GF2X_LIB
   OldMul(c, a, b);

   iter = 0;
   do {
      iter = iter ? (2*iter) : 1;
      t = GetTime();
      for (i = 0; i < iter; i++)
         OldMul(c, a, b);
      t = GetTime() - t;
   } while (t < 0.5);

   printf("   **** using old code: %fs\n",(t/iter));
#endif

}



ZZX KarMul(const ZZX& a, const ZZX& b)
{
   ZZX res;
   KarMul(res, a, b);
   return res;
}



int main()
{
   SetSeed(ZZ(0));


   printf("This is NTL version %s\n",NTL_VERSION);

   printf("Hardware charactersitics:\n");
   printf("NTL_BITS_PER_LONG = %d\n", NTL_BITS_PER_LONG);
   printf("NTL_ZZ_NBITS = %d\n", NTL_ZZ_NBITS);
   printf("NTL_SP_NBITS = %d\n", NTL_SP_NBITS);

#ifdef NTL_HAVE_LL_TYPE
   printf("NTL_HAVE_LL_TYPE\n");
#endif

#ifdef NTL_LONGDOUBLE_SP_MULMOD
   printf("NTL_LONGDOUBLE_SP_MULMOD\n");
#endif

#ifdef NTL_LONGLONG_SP_MULMOD
   printf("NTL_LONGLONG_SP_MULMOD\n");
#endif

  printf("\n");

   


	  printf("Basic Configuration Options:\n");



#ifdef NTL_LEGACY_NO_NAMESPACE
	  printf("NTL_LEGACY_NO_NAMESPACE\n");
#endif


#ifdef NTL_LEGACY_INPUT_ERROR
	  printf("NTL_LEGACY_INPUT_ERROR\n");
#endif


#ifdef NTL_THREADS
	  printf("NTL_THREADS\n");
#endif


#ifdef NTL_EXCEPTIONS
	  printf("NTL_EXCEPTIONS\n");
#endif

#ifdef NTL_THREAD_BOOST
	  printf("NTL_THREAD_BOOST\n");
#endif


#ifdef NTL_LEGACY_SP_MULMOD
	  printf("NTL_LEGACY_SP_MULMOD\n");
#endif


#ifdef NTL_DISABLE_LONGDOUBLE
	  printf("NTL_DISABLE_LONGDOUBLE\n");
#endif


#ifdef NTL_DISABLE_LONGLONG
	  printf("NTL_DISABLE_LONGLONG\n");
#endif

#ifdef NTL_MAXIMIZE_SP_NBITS
	  printf("NTL_MAXIMIZE_SP_NBITS\n");
#endif




#ifdef NTL_GMP_LIP
	  printf("NTL_GMP_LIP\n");
#endif


#ifdef NTL_GF2X_LIB
	  printf("NTL_GF2X_LIB\n");
#endif


#ifdef NTL_PCLMUL
	  printf("NTL_PCLMUL\n");
#endif


#ifdef NTL_LONG_LONG_TYPE
   printf("NTL_LONG_LONG_TYPE: %s\n", make_string(NTL_LONG_LONG_TYPE));
#endif

#ifdef NTL_UNSIGNED_LONG_LONG_TYPE
   printf("NTL_UNSIGNED_LONG_LONG_TYPE: %s\n", make_string(NTL_UNSIGNED_LONG_LONG_TYPE));
#endif


#ifdef NTL_X86_FIX
   printf("NTL_X86_FIX\n");
#endif

#ifdef NTL_NO_X86_FIX
   printf("NTL_NO_X86_FIX\n");
#endif

#ifdef NTL_NO_INIT_TRANS
   printf("NTL_NO_INIT_TRANS\n");
#endif

#ifdef NTL_CLEAN_INT
   printf("NTL_CLEAN_INT\n");
#endif

#ifdef NTL_CLEAN_PTR
   printf("NTL_CLEAN_PTR\n");
#endif

#ifdef NTL_RANGE_CHECK
   printf("NTL_RANGE_CHECK\n");
#endif


   printf("\n");
   printf("Resolution of double-word types:\n%s\n%s\n", make_string(NTL_LL_TYPE), make_string(NTL_ULL_TYPE));


   printf("\n");
   printf("Performance Options:\n");

#ifdef NTL_LONG_LONG
   printf("NTL_LONG_LONG\n");
#endif

#ifdef NTL_AVOID_FLOAT
   printf("NTL_AVOID_FLOAT\n");
#endif


#ifdef NTL_SPMM_ULL
   printf("NTL_SPMM_ULL\n");
#endif


#ifdef NTL_SPMM_ASM
   printf("NTL_SPMM_ASM\n");
#endif




#ifdef NTL_AVOID_BRANCHING
   printf("NTL_AVOID_BRANCHING\n");
#endif


#ifdef NTL_FFT_BIGTAB
   printf("NTL_FFT_BIGTAB\n");
#endif

#ifdef NTL_FFT_LAZYMUL
   printf("NTL_FFT_LAZYMUL\n");
#endif





#ifdef NTL_TBL_REM
   printf("NTL_TBL_REM\n");
#endif


#ifdef NTL_TBL_REM_LL
   printf("NTL_TBL_REM_LL\n");
#endif

#ifdef NTL_CRT_ALTCODE
   printf("NTL_CRT_ALTCODE\n");
#endif

#ifdef NTL_CRT_ALTCODE_SMALL
   printf("NTL_CRT_ALTCODE_SMALL\n");
#endif

#ifdef NTL_GF2X_ALTCODE
   printf("NTL_GF2X_ALTCODE\n");
#endif

#ifdef NTL_GF2X_ALTCODE1
   printf("NTL_GF2X_ALTCODE1\n");
#endif


#ifdef NTL_GF2X_NOINLINE
   printf("NTL_GF2X_NOINLINE\n");
#endif

   printf("\n\n");

   printf("running tests\n");

   long n, k, i;

   //n = 250;
   //k = 16000;
   n = 25;
   k = 1600;

   ZZ p;


   for (i = 0; i < 15; i++) {
     printf("%ld/%ld\n", n, k); 
     //printf(".");
      RandomLen(p, k);
      ZZ_p::init(p);  
    
      ZZ_pX a, b, c, c1;

      random(a, n);
      random(b, n);

      FFTMul(c, a, b);
      //printf(ZZ_pInfo->FFTInfo->NumPrimes;

      c1 = conv<ZZ_pX>( KarMul( conv<ZZX>(a), conv<ZZX>(b) ) );
      if (c1 != c) {
         printf("ZZ_pX mul failed!\n");
         return 1;
      }

      n = long(n * 1.35);
      k = long(k / 1.414);
   }


   // small prime tests...I've made some changes in v5.3
   // that should be checked on various platforms, so 
   // we might as well check them here.

   if (SmallModulusTest(17, 1000)) {
      printf("first SmallModulusTest failed!!\n");
      return 1;
   }

   if (SmallModulusTest((1L << (NTL_SP_NBITS))-1, 1000)) {
      printf("second SmallModulusTest failed!!\n");
      return 1;
   }

   // Test gf2x code....

   if (GF2X_test()) {
      printf("GF2X test failed!\n");
      return 1;
   }
   

   printf("OK\n");

   ZZ x1, x2, x3, x4;
   double t;

   RandomLen(x1, 1024);
   RandomBnd(x2, x1);
   RandomBnd(x3, x1);

   mul(x4, x2, x3);

   t = GetTime();
   //for (i = 0; i < 100000; i++)
   for (i = 0; i < 1000; i++)
      mul(x4, x2, x3);
   t = GetTime()-t;

   printf("time for 1024-bit mul: %fus\n", t*10);

   rem(x2, x4, x1);

   t = GetTime();
   //for (i = 0; i < 100000; i++)
   for (i = 0; i < 1000; i++)
      rem(x2, x4, x1);
   t = GetTime()-t;

   printf("time for 2048/1024-bit rem: %fus\n", t*10); 
   

   GenPrime(p, 1024);
   RandomBnd(x1, p);
   if (IsZero(x1)) set(x1);

   InvMod(x2, x1, p);

   t = GetTime();
   //for (i = 0; i < 1000; i++)
   for (i = 0; i < 10; i++)
      InvMod(x2, x1, p);
   t = GetTime()-t;

   printf("time for 1024-bit modular inverse: %fus\n", t*1000);



   // test modulus switching
   
   //n = 1024;
   //k = 1024;
   n = 128;
   k = 128;
   RandomLen(p, k);

   ZZ_p::init(p);
   if (!IsOdd(p)) p++;

   ZZ_pX j1, j2, j3;

   random(j1, n);
   random(j2, n);

   mul(j3, j1, j2);

   t = GetTime();
   //for (i = 0; i < 200; i++) mul(j3, j1, j2);
   for (i = 0; i < 20; i++) mul(j3, j1, j2);
   t = GetTime()-t;

   //printf("time to multiply degree 1023 polynomials\n   modulo a 1024-bit number: %fs\n",(t/200));
   printf("time to multiply degree 1023 polynomials\n   modulo a 1024-bit number: %fs\n",(t/20));

   GF2X_time();

   return 0;
}
