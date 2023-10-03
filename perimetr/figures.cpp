#include "figures.h"

namespace figures {
	void expand_figures_array(figure**& pps, int l,
		int* l_max, double coeff) {
		*l_max *= coeff;
		if (*l_max == l) *l_max *= 2;
		figure** p_new = new figure*[*l_max];
		for (int i = 0; i < l; ++i) *p_new[i] = *pps[i];
		delete[] pps;
		pps = p_new;
		return;
	}

	triangle::triangle()
		: a(-1), b(-1), c(-1) {}
	triangle::triangle(const int i, const int j, const int k)
		: a(i), b(j), c(k) {}
	int triangle::o_perimetr() const {
		if (a <= 0 || b <= 0 || c <= 0)
			return -1;
		return a + b + c;
	}
	rectangle::rectangle()
		: a(-1), b(-1) {}
	rectangle::rectangle(const int i, const int j)
		: a(i), b(j) {}
	int rectangle::o_perimetr() const {
		if (a <= 0 || b <= 0)
			return -1;
		return 2 * (a + b);
	}
	std::ostream& triangle::o_print_it() {
		std::cout << "a=" << a << "; b=" << b << "; c=" << c << std::endl;
		return std::cout;
	}
	std::ostream& rectangle::o_print_it() {
		std::cout << "a=" << a << "; b=" << b << std::endl;
		return std::cout;
	}
}