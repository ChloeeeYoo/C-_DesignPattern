class Shape {};
class Rect   : public Shape {};
class Circle : public Shape {};

// 도형 편집기 예제를 생각해 보세요
// => 객체지향 스타일로 잘 만들었다면 

// #1. 도형편집기 예제에 새로운 도형(Triangle)을 추가하는 것은 
//     쉬운 작업 일까요 ? 어려운 작업 일까요 ?
// => 쉬운 작업

// #2. Shape에 Move 가상함수 추가하는 작업은 
//     쉬운 작업 일까요 ? 어려운 작업 일까요 ?
// => 어려운 작업


// 전통적인 디자인 패턴의 특징
// 요소(Element, Class)의 추가     : 쉬운 작업
// 연산(operation, 가상함수)의 추가 : 쉽지 않은 작업


// 하지만 메뉴 예제를 생각해 보세요

// 모든 메뉴에 어떤 작업을 하려고 합니다.
// BaseMenu 에 "가상함수" 를 추가해서 작업 : 어려운작업
// 해당 작업을 하는 "visitor" 를 만들고 root 에 넣기 : 쉬운작업

// some_work_visitor sv; //<= 모든 메뉴 객체에 어떤 작업을 하는 방문자
// root.accept(&sv);


// visitor 패턴의 특징
// 요소(Element, Class)의 추가     : 어렵다.
//								=> 메뉴(visitor4.cpp) 예제에, SpecialMenu 가 추가되면
//								=> IMenuVisitor 인터페이스가 수정되어야 한다.
//								=> 인터페이스를 변경하면 모든 방문자가 수정되어야 한다.
// 
// 연산(operation, 가상함수)의 추가 : 쉬운 작업
//								=> 가상함수로 추가하지 말고, 
//									해당 작업을 수행하는 방문자를 만들면 된다는것