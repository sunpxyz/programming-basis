// ch15_object_oriented_programming
// oop_intro.cpp
// 2019/6/2


#include <iostream>
#include <sstream>
#include <memory>
#include <set>
#include <algorithm>


class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) {}
	std::pair<std::size_t, double> discount_policy() const {
		return {quantity, discount};
	}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};


class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
		Quote(book,p), min_qty(qty), discount(disc) {}
	double net_price(std::size_t) const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};


double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount) * price;
	} else {
		return cnt * price;
	}
}



double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n
	   << " total due: " << ret << std::endl;
	return ret;
}


int main()
{
	Quote item;
	Bulk_quote bulk;
	Quote *p = &item;
	p = &bulk;
	Quote &r = bulk;

	return 0;
}
