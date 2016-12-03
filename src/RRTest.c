
#include <NTL/mat_RR.h>
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

   mat_RR A;
   vec_RR x, y, z;
   RR d;

   RR::SetPrecision(200);

   inFile >> A;
   inFile >> y;
   inFile.close();

   solve(d, x, A, y);

   // mul(z, x, A);
   // sub(z, z, y);

   z = x*A - y;

   outFile << d << "\n";
   outFile << x << "\n";
   outFile << z << "\n";
   outFile.close();

   return 0;
}
