
#include <NTL/quad_float.h>
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

   quad_float a, b, c, d;

   quad_float::SetOutputPrecision(25);

   if (PrecisionOK())
      outFile << "Precision OK\n";
   else
      outFile << "Precision not OK\n";


   inFile >> a;
   outFile << a << "\n";

   inFile >> b;
   outFile << b << "\n";
   inFile.close();

   c = a + b;
   d = a;
   d += b;
   outFile << c << "\n";
   outFile << d << "\n";

   c = a - b;
   d = a;
   d -= b;
   outFile << c << "\n";
   outFile << d << "\n";

   c = a * b;
   d = a;
   d *= b;
   outFile << c << "\n";
   outFile << d << "\n";

   c = a / b;
   d = a;
   d /= b;
   outFile << c << "\n";
   outFile << d << "\n";

   c = -a;
   outFile << c << "\n";

   c = sqrt(a);
   outFile << c << "\n";

   power(c, to_quad_float(10), 20);
   outFile << c << "\n";

   {

   long n, n1;
   int shamt = min(NTL_BITS_PER_LONG,2*NTL_DOUBLE_PRECISION);

   n = to_long((1UL << (shamt-1)) - 1UL);
   c = to_quad_float(n);
   n1 = to_long(c);

   if (n1 == n)
      outFile << "long conversion OK\n";
   else
      outFile << "long conversion not OK\n";

   n = to_long(1UL << (shamt-1));
   c = to_quad_float(n);
   n1 = to_long(c);

   if (n1 == n)
      outFile << "long conversion OK\n";
   else
      outFile << "long conversion not OK\n";

   }

   {

   unsigned long n;
   ZZ n1;
   int shamt = min(NTL_BITS_PER_LONG,2*NTL_DOUBLE_PRECISION);

   n = (1UL << (shamt-1)) - 1UL;
   c = to_quad_float(n);
   n1 = to_ZZ(c);

   if (n1 == to_ZZ(n))
      outFile << "ulong conversion OK\n";
   else
      outFile << "ulong conversion not OK\n";

   n = 1UL << (shamt-1);
   c = to_quad_float(n);
   n1 = to_ZZ(c);

   if (n1 == to_ZZ(n))
      outFile << "ulong conversion OK\n";
   else
      outFile << "ulong conversion not OK\n";

   }
   outFile.close();
}
