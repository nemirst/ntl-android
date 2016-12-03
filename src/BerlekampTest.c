
#include <NTL/ZZ_pXFactoring.h>
#include <fstream>

NTL_CLIENT


long compare(const ZZ_pX& a, const ZZ_pX& b)
{
   if (deg(a) < deg(b))
      return 0;

   if (deg(a) > deg(b))
      return 1;

   long n = a.rep.length();
   long i;

   for (i = 0; i < n; i++) {
      if (rep(a.rep[i]) < rep(b.rep[i])) return 0;
      if (rep(a.rep[i]) > rep(b.rep[i])) return 1;
   }

   return 0;
}

void sort(vec_pair_ZZ_pX_long& v)
{
   long n = v.length();
   long i, j;

   for (i = 0; i < n-1; i++)
      for (j = 0; j < n-1-i; j++)
         if (compare(v[j].a, v[j+1].a)) {
            swap(v[j].a, v[j+1].a);
            swap(v[j].b, v[j+1].b);
         }
}


int main(int argc, char** argv)
{
   std::fstream inFile;
   std::ofstream outFile;
   inFile.open(argv[1]);
   if (!inFile) {
       printf("cannot read file");
       exit(1);
   }

   ZZ p;
   inFile >> p;
   ZZ_p::init(p);
   ZZ_pX f;

   inFile >> f;
   inFile.close();
   printf("Reading File Done");

   outFile.open (argv[2]);

   vec_pair_ZZ_pX_long factors;

   double t = GetTime();
   berlekamp(factors, f, 1);
   t = GetTime()-t;
   printf("total time: %s\n", t);

   ZZ_pX ff;

   mul(ff, factors);
   if (f != ff)
      TerminalError("Incorrect factorization!!");

   sort(factors);

   printf("factorization pattern:");
   long i;

   for (i = 0; i < factors.length(); i++) {
      printf(" ");
      long k = factors[i].b;
      if (k > 1)
	printf("%f*", k);
      cerr << deg(factors[i].a);
   }

   printf("\n");



   outFile << factors << "\n";

   outFile.close();
   return 0;
}
