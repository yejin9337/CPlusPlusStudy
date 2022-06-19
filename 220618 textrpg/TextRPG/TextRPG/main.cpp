#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU
{
	MAIN_NULL,
	MAP,
	STORE,
	INVENTORY,
	EXIT
};

enum MAP_MODE
{
	MAP_MODE_NULL,
	MAP_MODE_EASY,
	MAP_MODE_NOMAL,
	MAP_MODE_HARD,
	MAP_MODE_BACK
};

enum JOB
{
	JOB_NULL,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_MAGICIAN,
	JOB_END
};

enum ITEM_TYPE
{
	ITEM_NULL,
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_BACK
};

enum BATTLE
{
	BATTLE_NULL,
	BATTLE_ATTACK,
	BATTLE_BACK
};

struct _tagItem
{
	char Name[10];
	char typeName[10];
	ITEM_TYPE type;
	int Min;
	int Max;
	int Price;
	int Sell;
};
struct _tagInventory
{
	_tagItem item[20];
	int gold;
};

struct _tagPlayer
{
	char Name[10];
	char JobName[10];
	JOB pjob;
	int AttackMin;
	int AttackMax;
	int ArmorMin;
	int ArmorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int Exp;
	int Level;
	_tagInventory Inventory;
};

struct _tagMonster
{
	char Name[10];
	int AttackMin;
	int AttackMax;
	int ArmorMin;
	int ArmorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int Level;
	int DropExp;
	int DropGold;
};

