#include <iostream>

namespace figures {
	class figure;
	class triangle;
	class rectangle;
	void expand_figures_array(figure**& pps, int l,
		int& l_max, double coeff = 1.7);
	class figure {
	public:
		virtual int o_perimetr() const = 0;
		virtual std::ostream& o_print_it()=0;
	};

	class triangle : public figure {
	private:
		int a, b, c;
	public:
		triangle();
		triangle(const int i, const int j, const int k);
		int o_perimetr() const override;
		std::ostream& o_print_it() override;
	};

	class rectangle : public figure {
	private:
		int a, b;
	public:
		rectangle();
		rectangle(const int i, const int j);
		int o_perimetr() const override;
		std::ostream& o_print_it() override;
	};
}