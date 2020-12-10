
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <random>


//using namespace boost::multiprecision;
using boost::multiprecision::cpp_int;
using namespace boost::random;
typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;
generator_type gen256(static_cast<unsigned int>(std::time(0)));

class KeyGen
{
public:
	cpp_int n; // відкритий n = p*q
	cpp_int e; // відкритий e = 2^16 + 1;  2 <= e <= fi(n)-1, fi -- функція Ойлера fi(n) = (p-1)(q-1)

	void MakeKeyPair();
	cpp_int Encrypt(cpp_int msg);
	cpp_int Decrypt(cpp_int cp);
	std::vector<cpp_int> Sign(cpp_int);
	int Verify(std::vector<cpp_int>);
	void SendKey();
	void ReceiveKey();

private:
	cpp_int p; // Простое число 256
	cpp_int q; // Простое число 256
	cpp_int d; // Секретний ключ. Обернений за для e за mod(fi(n))
	cpp_int fi; //Функция Ойлера

	bool MillerRabin(cpp_int p);
	bool TrialDivision(cpp_int p);
	cpp_int powmod(cpp_int a, cpp_int k, cpp_int n);
	cpp_int Gcd(cpp_int a, cpp_int b);
	cpp_int Gcd(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y);
	cpp_int Eiler(cpp_int n);
	cpp_int BackElement(cpp_int a, cpp_int m);
};