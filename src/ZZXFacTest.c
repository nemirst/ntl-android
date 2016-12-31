#include <NTL/ZZXFactoring.h>
#include <fstream>
NTL_CLIENT


long compare(const ZZX& a, const ZZX& b)
{
   if (deg(a) < deg(b))
      return 0;

   if (deg(a) > deg(b))
      return 1;

   long n = a.rep.length();
   long i;

   for (i = 0; i < n; i++) {
      if (a.rep[i] < b.rep[i]) return 0;
      if (a.rep[i] > b.rep[i]) return 1;
   }

   return 0;
}
      

void sort(vec_pair_ZZX_long& v)
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
            
 

int main(int argc, char **argv)
{
   std::fstream inFile;
   std::ofstream outFile;
   inFile.open(argv[1]);
   if (!inFile) {
       printf("cannot read file");
       exit(1);
   }

   ZZX f1, f;

   if (argc > 2) 
      ZZXFac_MaxPrune = atoi(argv[2]);

   inFile >> f;
   inFile.close();
   printf("Reading File Done");

   outFile.open (argv[2]);

   vec_pair_ZZX_long factors;
   ZZ c;

   double t;

   t = GetTime();
   factor(c, factors, f, 0);
   t = GetTime()-t;

   printf("total time: %f\n", t );


   mul(f1, factors);
   mul(f1, f1, c);

   if (f != f1)
      TerminalError("FACTORIZATION INCORRECT!!!");



   sort(factors);

   outFile << c << "\n";
   outFile << factors << "\n";

   return 0;
}

