#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int func(char ch)
{
	int r = -1;
	if (ch == 'А' || ch == 'а') r = 1;
	else if (ch == 'Б' || ch == 'б') r = 2;
	else if (ch == 'В' || ch == 'в') r = 3;
	else if (ch == 'Г' || ch == 'г') r = 4;
	else if (ch == 'Д' || ch == 'д') r = 5;
	else if (ch == 'Е' || ch == 'е') r = 6;
	else if (ch == 'Ё' || ch == 'ё') r = 7;
	else if (ch == 'Ж' || ch == 'ж') r = 8;
	else if (ch == 'З' || ch == 'з') r = 9;
	else if (ch == 'И' || ch == 'и') r = 10;
	else if (ch == 'Й' || ch == 'й') r = 11;
	else if (ch == 'К' || ch == 'к') r = 12;
	else if (ch == 'Л' || ch == 'л') r = 13;
	else if (ch == 'М' || ch == 'м') r = 14;
	else if (ch == 'Н' || ch == 'н') r = 15;
	else if (ch == 'О' || ch == 'о') r = 16;
	else if (ch == 'П' || ch == 'п') r = 17;
	else if (ch == 'Р' || ch == 'р') r = 18;
	else if (ch == 'С' || ch == 'с') r = 19;
	else if (ch == 'Т' || ch == 'т') r = 20;
	else if (ch == 'У' || ch == 'у') r = 21;
	else if (ch == 'Ф' || ch == 'ф') r = 22;
	else if (ch == 'Х' || ch == 'х') r = 23;
	else if (ch == 'Ц' || ch == 'ц') r = 24;
	else if (ch == 'Ч' || ch == 'ч') r = 25;
	else if (ch == 'Ш' || ch == 'ш') r = 26;
	else if (ch == 'Щ' || ch == 'щ') r = 27;
	else if (ch == 'Ъ' || ch == 'ъ') r = 28;
	else if (ch == 'Ы' || ch == 'Ы') r = 29;
	else if (ch == 'Ь' || ch == 'ь') r = 30;
	else if (ch == 'Э' || ch == 'э') r = 31;
	else if (ch == 'Ю' || ch == 'ю') r = 32;
	else if (ch == 'Я' || ch == 'я') r = 33;
	else if (ch == ' ') r = 34;
	return r;
}

char refunc(int n)
{
	switch (n)
	{
	case 1: return 'а';
		break;
	case 2: return 'б';
		break;
	case 3: return 'в';
		break;
	case 4: return 'г';
		break;
	case 5: return 'д';
		break;
	case 6: return 'е';
		break;
	case 7: return 'ё';
		break;
	case 8: return 'ж';
		break;
	case 9: return 'з';
		break;
	case 10: return 'и';
		break;
	case 11: return 'й';
		break;
	case 12: return 'к';
		break;
	case 13: return 'л';
		break;
	case 14: return 'м';
		break;
	case 15: return 'н';
		break;
	case 16: return 'о';
		break;
	case 17: return 'п';
		break;
	case 18: return 'р';
		break;
	case 19: return 'с';
		break;
	case 20: return 'т';
		break;
	case 21: return 'у';
		break;
	case 22: return 'ф';
		break;
	case 23: return 'х';
		break;
	case 24: return 'ц';
		break;
	case 25: return 'ч';
		break;
	case 26: return 'ш';
		break;
	case 27: return 'щ';
		break;
	case 28: return 'ъ';
		break;
	case 29: return 'ы';
		break;
	case 30: return 'ь';
		break;
	case 31: return 'э';
		break;
	case 32: return 'ю';
		break;
	case 33: return 'я';
		break;
	case 34: return '_';
		break;
	}
}

bool pred(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second > b.second;
}

