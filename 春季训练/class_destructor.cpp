/**
 * PROG: class destructor
 */
#include <cstdio>

class Base
{
public:
	Base();
	~Base();
	virtual void TestFun();
};

class MyClass : public Base
{
public:
	MyClass();
	~MyClass();
	virtual void TestFun();

protected:
	char* m_pStr;
};

Base::Base()
{
    printf("Base::Base()\n");
}

Base::~Base()
{
    /*
    if (m_pStr != NULL)
    {
        delete m_pStr;
    }
    */
    printf("Base::~Base()\n");
}

void Base::TestFun()
{
    printf("Base::TestFun()\n");
}

MyClass::MyClass()
{
    m_pStr = NULL;
    printf("MyClass::MyClass()\n");
}

MyClass::~MyClass()
{
    if (NULL != m_pStr)
    {
        delete m_pStr;
    }
    printf("MyClass::~MyClass()\n");
}

void MyClass::TestFun()
{
    m_pStr = new char[100];
    printf("MyClass::TestFun()\n");
}

void fun()
{
    Base* pClass = new MyClass();
	pClass->TestFun();
	delete pClass;

	printf("*** delete pClass ***\n");
}

/////////////////////////////
// Test.cpp
int main(void)
{
    fun();
	return 0;
}
