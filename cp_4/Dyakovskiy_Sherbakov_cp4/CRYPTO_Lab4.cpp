#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <random>


using namespace boost::multiprecision;
using namespace boost::random;
typedef independent_bits_engine<mt19937, 256, uint256_t> generator_type;
generator_type gen256;


//Проверено на малых числах
int GetRandomNumber(int min, int max)
{
	std::random_device random_device; // Источник энтропии.
	std::mt19937 generator(random_device()); // Генератор случайных чисел.
	// (Здесь берется одно инициализирующее значение, можно брать больше)

	std::uniform_int_distribution<> distribution(min, max);

	int x = distribution(generator); // Случайное число.
	return x;
}

//Проверено на малых числах
uint256_t Gcd(uint256_t a, uint256_t b) //Большие числа
{
	return b ? Gcd(b, a % b) : a;
}

//Проверено на малых числах
uint256_t powmod(uint256_t a, uint256_t k, uint256_t n) //Большие числа
{
	uint256_t b = 1; 
	while (k) {
		if (k % 2 == 0) {
			k /= 2;
			a = (a * a) % n; 
		}
		else {
			k--;
			b = (b * a) % n; 
		}
	}
	return b;

	/*
	uint256_t res = 1;

	a = a % n;

	if (a == 0) return 0;

	while (k > 0)
	{
		// If y is odd, multiply x with result  
		if (k % 2 == 1)
		{
			res = (res * a) % n;
		}

		// y must be even now  
		a = (a * a) % n;
		k = k / 2;

	}
	return res % n;
	*/
}

//Проверено на малых числах
bool TrialDivision(uint256_t p)
{
	if (p % 2 == 0 || p % 3 == 0 || p % 5 == 0)
	{
		return false;
	}
	else 
	{
		int a = 7, b = 11;
		while (b < 50)
		{
			if(p % a == 0 || p % b == 0)
			{
				return false;
			}
			else
			{
				a += 6;
				b += 6;
			}
		}
	}
	return true;
}

//Вроде проверено для малых числел
bool MillerRabin(uint256_t p) // Принимает большое число 
{
	if (TrialDivision(p))
	{
		//std::cout << "************************************************************************** " << std::endl;
		int k = 10;
		// Крок 0
		uint256_t d = p - 1; // Большое число 
		int s = 0;
		uint256_t x = 0;
		while (d % 2 == 0)
		{
			d /= 2;
			s++;
		}
		//std::cout << d << " " << s << " " << p << std::endl;
		//Крок 1
		for(int count = 0; count < k; count++)
		{ 
				x = 2 + gen256() % (p - 2); //Большое случайное х из интервала 2 < x < p-2, независимое от ранее выбраных x
				//x = GetRandomNumber(1, 1000);
				if (Gcd(x, p) == 1)
				{
					//Крок 2
					x = powmod(x, d, p);
					if (x == 1 || x == p - 1)
					{
						continue; // р сильно псевдопросте
					}
					else
					{
						bool check = false;
						for (int r = 0; r < s - 1; r++) 
						{
							check = false;
							x = powmod(x, 2, p);
							if (x == p - 1)
							{ 
								check = true; //р сильно псевдопросте
								break;
							} 
							else if (x == 1)
							{
								//continue;
								return false; // р складене
							} 
						}
						if (!check)
						{
							return false; //Якщо за k кроків не було знайденто сильно псевдопросте число, то р є складеним 
						}
					}
				}
				else 
				{
					return false; // р -- складене число
				}
		}
		return true;
	}
	return false;
}

int main()
{
	/*
	uint256_t num = gen256();
	for (int i = 0; i < 50; i++)
		std::cout << gen256() << std::endl;
*/
	
	
	/*uint256_t num = gen256();
	int count = 0;
	while (true)
	{
		//uint256_t num = gen256();
		if (MillerRabin(num))
		{
			std::cout << num << std::endl;
			break;
		}
		count++;
		//std::cout << num << std::endl;
		std::cout << "Failed: " << count << std::endl;
		num = gen256();
	}*/


	uint256_t n = 18446744073709551557;
	
	//Тесты с простыми числами
	std::cout << MillerRabin(2383) << std::endl;
	std::cout << MillerRabin(2963) << std::endl;
	std::cout << MillerRabin(1277) << std::endl;
	std::cout << MillerRabin(1289) << std::endl;
	std::cout << MillerRabin(2441) << std::endl;
	std::cout << MillerRabin(1409) << std::endl;
	std::cout << MillerRabin(1459) << std::endl;
	std::cout << MillerRabin(2939) << std::endl;
	std::cout << MillerRabin(1787) << std::endl;
	std::cout << MillerRabin(103) << std::endl;
	std::cout << MillerRabin(2671) << std::endl;
	std::cout << MillerRabin(98764321261) << std::endl;
	std::cout << MillerRabin(n) << std::endl;
	std::cout << "Sostavnie: " << std::endl;
	std::cout << MillerRabin(3300) << std::endl;
	std::cout << MillerRabin(2382) << std::endl;
	std::cout << MillerRabin(2314) << std::endl;
	std::cout << MillerRabin(3362) << std::endl;
	std::cout << MillerRabin(2348) << std::endl; 
	
	return 0;
}