void funcLetterFreqWoS(vector<char> text) {
	cout << "\tMonogram without space." << endl;
	int place = 0;

	map<char, int> mLetterArr = {
		{'а', 0},
		{'б', 0},
		{'в', 0},
		{'г', 0},
		{'д', 0},
		{'е', 0},
		{'ё', 0},
		{'ж', 0},
		{'з', 0},
		{'и', 0},
		{'й', 0},
		{'к', 0},
		{'л', 0},
		{'м', 0},
		{'н', 0},
		{'о', 0},
		{'п', 0},
		{'р', 0},
		{'с', 0},
		{'т', 0},
		{'у', 0},
		{'ф', 0},
		{'х', 0},
		{'ц', 0},
		{'ч', 0},
		{'ш', 0},
		{'щ', 0},
		{'ъ', 0},
		{'ы', 0},
		{'ь', 0},
		{'э', 0},
		{'ю', 0},
		{'я', 0}
	};

	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'а':
			mLetterArr.at('а')++;
			break;
		case 'б':
			mLetterArr.at('б')++;
			break;
		case 'в':
			mLetterArr.at('в')++;
			break;
		case 'г':
			mLetterArr.at('г')++;
			break;
		case 'д':
			mLetterArr.at('д')++;
			break;
		case 'е':
			mLetterArr.at('е')++;
			break;
		case 'ё':
			mLetterArr.at('ё')++;
			break;
		case 'ж':
			mLetterArr.at('ж')++;
			break;
		case 'з':
			mLetterArr.at('з')++;
			break;
		case 'и':
			mLetterArr.at('и')++;
			break;
		case 'й':
			mLetterArr.at('й')++;
			break;
		case 'к':
			mLetterArr.at('к')++;
			break;
		case 'л':
			mLetterArr.at('л')++;
			break;
		case 'м':
			mLetterArr.at('м')++;
			break;
		case 'н':
			mLetterArr.at('н')++;
			break;
		case 'о':
			mLetterArr.at('о')++;
			break;
		case 'п':
			mLetterArr.at('п')++;
			break;
		case 'р':
			mLetterArr.at('р')++;
			break;
		case 'с':
			mLetterArr.at('с')++;
			break;
		case 'т':
			mLetterArr.at('т')++;
			break;
		case 'у':
			mLetterArr.at('у')++;
			break;
		case 'ф':
			mLetterArr.at('ф')++;
			break;
		case 'х':
			mLetterArr.at('х')++;
			break;
		case 'ц':
			mLetterArr.at('ц')++;
			break;
		case 'ч':
			mLetterArr.at('ч')++;
			break;
		case 'ш':
			mLetterArr.at('ш')++;
			break;
		case 'щ':
			mLetterArr.at('щ')++;
			break;
		case 'ъ':
			mLetterArr.at('ъ')++;
			break;
		case 'ы':
			mLetterArr.at('ы')++;
			break;
		case 'ь':
			mLetterArr.at('ь')++;
			break;
		case 'э':
			mLetterArr.at('э')++;
			break;
		case 'ю':
			mLetterArr.at('ю')++;
			break;
		case 'я':
			mLetterArr.at('я')++;
			break;
		}

	}

	vector<pair<char, int>> vTempArr(mLetterArr.begin(), mLetterArr.end());
	sort(vTempArr.begin(), vTempArr.end(), pred);

	int iAmountLetters = 0;
	for (auto p : vTempArr) {
		iAmountLetters += p.second;
	}

	cout.setf(ios::fixed);
	cout.precision(4);

	double dTempSum = 0;
	for (auto p : vTempArr) {

		float temp = (float)p.second / (float)iAmountLetters;
		//cout << " (" << temp << ")" << p.first << " : " << p.second << endl;
		cout << p.first << " : " << temp << endl;

		if (p.second != 0) {
			dTempSum += temp * (log(temp) / log(2));
		}

	}

	cout << "H1(Ensemble entropy without space): " << (-1) * dTempSum << endl;

}

