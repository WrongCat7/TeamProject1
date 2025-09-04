#include <iostream>
#include <string>
using namespace std;

int main()
{
	//캐릭터 글자 수 제한
	const size_t maxnamelength = 10;
	string charactername;

	cout << "캐릭터 이름을 입력하세요 (최대 " << maxnamelength << "자): ";
	getline(cin, charactername);

	if (charactername.length() > maxnamelength)
	{
		cout << "이름이 너무 깁니다." << maxnamelength << "자 이하로 입력해주세요. \n";
	}
	else
		cout << "입력된 이름 : " << charactername << '\n';

	return 0;
}