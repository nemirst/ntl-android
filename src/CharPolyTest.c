
#include <NTL/ZZX.h>
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
   ZZX a, f, g;

   inFile >> a;
   inFile >> f;

   double t = GetTime();
   CharPolyMod(g, a, f);
   printf("%f\n",GetTime()-t);

   outFile << g << "\n";
   outFile.close();
   return 0;
}