void funcLetterFreqWS(vector<char> text) {
	cout << "\tMonogram with space." << endl;
	int place = 0;

	map<char, int> mLetterArr = {
		{'а', 0},
		{'б', 0},
		{'в', 0},
		{'г', 0},
		{'д', 0},
		{'е', 0},
		{'ё', 0},
		{'ж', 0},
		{'з', 0},
		{'и', 0},
		{'й', 0},
		{'к', 0},
		{'л', 0},
		{'м', 0},
		{'н', 0},
		{'о', 0},
		{'п', 0},
		{'р', 0},
		{'с', 0},
		{'т', 0},
		{'у', 0},
		{'ф', 0},
		{'х', 0},
		{'ц', 0},
		{'ч', 0},
		{'ш', 0},
		{'щ', 0},
		{'ъ', 0},
		{'ы', 0},
		{'ь', 0},
		{'э', 0},
		{'ю', 0},
		{'я', 0},
		{'_', 0}
	};

	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'а':
			mLetterArr.at('а')++;
			break;
		case 'б':
			mLetterArr.at('б')++;
			break;
		case 'в':
			mLetterArr.at('в')++;
			break;
		case 'г':
			mLetterArr.at('г')++;
			break;
		case 'д':
			mLetterArr.at('д')++;
			break;
		case 'е':
			mLetterArr.at('е')++;
			break;
		case 'ё':
			mLetterArr.at('ё')++;
			break;
		case 'ж':
			mLetterArr.at('ж')++;
			break;
		case 'з':
			mLetterArr.at('з')++;
			break;
		case 'и':
			mLetterArr.at('и')++;
			break;
		case 'й':
			mLetterArr.at('й')++;
			break;
		case 'к':
			mLetterArr.at('к')++;
			break;
		case 'л':
			mLetterArr.at('л')++;
			break;
		case 'м':
			mLetterArr.at('м')++;
			break;
		case 'н':
			mLetterArr.at('н')++;
			break;
		case 'о':
			mLetterArr.at('о')++;
			break;
		case 'п':
			mLetterArr.at('п')++;
			break;
		case 'р':
			mLetterArr.at('р')++;
			break;
		case 'с':
			mLetterArr.at('с')++;
			break;
		case 'т':
			mLetterArr.at('т')++;
			break;
		case 'у':
			mLetterArr.at('у')++;
			break;
		case 'ф':
			mLetterArr.at('ф')++;
			break;
		case 'х':
			mLetterArr.at('х')++;
			break;
		case 'ц':
			mLetterArr.at('ц')++;
			break;
		case 'ч':
			mLetterArr.at('ч')++;
			break;
		case 'ш':
			mLetterArr.at('ш')++;
			break;
		case 'щ':
			mLetterArr.at('щ')++;
			break;
		case 'ъ':
			mLetterArr.at('ъ')++;
			break;
		case 'ы':
			mLetterArr.at('ы')++;
			break;
		case 'ь':
			mLetterArr.at('ь')++;
			break;
		case 'э':
			mLetterArr.at('э')++;
			break;
		case 'ю':
			mLetterArr.at('ю')++;
			break;
		case 'я':
			mLetterArr.at('я')++;
			break;
		case ' ':
			mLetterArr.at('_')++;
		default:
			break;
		}

	}

	vector<pair<char, int>> vTempArr(mLetterArr.begin(), mLetterArr.end());
	sort(vTempArr.begin(), vTempArr.end(), pred);

	int iAmountLetters = 0;
	for (auto p : vTempArr) {
		iAmountLetters += p.second;
	}


	cout.setf(ios::fixed);
	cout.precision(4);

	double dTempSum = 0;
	for (auto p : vTempArr) {

		float temp = (float)p.second / (float)iAmountLetters;
		//cout << " (" << temp << ")" << p.first << " : " << p.second << endl;

		cout << p.first << " : " << temp << endl;

		if (p.second != 0) {
			dTempSum += temp * (log(temp) / log(2));
		}

	}
	cout << "H1(Ensemble entropy with space): " << (-1) * dTempSum << endl;
}

void bigram_cross(vector<char> buff)
{
	int count = 0;
	int matrix[33][33] = { 0 };
	for (int i = 0; i < buff.size() - 1; i++)
	{
		if (buff[i] != ' ' && buff[i + 1] != ' ' && buff[i + 1] != '\0')
		{
			//cout << refunc(func(buff[i])) << "" << refunc(func(buff[i + 1])) << endl;
			matrix[func(buff[i + 1]) - 1][func(buff[i]) - 1]++;
			count++;
		}
	}
	//cout << "Count: " << count << endl;
	//cout << "\t";
	/*for (int i = 0; i < 33; i++)
	{
		cout << refunc(i + 1) << "  ";
	}*/

	cout << endl;
	float h = 0.0;
	for (int i = 0; i < 33; i++)
	{
		//cout << refunc(i + 1) << "\t";
		for (int j = 0; j < 33; j++)
		{
			cout.precision(10);
			if (matrix[i][j] != 0)
			{
				float temp = (float)matrix[i][j] / count;
				h += temp * log(temp) / log(2);

				cout << refunc(i + 1) << refunc(j + 1) << ": ";
				cout << (float)matrix[i][j] / count << endl;//"\t";
			}
			//cout << (float)matrix[i][j] / count << endl;//"\t";
		}
		//cout << endl;
	}
	cout.precision(20);
	cout << "H -- " << (long double)h * (-1) << endl;
	cout.precision(5);
}

