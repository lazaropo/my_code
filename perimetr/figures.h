namespace figures {
	class figure;
	void expand_figures_array(figure**& pps, int l,
		int* l_max, double coeff = 1.7);
	class figure {
	public:
		virtual int o_perimetr() const = 0;
	};

	class triangle : public figure {
	private:
		int a, b, c;
	public:
		triangle();
		triangle(const int i, const int j, const int k);
		int o_perimetr() const override;
	};

	class rectangle : public figure {
	private:
		int a, b;
	public:
		rectangle();
		rectangle(const int i, const int j);
		int o_perimetr() const override;
	};
}