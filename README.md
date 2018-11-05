## main
main에서는 ` library YSC; `라는 코드를 통해서 library에 정의된 library()를 call하게 된다. 이 과제의 모든 동작은 library()함수 내부에서 처리해주게 된다.
## library
library는 다음과 같이 정의되어 있다.
```
private:
	vector<book> books;
	vector<undergraduate> undergraduates;
public:
	library();
	void set_books();
	void input();
	int set_data(string date, string resource_type, string resource_name, string operation, string member_type, string member_name);
	void output(int operation_num, int return_code);
	int day2int(string day);
	string int2day(int day);
```
- private
	- library에서는 book과 undergraduate를 vector로 가지고 있게 해서 books는 resource의 목록을 나타내고 undergraduates는 member의 목록을 저장한다.
- public
	- library
		- input을 받아 output을 내보내는 모든 동작이 이루어지는 함수이다.
	- set_books
		- 초기 resource를 받아준다.
	- set_data
		- 1줄씩 받은 input을 보고 비교를 통해서 return_code를 return해주고 날짜를 함께 나타내야하는 4, 5, 6, 7의 경우에는 날짜를 int로 변경해서 10을 곱해 return_code에 더해서 전달해준다.
	- output
		- output으로 내보내기 위한 목차를 받고 return_code를 받아 해당되는 output을 파일에 써준다.
		- return_code는 1의 자리만 확인하고 날짜 값은 10으로 나눈 나머지를 취해 출력해준다.
	- day2int
		- string으로 받은 날짜를 int 값으로 반환해준다.
	- int2day
		- int로 받은 날짜를 string으로 반환해준다.


## resource, member
resource와 member에서 필요한 변수들을 class로 만들어주고 이를 get하고 set하기 위한 함수들로 이루어져있다.
- resource
	- resource class가 있고 book이 resource를 상속받아 사용하게 된다. 이 과제에서는 type이 모두 book이기 때문에 book만 생성해주었다.
- member
	- member class가 있고 undergraduate가 member를 상속받아 사용하게 된다. 이 과제에서는 type이 모두 undergraduate이기 때문에 undergraduate만 생성해주었다.
	