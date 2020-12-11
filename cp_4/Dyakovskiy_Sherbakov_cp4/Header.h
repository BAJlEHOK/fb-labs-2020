
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <random>
#include <iomanip>
#include <fstream>


//using namespace boost::multiprecision;
using boost::multiprecision::cpp_int;
using namespace boost::random;
typedef independent_bits_engine<mt19937, 1024, cpp_int> generator_type;
generator_type gen(static_cast<unsigned int>(std::time(0)));

class KeyGen
{
public:
	cpp_int n; // open n = p*q
	cpp_int e; // open e = 2^16 + 1;  2 <= e <= fi(n)-1, fi -- ôóíêö³ÿ Îéëåðà fi(n) = (p-1)(q-1)

	void MakeKeyPair(cpp_int);
	cpp_int Encrypt(cpp_int msg);
	cpp_int Decrypt(cpp_int cp);
	std::pair<cpp_int, cpp_int> Sign(cpp_int);
	bool Verify(cpp_int, cpp_int);

private:
	cpp_int p; // simple num 256
	cpp_int q; // simple num 256
	cpp_int d; // Secret key. Inverse for e to mod(fi(n))
	cpp_int fi; //Eiler func

	bool MillerRabin(cpp_int p);
	bool TrialDivision(cpp_int p);
	cpp_int powmod(cpp_int a, cpp_int k, cpp_int n);
	cpp_int Gcd(cpp_int a, cpp_int b);
	cpp_int Gcd(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y);
	cpp_int BackElement(cpp_int a, cpp_int m);
	cpp_int pow(cpp_int, cpp_int);
};