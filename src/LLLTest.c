
#include <NTL/LLL.h>
#include <fstream>
NTL_CLIENT

int main(int argc, char** argv)
{
   std::fstream inFile;
   std::ofstream outFile;
   inFile.open(argv[1]);
   if (!inFile) {
       printf("cannot read file");
       exit(1);
   }
   outFile.open(argv[2]);

   mat_ZZ B;
   long s;

#if 1
   inFile >> B;
#else
   long i, j;
   long n;
   printf("n: ");
   inFile >> n;

   long m;
   printf("m: ");
   inFile >> m;

   long k;
   printf("k: ");
   inFile >> k;
   inFile.close();

   B.SetDims(n, m);
   for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
         RandomLen(B(i,j), k);
         if (RandomBnd(2)) negate(B(i,j), B(i,j));
      }


#endif

   mat_ZZ U, B0, B1, B2;

   B0 = B;

   double t;
   ZZ d;

   B = B0;
   printf("LLL_FP...");
   t = GetTime();
   s = LLL_FP(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("LLL_QP...");
   t = GetTime();
   s = LLL_QP(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");


   B = B0;
   printf("LLL_XD...");
   t = GetTime();
   s = LLL_XD(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("LLL_RR...");
   t = GetTime();
   s = LLL_RR(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("G_LLL_FP...");
   t = GetTime();
   s = G_LLL_FP(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("G_LLL_QP...");
   t = GetTime();
   s = G_LLL_QP(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("G_LLL_XD...");
   t = GetTime();
   s = G_LLL_XD(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");

   B = B0;
   printf("G_LLL_RR...");
   t = GetTime();
   s = G_LLL_RR(B, U, 0.99);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");
   LLL(d, B, 90, 100);
   if (B1 != B) TerminalError("bad LLLTest (2)");


   B = B0;
   printf("LLL...");
   t = GetTime();
   s = LLL(d, B, U);
   printf("%f\n",(GetTime()-t));
   mul(B1, U, B0);
   if (B1 != B) TerminalError("bad LLLTest (1)");

   outFile << "rank = " << s << "\n";
   outFile << "det = " << d << "\n";
   outFile << "B = " << B << "\n";
   outFile << "U = " << U << "\n";
   outFile.close();
   return 0;
}