void bigram_ncross(vector<char> buff)
{
	int count = 0;
	int matrix[33][33] = { 0 };
	for (int i = 0; i < buff.size() - 1; i++)
	{
		if (i % 2 != 0)
		{
			continue;
		}
		if (buff[i] != ' ' && buff[i + 1] != ' ' && buff[i + 1] != '\0')
		{
			//cout << refunc(func(buff[i])) << "" << refunc(func(buff[i + 1])) << endl;
			matrix[func(buff[i + 1]) - 1][func(buff[i]) - 1]++;
			count++;
		}
	}
	/*cout << "Count: " << count << endl;
	cout << "\t";
	for (int i = 0; i < 33; i++)
	{
		cout << refunc(i + 1) << "  ";
	}*/

	cout << endl;
	float h = 0.0;
	for (int i = 0; i < 33; i++)
	{
		//cout << refunc(i + 1) << "\t";
		for (int j = 0; j < 33; j++)
		{
			cout.precision(10);
			if (matrix[i][j] != 0)
			{
				float temp = (float)matrix[i][j] / count;
				h += temp * log(temp) / log(2);

				cout << refunc(i + 1) << refunc(j + 1) << ": ";
				cout << (float)matrix[i][j] / count << endl;//"\t";
			}
			//cout << (float)matrix[i][j] / count << "  ";
		}
		//cout << endl;
	}
	cout.precision(20);
	cout << "H -- " << h * (-1)<< endl;
	cout.precision(5);
}

void bigram_cross_space(vector<char> buff)
{
	int count = 0;
	int matrix[34][34] = { 0 };
	for (int i = 0; i < buff.size() - 1; i++)
	{
		if (buff[i + 1] != '\0')
		{
			//cout << refunc(func(buff[i])) << "" << refunc(func(buff[i + 1])) << endl;
			matrix[func(buff[i + 1]) - 1][func(buff[i]) - 1]++;
			count++;
		}
	}

	/*cout << "Count: " << count << endl;
	cout << "\t";
	for (int i = 0; i < 34; i++)
	{
		cout << refunc(i + 1) << "  ";
	}*/

	cout << endl;
	float h = 0.0;
	for (int i = 0; i < 34; i++)
	{
		//cout << refunc(i + 1) << "\t";
		for (int j = 0; j < 34; j++)
		{
			cout.precision(10);
			if (matrix[i][j] != 0)
			{
				float temp = (float)matrix[i][j] / count;
				h += temp * log(temp) / log(2);

				cout << refunc(i + 1) << refunc(j + 1) << ": ";
				cout << (float)matrix[i][j] / count << endl;//"\t";
			}
			//cout << (float)matrix[i][j] / count << "  ";
		}
		//cout << endl;
	}
	cout.precision(20);
	cout << "H -- " << h * (-1) << endl;
	cout.precision(5);
}

void bigram_ncross_space(vector<char> buff)
{
	int count = 0;
	int matrix[34][34] = { 0 };
	for (int i = 0; i < buff.size() - 1; i++)
	{
		if (i % 2 != 0)
		{
			continue;
		}
		if (buff[i + 1] != '\0')
		{
			//cout << refunc(func(buff[i])) << "" << refunc(func(buff[i + 1])) << endl;
			matrix[func(buff[i + 1]) - 1][func(buff[i]) - 1]++;
			count++;
		}
	}
	/*cout << "Count: " << count << endl;
	cout << "\t";
	for (int i = 0; i < 34; i++)
	{
		cout << refunc(i + 1) << "  ";
	}*/

	cout << endl;
	float h = 0.0;
	for (int i = 0; i < 34; i++)
	{
		//cout << refunc(i + 1) << "\t";
		for (int j = 0; j < 34; j++)
		{
			cout.precision(10);
			if (matrix[i][j] != 0)
			{
				float temp = (float)matrix[i][j] / count;
				h += temp * log(temp) / log(2);

				cout << refunc(i + 1) << refunc(j + 1) << ": ";
				cout << (float)matrix[i][j] / count << endl;//"\t";
			}
			//cout << (float)matrix[i][j] / count << "  ";
		}
		//cout << endl;
	}
	cout.precision(20);
	cout << "H -- " << h * (-1)<< endl;
	cout.precision(5);
}

