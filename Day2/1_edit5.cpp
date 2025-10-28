// edit3.cpp
// => 변하는 것을 가상함수로 분리
// => template method 패턴
// => 상속 활용
// => 변경하고 싶다면 파생 클래스를 만들라는 의도..

// 특징 
// NumEdit : Edit 의 기능과 Validation 기능을 모두 소유. 
// => 다른 입력 도구에서 Validation 정책 사용할수 없다.
// => 실행시간에 Validation 정책 교체할수 없다.


// edit4.cpp
// => 변하는 것을 다른 클래스로 분리
// => strategy 패턴

// 특징 
// Edit 기능과 Validation 정책이 분리되어 있다.
// => 다른 입력도구에서도 Validation 정책 사용가능
// => 실행시간에 Validation 정책 교체가능

// Edit 예제
// => template method 보다 strategy 가 더 좋은 설계

// 도형 편집기 예제
// => 사각형을 그리는 정책은 다른 클래스에서 사용할 필요 없음.
// => 사각형을 그리는 정책은 실행시간에 변경되지 않음.
// => 사각형을 그리려면 멤버 데이타 접근 필요 - 즉, 멤버 함수가 좋다.

// => 따라서, strategy 보다는  template method 가 좋은 코드. 



