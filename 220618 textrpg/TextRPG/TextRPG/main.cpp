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

	// 게임을 시작할 때 플레이어 정보를 설정한다
	_tagPlayer player = {}; //플레이어 값들 전부 초기화
	cout << "닉네임을 입력하세요 : ";
	cin >> player.Name;

	int jobInput = JOB_NULL;

	while (jobInput == JOB_NULL)
	{
		system("cls");
		cout << "직업을 선택하세요\n";
		cout << "1.기사" << endl;
		cout << "2.궁수" << endl;
		cout << "3.마법사" << endl;
		cout << "입력 : ";
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
		strcpy_s(player.JobName, "기사");
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
		strcpy_s(player.JobName, "궁수");
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
		strcpy_s(player.JobName, "마법사");
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

	// 몬스터를 생성한다
	_tagMonster mosterArr[MAP_MODE_BACK - 1] = {};

	// 고블린 생성
	strcpy_s(mosterArr[0].Name, "고블린");
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

	// 트롤 생성
	strcpy_s(mosterArr[1].Name, "트롤");
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

	// 드래곤 생성
	strcpy_s(mosterArr[2].Name, "드래곤");
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
		cout << "1.맵" << endl;
		cout << "2.상점" << endl;
		cout << "3.인벤토리" << endl;
		cout << "4.종료" << endl;
		cout << "입력: ";

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
				cout << "1.쉬움" << endl;
				cout << "2.보통" << endl;
				cout << "3.어려움" << endl;
				cout << "4.뒤로가기" << endl;
				cout << "입력: ";
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

				//선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스와 일치한다
				_tagMonster monster = mosterArr[iMenu - 1];

				while (true)
				{
					system("cls");
					switch (iMenu)
					{
					case MAP_MODE_EASY:
						printf("==================== 쉬움 ====================\n");
						break;

					}

					//플레이어 정보를 출력한다
					printf("***** Player *****\n");
					cout << "이름 : " << player.Name << "\t직업 : " << player.JobName << endl;
					cout << "레벨 : " << player.Level << "\t경험치 : " << player.Exp << endl;
					cout << "공격력 : " << player.AttackMin << " ~ " << player.AttackMax << "\t방어력 : " << player.ArmorMin << " ~ " << player.ArmorMax;
					cout << "HP : " << player.HP << " / " << player.HPMax << "\tMP" << player.MP << " / " << player.MPMax << endl;
					cout << "보유 골드 : " << player.Inventory.gold << " Gold\n";

					//몬스터 정보 출력
					printf("***** Monster *****\n");
					cout << "이름 : " << monster.Name << endl;
					cout << "레벨 : " << monster.Level << endl;
					cout << "공격력 : " << monster.AttackMin << " ~ " << monster.AttackMax << "\t방어력 : " << monster.ArmorMin << " ~ " << player.ArmorMax;
					cout << "HP : " << monster.HP << " / " << monster.HPMax << "\tMP" << monster.MP << " / " << monster.MPMax << endl;
					cout << "보유 골드 : " << player.Inventory.gold << " Gold\n" << "\t획득경험치 : " << monster.DropExp << endl;

					//전투
					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "입력: ";
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

						// 몬스터 HP를 감소시킨다
						monster.HP -= iDamage;

						cout << player.Name << "이(가)" << monster.Name << "에게" << iDamage << "의 피해를 입혔습니다" << endl;

						// 몬스터 사망
						if (monster.HP <= 0)
						{
							cout << monster.Name << "몬스터가 사망하였습니다" << endl;
							player.Exp += monster.DropExp;
							player.Inventory.gold += monster.DropGold;
							cout << monster.DropExp << "경험치를 획득하였습니다" << endl;
							cout << monster.DropGold << "Gold를 획득하였습니다" << endl;

							//초기화
							monster.HP = monster.HPMax;
							monster.MP = monster.MPMax;
							system("pause");
							break;
						}

						//몬스터 공격
						iAttack = rand() % (monster.AttackMax - monster.AttackMin + 1) + player.AttackMin;
						iArmor = rand() % (player.ArmorMax - player.ArmorMin + 1) + monster.ArmorMin;

						iDamage = iAttack + iArmor;
						// if (iDamage < 1)
						// iDamage = 1;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다
						player.HP -= iDamage;

						cout << monster.Name << "이(가)" << player.Name << "에게" << iDamage << "의 피해를 입혔습니다" << endl;

						//플레이어 사망
						if (player.HP <= 0)
						{
							cout << player.Name << "이(가) 사망하였습니다" << endl;

							int iExp = player.Exp * 0.1f;
							int iGold = player.Inventory.gold * 0.1f;

							cout << iExp << "의 경험치를 잃었습니다" << endl;
							cout << iGold << "의 Gold를 잃었습니다" << endl;

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
			
