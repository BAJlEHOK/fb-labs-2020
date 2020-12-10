#include "Methods.h"
std::pair<cpp_int, cpp_int> Sign(cpp_int msg, KeyGen& A)
{
	std::cout << "Signing ..." << std::endl;
	cpp_int S = A.Encrypt(msg);
	std::pair<cpp_int, cpp_int> smsg = make_pair(msg, S);

	return smsg;
}

bool Verify(KeyGen &A, cpp_int k, cpp_int S)
{
	std::cout << "Verifying ..." << std::endl;
	if (k == A.Decrypt(S))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::pair<cpp_int, cpp_int> SendKey(KeyGen& A, KeyGen& B, cpp_int k)
{
	cpp_int S = Sign(k, A).second;
	cpp_int k1 = B.Decrypt(k);
	cpp_int S1 = B.Decrypt(S);
	
	std::pair<cpp_int, cpp_int> msg = make_pair(k1, S1);

	return msg;
}

void ReceiveKey(KeyGen& A, KeyGen& B, std::pair<cpp_int, cpp_int> msg)
{
	cpp_int k = B.Encrypt(msg.first);
	cpp_int S = B.Encrypt(msg.second);
	if (Verify(A, k, S))
	{
		std::cout << "The Connection between A and B is established!" << std::endl;
	}
	else
	{
		std::cout << "Connection failed!" << std::endl;
	}

}


int main()
{
	KeyGen A, B;
	A.MakeKeyPair();
	B.MakeKeyPair();
	while (true)
	{
		if (B.n >= A.n)
		{
			break;
		}
		A.MakeKeyPair();
	}

	ReceiveKey(A, B, SendKey(A, B, 1337));
	
	return 0;
}