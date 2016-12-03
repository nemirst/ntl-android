#include <NTL/ZZXFactoring.h>
#include <fstream>

NTL_CLIENT

long NumFacs(const vec_pair_ZZX_long& v)
{
   long i;
   long res;

   res = 0;
   
   for (i = 0; i < v.length(); i++)
      res += v[i].b;

   return res;
}


int main(int argc, char** argv)
{
   std::fstream inFile;
   inFile.open(argv[1]);
   if (!inFile) {
       printf("cannot read file");
       exit(1);
   }

   long cnt = 0;
   while (SkipWhiteSpace(inFile)) {
      cnt++;
      printf(".");

      vec_ZZ w;
      ZZX f1, f;
      long nfacs;

      inFile >> w;
      inFile >> nfacs;

      long i, n;
      n = w.length();
      f.rep.SetLength(n);
      for (i = 0; i < n; i++)
         f.rep[i] = w[n-1-i];
      f.normalize();

      vec_pair_ZZX_long factors;
      ZZ c;

      factor(c, factors, f, 0);


      mul(f1, factors);
      mul(f1, f1, c);

      if (f != f1) {
         //printf("%f\n",f);
         //cerr << c << " " << factors << "\n"; //factors data type doesn't play well with printf...
         TerminalError("FACTORIZATION INCORRECT (1) !!!");
      }

      long nfacs1 = NumFacs(factors);

      if (nfacs1 != nfacs)
         TerminalError("FACTORIZATION INCORRECT (2) !!!");
   }

   
   inFile.close();
   printf("\nMoreFacTest OK\n");

   return 0;
}
