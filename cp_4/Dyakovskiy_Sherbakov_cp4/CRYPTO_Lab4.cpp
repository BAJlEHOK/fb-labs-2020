#include "Methods.h"


//A(e, n, d) to B(e1, n1)
std::pair<cpp_int, cpp_int> SendKey(KeyGen& A, KeyGen& B, cpp_int k)
{
	cpp_int S = A.Sign(k).second; //S = k^d mod n
	cpp_int k1 = B.Encrypt(k); //k1 = k^e1 mod n1
	cpp_int S1 = B.Encrypt(S); // S1 = S^e1 mod n1
	std::pair<cpp_int, cpp_int> msg = make_pair(k1, S1);

	return msg;
}
// B to A
void ReceiveKey(KeyGen& A, KeyGen& B, std::pair<cpp_int, cpp_int> msg)
{
	std::cout << "B.e = " << B.e << std::endl;
	std::cout << std::hex << "B.n = " << B.n << std::endl;
	cpp_int k = A.Decrypt(msg.first); //k = k1^d1 mod n1
	cpp_int S = A.Decrypt(msg.second); //S = S1^d1 mod n1
	std::cout << std::hex << " ReceiveKey: k = " << k << std::endl;
	if (B.Verify(k, S)) // k = S^e mod n
	{
		std::cout << "The Connection between A and B is established!" << std::endl;
	}
	else
	{
		std::cout << "Connection failed!" << std::endl;
	}

}

//If А to В: B.n > A.n і навпаки
void GenerateKeyPair(KeyGen& A, KeyGen& B)
{
	//Random gen А and В
	/*
	A.MakeKeyPair();
	B.MakeKeyPair();
	while (true)
	{
		if (B.n >= A.n)
		{
			break;
		}
		A.MakeKeyPair();
	}*/

	A.MakeKeyPair(256);

	while (true)
	{
		if (B.n >= A.n)
		{
			break;
		}
		A.MakeKeyPair(256);
	}
	std::cout << std::hex << "A.n = " << A.n << "\n A.e = " << A.e << std::endl;
	std::cout << std::hex << "B.n = " << B.n << "\n B.e = " << B.e << std::endl;
}

void Test(KeyGen& A, KeyGen& B)
{
	//Random gen А and В
	
	A.MakeKeyPair(256);
	B.MakeKeyPair(256);
	while (true)
	{
		if (B.n >= A.n)
		{
			break;
		}
		A.MakeKeyPair(256);
	}

	ReceiveKey(B, A, SendKey(A, B, 0x1337));

}

int main()
{
	KeyGen A, B;
	
	//Test program
	Test(A, B);

	//Test Encryption
	/*A.MakeKeyPair();
	std::cout << std::hex << "A.n = " << A.n << "\n A.e = " << A.e << std::endl;
	cpp_int cp;
	std::cout << "Enter CP:\n >>> ";
	std::cin >> std::hex >> cp;
	std::cout << "Decrypt msg:" << A.Decrypt(cp) << std::endl;*/

	//Test Decryption
	/*std::ifstream server_n;
	server_n.open("Server_n.txt");
	server_n >> std::hex >> B.n;
	B.e = 0x10001;
	std::cout << std::hex << "Encrypt msg:" << B.Encrypt(0x1337) << std::endl;*/

	//Test Send Key	
	/*std::ifstream server_n;
	server_n.open("Server_n.txt");
	server_n >> std::hex >> B.n;
	B.e = 0x10001;
	GenerateKeyPair(A, B);
	cpp_int k, S;
	std::cout << "Enter k:\n >>> ";
	std::cin >> std::hex >> k;
	std::cout << "Enter S:\n >>> ";
	std::cin >> std::hex >> S;
	ReceiveKey(A, B, make_pair(k, S));*/

	//Test Recive Key
	/*std::ifstream server_n;
	server_n.open("Server_n.txt");
	server_n >> std::hex >> B.n;
	B.e = 0x10001;
	GenerateKeyPair(A, B);
	std::pair<cpp_int, cpp_int> msg = SendKey(A, B, 0x1337);
	std::cout << std::hex << "k =  " << msg.first << "\n S = " << msg.second << std::endl;*/

	
	return 0;
}