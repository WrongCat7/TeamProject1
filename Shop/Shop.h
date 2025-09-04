#include <string>
#include <vector>
using namespace std;

class Shop
{
private:
	string name;	//���� �̸�
	vector<Item> item;	//������ ����Ʈ, ���� ������ Ŭ������ ����
	int MaxItems;	//�������� �ִ� ���� ��
public:
	Shop(string N) : name(N) {}
	void BuyItem(string ItmeName, float Money);	//������ ����
	void PriceCheck(string ItemName);
	void ShowItems();	//��ǰ ��ü ��ϰ� ��� ����һ��̶� �Ű����� ����.
	void GetItemCount(string ItemName);
	void SellItem(string ItemName);	//������ �Ǹ�
};