int main() {
	setlocale(0, "Rus");
	cout << "Created by Sherbakov Oleg, Kirill Dyakovskiy." << endl << endl;


	ifstream fMainFile;
	fMainFile.open("text.txt");

	if (!fMainFile.is_open()) {
		cout << "File didn't open." << endl;
		fMainFile.close();
		return 1;
	}

	vector<char> vMessageArr;
	int sizeMess = -1;
	char cTempLetter;


	do {
		cTempLetter = fMainFile.get();
		sizeMess++;
		switch (cTempLetter) {
		case 'А':
			vMessageArr.push_back('а');
			break;
		case 'Б':
			vMessageArr.push_back('б');
			break;
		case 'В':
			vMessageArr.push_back('в');
			break;
		case 'Г':
			vMessageArr.push_back('г');
			break;
		case 'Д':
			vMessageArr.push_back('д');
			break;
		case 'Е':
			vMessageArr.push_back('е');
			break;
		case 'Ё':
			vMessageArr.push_back('ё');
			break;
		case 'Ж':
			vMessageArr.push_back('ж');
			break;
		case 'З':
			vMessageArr.push_back('з');
			break;
		case 'И':
			vMessageArr.push_back('и');
			break;
		case 'Й':
			vMessageArr.push_back('й');
			break;
		case 'К':
			vMessageArr.push_back('к');
			break;
		case 'Л':
			vMessageArr.push_back('л');
			break;
		case 'М':
			vMessageArr.push_back('м');
			break;
		case 'Н':
			vMessageArr.push_back('н');
			break;
		case 'О':
			vMessageArr.push_back('о');
			break;
		case 'П':
			vMessageArr.push_back('п');
			break;
		case 'Р':
			vMessageArr.push_back('р');
			break;
		case 'С':
			vMessageArr.push_back('с');
			break;
		case 'Т':
			vMessageArr.push_back('т');
			break;
		case 'У':
			vMessageArr.push_back('у');
			break;
		case 'Ф':
			vMessageArr.push_back('ф');
			break;
		case 'Х':
			vMessageArr.push_back('х');
			break;
		case 'Ц':
			vMessageArr.push_back('ц');
			break;
		case 'Ч':
			vMessageArr.push_back('ч');
			break;
		case 'Ш':
			vMessageArr.push_back('ш');
			break;
		case 'Щ':
			vMessageArr.push_back('щ');
			break;
		case 'Ъ':
			vMessageArr.push_back('ъ');
			break;
		case 'Ы':
			vMessageArr.push_back('ы');
			break;
		case 'Ь':
			vMessageArr.push_back('ь');
			break;
		case 'Э':
			vMessageArr.push_back('э');
			break;
		case 'Ю':
			vMessageArr.push_back('ю');
			break;
		case 'Я':
			vMessageArr.push_back('я');
			break;
		case ' ':
			if ((cTempLetter == ' ' && vMessageArr.size() == 0) || (cTempLetter == ' ' && vMessageArr.back() != ' '))
				vMessageArr.push_back(cTempLetter);
			break;
		case 'а':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'б':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'в':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'г':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'д':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'е':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ё':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ж':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'з':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'и':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'й':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'к':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'л':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'м':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'н':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'о':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'п':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'р':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'с':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'т':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'у':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ф':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'х':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ц':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ч':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ш':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'щ':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ъ':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ы':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ь':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'э':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'ю':
			vMessageArr.push_back(cTempLetter);
			break;
		case 'я':
			vMessageArr.push_back(cTempLetter);
			break;
		default:
			break;
		}

	} while (!fMainFile.eof());
	vMessageArr.pop_back();


	/*for (int i = 0; i < vMessageArr.size(); i++) {
			cout << vMessageArr[i];
	}*/

	funcLetterFreqWoS(vMessageArr);
	cout << endl << endl;
	funcLetterFreqWS(vMessageArr);
	cout << endl << endl;

	bigram_cross(vMessageArr);
	cout << endl << endl;
	bigram_ncross(vMessageArr);
	cout << endl << endl;
	bigram_cross_space(vMessageArr);
	cout << endl << endl;
	bigram_ncross_space(vMessageArr);
	cout << endl << endl;

	system("pause");
	return 0;
}
