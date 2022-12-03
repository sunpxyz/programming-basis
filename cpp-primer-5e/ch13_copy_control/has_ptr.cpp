// ch13_copy_control
// has_ptr.cpp
// 2019/5/17

#include <iostream>
#include <algorithm>


class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i), use(p.use) { ++*use; }
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
	HasPtr& operator=(const HasPtr &);
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
	std::size_t *use;
};


HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--&use == 0) {
		delete ps;
		delete use;
	}

	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}


HasPtr::~HasPtr()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}


inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}


int main() {
	//
	return 0;
}