int main()
{

	srand(time(NULL));

	// ������ ������ �� �÷��̾� ������ �����Ѵ�
	_tagPlayer player = {}; //�÷��̾� ���� ���� �ʱ�ȭ
	cout << "�г����� �Է��ϼ��� : ";
	cin >> player.Name;

	int jobInput = JOB_NULL;

	while (jobInput == JOB_NULL)
	{
		system("cls");
		cout << "������ �����ϼ���\n";
		cout << "1.���" << endl;
		cout << "2.�ü�" << endl;
		cout << "3.������" << endl;
		cout << "�Է� : ";
		cin >> jobInput;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		//else if (jobInput <= JOB_NULL || jobInput >= JOB_END)
		//{
		//	jobInput = JOB_NULL;
		//}
	}

	player.Level = 1;
	player.Exp = 0;
	player.pjob = (JOB)jobInput;
	player.Inventory.gold = 10000;

	switch (player.pjob)
	{
	case JOB_KNIGHT:
		strcpy_s(player.JobName, "���");
		player.AttackMin = 5;
		player.AttackMax = 10;
		player.ArmorMin = 10;
		player.ArmorMax = 20;
		player.HP = 500;
		player.HPMax = 500;
		player.MP = 100;
		player.MPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(player.JobName, "�ü�");
		player.AttackMin = 10;
		player.AttackMax = 15;
		player.ArmorMin = 10;
		player.ArmorMax = 15;
		player.HP = 400;
		player.HPMax = 400;
		player.MP = 200;
		player.MPMax = 200;
		break;
	case JOB_MAGICIAN:
		strcpy_s(player.JobName, "������");
		player.AttackMin = 15;
		player.AttackMax = 20;
		player.ArmorMin = 5;
		player.ArmorMax = 10;
		player.HP = 300;
		player.HPMax = 300;
		player.MP = 300;
		player.MPMax = 300;
		break;
	}

	// ���͸� �����Ѵ�
	_tagMonster mosterArr[MAP_MODE_BACK - 1] = {};

	// ��� ����
	strcpy_s(mosterArr[0].Name, "���");
	mosterArr[0].AttackMin = 20;
	mosterArr[0].AttackMax = 30;
	mosterArr[0].ArmorMin = 0;
	mosterArr[0].ArmorMax = 0;
	mosterArr[0].HP = 100;
	mosterArr[0].HPMax = 100;
	mosterArr[0].MP = 10;
	mosterArr[0].MPMax = 10;
	mosterArr[0].Level = 1;
	mosterArr[0].DropExp = 1000;
	mosterArr[0].DropGold = 100;

	// Ʈ�� ����
	strcpy_s(mosterArr[1].Name, "Ʈ��");
	mosterArr[1].AttackMin = 80;
	mosterArr[1].AttackMax = 100;
	mosterArr[1].ArmorMin = 50;
	mosterArr[1].ArmorMax = 100;
	mosterArr[1].HP = 1000;
	mosterArr[1].HPMax = 1000;
	mosterArr[1].MP = 100;
	mosterArr[1].MPMax = 100;
	mosterArr[1].Level = 5;
	mosterArr[1].DropExp = 7000;
	mosterArr[1].DropGold = 2000;

	// �巡�� ����
	strcpy_s(mosterArr[2].Name, "�巡��");
	mosterArr[2].AttackMin = 250;
	mosterArr[2].AttackMax = 500;
	mosterArr[2].ArmorMin = 200;
	mosterArr[2].ArmorMax = 400;
	mosterArr[2].HP = 10000;
	mosterArr[2].HPMax = 10000;
	mosterArr[2].MP = 20000;
	mosterArr[2].MPMax = 20000;
	mosterArr[2].Level = 20;
	mosterArr[2].DropExp = 30000;
	mosterArr[2].DropGold = 40000;


	while (true)
	{
		system("cls");
		printf("==================== MAIN ====================\n");
		cout << "1.��" << endl;
		cout << "2.����" << endl;
		cout << "3.�κ��丮" << endl;
		cout << "4.����" << endl;
		cout << "�Է�: ";

		int iMenu;
		cin >> iMenu;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == EXIT)
		{
			break;
		}

		switch (iMenu)
		{
		case MAP:
			while (true)
			{
				system("cls");
				printf("==================== MAP ====================\n");
				cout << "1.����" << endl;
				cout << "2.����" << endl;
				cout << "3.�����" << endl;
				cout << "4.�ڷΰ���" << endl;
				cout << "�Է�: ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (iMenu == MAP_MODE_BACK)
				{
					break;
				}

				//������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� ��ġ�Ѵ�
				_tagMonster monster = mosterArr[iMenu - 1];

				while (true)
				{
					system("cls");
					switch (iMenu)
					{
					case MAP_MODE_EASY:
						printf("==================== ���� ====================\n");
						break;

					}

					//�÷��̾� ������ ����Ѵ�
					printf("***** Player *****\n");
					cout << "�̸� : " << player.Name << "\t���� : " << player.JobName << endl;
					cout << "���� : " << player.Level << "\t����ġ : " << player.Exp << endl;
					cout << "���ݷ� : " << player.AttackMin << " ~ " << player.AttackMax << "\t���� : " << player.ArmorMin << " ~ " << player.ArmorMax;
					cout << "HP : " << player.HP << " / " << player.HPMax << "\tMP" << player.MP << " / " << player.MPMax << endl;
					cout << "���� ��� : " << player.Inventory.gold << " Gold\n";

					//���� ���� ���
					printf("***** Monster *****\n");
					cout << "�̸� : " << monster.Name << endl;
					cout << "���� : " << monster.Level << endl;
					cout << "���ݷ� : " << monster.AttackMin << " ~ " << monster.AttackMax << "\t���� : " << monster.ArmorMin << " ~ " << player.ArmorMax;
					cout << "HP : " << monster.HP << " / " << monster.HPMax << "\tMP" << monster.MP << " / " << monster.MPMax << endl;
					cout << "���� ��� : " << player.Inventory.gold << " Gold\n" << "\tȹ�����ġ : " << monster.DropExp << endl;

					//����
					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�Է�: ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024,'\n');
						continue;
					}
					else if (iMenu== BATTLE_BACK)
					{
						break;
					}

					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (player.AttackMax - player.AttackMin + 1) + player.AttackMin;
						int iArmor = rand() % (monster.ArmorMax - monster.ArmorMin + 1) + monster.ArmorMin;

						int iDamage = iAttack + iArmor;
						// if (iDamage < 1)
						// iDamage = 1;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// ���� HP�� ���ҽ�Ų��
						monster.HP -= iDamage;

						cout << player.Name << "��(��)" << monster.Name << "����" << iDamage << "�� ���ظ� �������ϴ�" << endl;

						// ���� ���
						if (monster.HP <= 0)
						{
							cout << monster.Name << "���Ͱ� ����Ͽ����ϴ�" << endl;
							player.Exp += monster.DropExp;
							player.Inventory.gold += monster.DropGold;
							cout << monster.DropExp << "����ġ�� ȹ���Ͽ����ϴ�" << endl;
							cout << monster.DropGold << "Gold�� ȹ���Ͽ����ϴ�" << endl;

							//�ʱ�ȭ
							monster.HP = monster.HPMax;
							monster.MP = monster.MPMax;
							system("pause");
							break;
						}

						//���� ����
						iAttack = rand() % (monster.AttackMax - monster.AttackMin + 1) + player.AttackMin;
						iArmor = rand() % (player.ArmorMax - player.ArmorMin + 1) + monster.ArmorMin;

						iDamage = iAttack + iArmor;
						// if (iDamage < 1)
						// iDamage = 1;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// �÷��̾��� HP�� ���ҽ�Ų��
						player.HP -= iDamage;

						cout << monster.Name << "��(��)" << player.Name << "����" << iDamage << "�� ���ظ� �������ϴ�" << endl;

						//�÷��̾� ���
						if (player.HP <= 0)
						{
							cout << player.Name << "��(��) ����Ͽ����ϴ�" << endl;

							int iExp = player.Exp * 0.1f;
							int iGold = player.Inventory.gold * 0.1f;

							cout << iExp << "�� ����ġ�� �Ҿ����ϴ�" << endl;
							cout << iGold << "�� Gold�� �Ҿ����ϴ�" << endl;

							player.HP = player.HPMax;
							player.MP = player.MPMax;
						}
						
						system("pause");
					}
						break;
					}

				}
			}
			break;
		case STORE:
			break;
		case INVENTORY:
			break;
		}

	}

	return 0;
}
			
