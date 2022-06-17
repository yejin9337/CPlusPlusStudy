#include <iostream>
#include <vector>
using namespace std; // 벡터가 std라는 이름공간 사용

int main()
{
	// 벡터 생성하기
	vector<int> vec;
	cout << boolalpha << vec.empty() << endl;
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	// 읽기 / 검색 / 삽입 / 삭제
	// 삽입
	// insert / push_back

	vec.push_back(3);                                                                             
	vec.push_back(4);
	vec.push_back(2);
	// {3 , 4 , 2}

	// 반복자
	// begin() : 컨테이너의 첫 원소를 가리키는 반복자
	// end() : 컨테이너의 마지막 원소의 다음을 가리키는 반복자
	// rbegin() : 컨테이너의 마지막 원소를 가리키는 반복자
	// rend() : 컨테이너의 첫 원소의 이전을 가리키는 반복자


	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) //iter는 되도록 전위 증가연산자 쓰기
	{
		cout << *iter << ",";
	}
	cout << endl;
	// end()가 실시간으로 달라 질 수 있어서 그냥 호출해서 사용한다 (뭔말인지 나도 모름)

	for (vector<int>::reverse_iterator iter = vec.rbegin(); iter!=vec.rend(); ++iter) // 애초에 설계가 역방향으로 되어있음
	{
		cout << *iter << ",";
	}
	cout << endl;


	// insert : pos 이전의 데이터를 삽입한다
	vector<int>::iterator iter = vec.begin();
	++iter;

	iter = vec.insert(iter, 10); // { 3 , 10 , 4 , 2 }, iter : &vec[1] (10)
	vec.insert(iter, 3, 5); //{ 3, 5 , 5 , 5 , 10 , 4 , 2 }, iter : &vec[1] (5)
	vec.insert(iter, vec.begin() + 3, vec.end() - 1); //{3 5 10 4 5 5 5 10 4 2} , iter : &vec[1] (5)

	//삭제
	// pop_back : 맨 끝에 있는 데이터를 삭제
	// vec : {3 5 10 4 5 5 5 10 4 2}
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	// {3 5 10 4 5 5 5 }

	// erase : pos에 있는 데이터를 삭제
	vec.erase(vec.begin()); // {5 10 4 5 5 5 }
	vec.erase(vec.begin() + 1, vec.begin() + 3); // {5 5 5 5 }

	//읽기
	cout << vec.front() << endl; // 맨 앞의 5
	cout << vec.back() << endl; // 맨 뒤의 5
	cout << vec[2] << endl; //두번째 5

	//찾기(검색) -> 메소드가 아니라 알고리즘 라이브러리에 존재

	//다른 생성
	vector<int> vec2(5); //{0 0 0 0 0}
	vector<int> vec2(10); //{10 10 10 10 10}



	return 0;
}












/* 포인터 주소값을 값으로가지는 데이터 타입

&a <- 어떤 변수의 메모리 주소
이 주소 값을 담을수 있는 데이터 타입이 포인터다

매개변수는 매개변수로 들어온 값이 중괄호 안에서 선언된다 -> 외부에 영향을 못준다
매개변수가 포인터로 들어올 경우 역참조를 통해 값을 바꿔주면 메모리의 값이 바뀌기 때문에
함수 내부에서 값을 바꾸는게 가능해진다


템플릿은 데이터 타입에서 자유로워지고 싶은것
내가 만드는 클래스, 내가 만드는 함수에서 다양한 데이터 타입을 처리할 수 있게 하고싶다
같은 연산이더라도 데이터 타입이 다르면 함수 여러개를 만들어야한다
그래서 템플릿이 나옴
T sum (T a, T b)
{
	return a+b;
}


목요일 레벨 테스트
금요일 학습 노트



*/