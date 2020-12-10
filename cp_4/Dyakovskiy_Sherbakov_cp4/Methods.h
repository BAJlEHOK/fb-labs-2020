#pragma once
#include "Header.h"

void KeyGen::MakeKeyPair()
{
	cpp_int num = gen256();
	int count = 0;
	int k = 0;
	cpp_int p1, q1;
	while (k < 2)
	{
		if (MillerRabin(num))
		{
			//std::cout << num << std::endl;
			if (k == 0) 
			{ 
				p1 = num; 
				int i = 1;
				while (true)
				{
					if (MillerRabin(p1))
					{
						this->p = p1;
						break;
					}
					p1 = 2 * i * p1 + 1;
				}
				k++;
			}
			if (k == 1) 
			{ 
				q1 = gen256();
				int j = 1;
				while (true)
				{
					if (MillerRabin(q1))
					{
						this->q = q1;
						break;
					}
					q1 = 2 * j * q1 + 1;
				}
				break; 
			}
		}
		count++;
		num = gen256();
	}

	this->n = p * q;
	this->fi = (p - 1) * (q - 1);

	bool ch = false;
	while (!ch)
	{
		this->e = 2 + gen256() % (fi - 1);
		ch = (Gcd(e, fi) == 1);
	}
	this->d = BackElement(e, fi);
	/*std::cout << "###################################################################################" << std::endl;
	std::cout << "###########   My Keys!    #############" << std::endl;
	std::cout << "p: " << p << std::endl;
	std::cout << "q: " << q << std::endl;*/
	//std::cout << "n: " << n << std::endl;
	//std::cout << "fi: " << fi << std::endl;
	//std::cout << "e: " << e << std::endl;
	//std::cout << "d: " << d << std::endl;
}

cpp_int KeyGen::Encrypt(cpp_int msg)
{
	//std::cout << std::hex<< "Encrypt: msg " << msg << std::endl;
	std::cout << "Encrypting [" << msg << "] ..." << std::endl;
	cpp_int cp = powmod(msg, e, n); //C = M^e mod n
	std::cout << std::hex << "Ciphertext: " << cp << std::endl;
	return cp;
}

cpp_int KeyGen::Decrypt(cpp_int cp)
{
	std::cout << "Decrypting:" << cp << std::endl;
	cpp_int msg = powmod(cp, d, n); //M = C^d mod n
	std::cout << "Decrypt!\nres = :" << cp << std::endl;

	return msg;
}

cpp_int KeyGen::Gcd(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	cpp_int x1, y1;
	cpp_int d = Gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

cpp_int KeyGen::Gcd(cpp_int a, cpp_int b) //Большие числа
{
	return b ? Gcd(b, a % b) : a;
}

cpp_int KeyGen::BackElement(cpp_int a, cpp_int m)
{
	cpp_int x, y;
	cpp_int g = Gcd(a, m, x, y);
	if (g != 1)
	{
		return 0;
	}
	else {
		x = (x % m + m) % m;
		if (x < 0) { x += m; }
		return x;
	}
}

cpp_int KeyGen::Eiler(cpp_int n)
{
	cpp_int ans;
	ans = n;
	for (cpp_int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	if (n > 1) ans -= ans / n;

	return ans;
}

//Возведение в степень по модулю
cpp_int KeyGen::powmod(cpp_int a, cpp_int k, cpp_int n) //Большие числа
{
	cpp_int b = 1;
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

}

//Тест пробных дилителей
bool KeyGen::TrialDivision(cpp_int p)
{
	if (p % 2 == 0 || p % 3 == 0 || p % 5 == 0)
	{
		//std::cout << p << "\tFaild!" << std::endl;
		return false;
	}
	else
	{
		int a = 7, b = 11;
		while (b < 50)
		{
			if (p % a == 0 || p % b == 0)
			{
				//std::cout << p << "\tFaild!" << std::endl;
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

//Тест Миллера-Рабина
bool KeyGen::MillerRabin(cpp_int p) // Принимает большое число 
{
	if (TrialDivision(p))
	{
		//std::cout << "************************************************************************** " << std::endl;
		int k = 10;
		// Крок 0
		cpp_int d = p - 1; // Большое число 
		int s = 0;
		cpp_int x = 0;
		while (d % 2 == 0)
		{
			d /= 2;
			s++;
		}
		//Крок 1
		for (int count = 0; count < k; count++)
		{
			x = 2 + gen256() % (p - 2); //Большое случайное х из интервала 2 < x < p-2, независимое от ранее выбраных x
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
							//std::cout << p << "\tFaild!" << std::endl;
							return false; // р складене
						}
					}
					if (!check)
					{
						//std::cout << p << "\tFaild!" << std::endl;
						return false; //Якщо за k кроків не було знайденто сильно псевдопросте число, то р є складеним 
					}
				}
			}
			else
			{
				//std::cout << p << "\tFaild!" << std::endl;
				return false; // р -- складене число
			}
		}
		return true;
	}
	//std::cout << p << "\tFaild!" << std::endl;
	return false;
}