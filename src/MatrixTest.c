
#include <NTL/mat_ZZ.h>
#include <NTL/mat_poly_ZZ.h>
#include <NTL/HNF.h>
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

   mat_ZZ B, X;
   vec_ZZ v, w;

   inFile >> B;
   inFile >> v;

   ZZ d;

   outFile.open(argv[2]);

   double t;
   printf("matrix inverse...");
   t = GetTime();
   inv(d, X, B);
   printf("%f\n",(GetTime()-t));

   outFile << d << "\n";
   outFile << X << "\n";

   outFile << "\n\n\n";

   printf("hensel solve...");
   t = GetTime();
   HenselSolve1(d, w, B, v);
   printf("%f\n",(GetTime()-t));

   outFile << d << "\n";
   outFile << w << "\n";

   outFile << "\n\n\n";

   ZZX f;

   printf("char poly...");
   t = GetTime();
   CharPoly(f, B);
   printf("%f\n",(GetTime()-t));

   outFile << f << "\n";

   outFile << "\n\n\n";

   printf("HNF...");
   t = GetTime();
   HNF(X, B, d);
   printf("%f\n",(GetTime()-t));

   outFile << X;

   outFile.close();
   return 0;
}
