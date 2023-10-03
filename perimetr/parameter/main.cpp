//��� ���� �������� ������� ����� Figure (�������������� ������) � 
// �������������� �� ���� ������ Triangle (�����������) � 
// Rectangle (�������������).
//
//����� Triangle ������ ����� �����������, 
// ����������� �� ���� ��� ����� ���� int �
// ������� ������������. ��������, ��� ����������� � ������ ��������� ������ 
// ����������.
//
//����� Rectangle ������ ����� �����������, 
// ����������� �� ���� ��� ����� ���� int � ������� ��������������.
//
//����� Figure ������ �������� 
// ����������� ������� int Perimeter() const, 
// ������������ �������� ������.
//
//������-���������� ������ �������������� ��� ������� ���������� �������.
//
//������� main ������ � ����� ���� �� ����: 
// ��� ����� � ����� ����������� ���������. ���� ��������� �������� ���: 

#include "figures.h"
 
#include <vector>
// #include <iostream>
 
int main() {
    using namespace figures;
    figure** pps=new figure*[2];
    int l_pps = 0, l_max_pps = 2;
 
    std::string type;
 
    while (std::cin >> type) {
        if (type == "triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            triangle* pt = new triangle(a, b, c);
            if (l_pps >= l_max_pps) expand_figures_array(pps, l_pps, l_max_pps);
            pps[l_pps++] = pt;
        } else if (type == "rectangle") {
            int a, b;
            std::cin >> a >> b;
            rectangle* pr = new rectangle(a, b);
            if (l_pps >= l_max_pps) expand_figures_array(pps, l_pps, l_max_pps);
            pps[l_pps++] = pr;
        }
    }
 
    for (int i = 0; i < l_pps; ++i) {
        pps[i]->o_print_it();
        std::cout << pps[i]->o_perimetr() << std::endl;
    }
 
    for (int i = 0; i < l_pps; ++i) 
        delete[] pps[i];
    delete[] pps;
    return 0;
}

