#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ĳ���� ���� �� ����
	const size_t maxnamelength = 10;
	string charactername;

	cout << "ĳ���� �̸��� �Է��ϼ��� (�ִ� " << maxnamelength << "��): ";
	getline(cin, charactername);

	if (charactername.length() > maxnamelength)
	{
		cout << "�̸��� �ʹ� ��ϴ�." << maxnamelength << "�� ���Ϸ� �Է����ּ���. \n";
	}
	else
		cout << "�Էµ� �̸� : " << charactername << '\n';

	return 0;
}