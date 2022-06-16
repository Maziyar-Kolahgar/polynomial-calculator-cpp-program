#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
class Term // cx^p
{
private:
    float coefficient, x;
    int power;

public:
    Term(float c, int p) : coefficient(c), power(p) {}
    Term(float c) : coefficient(c), power(0) {}
    Term() : power(0), coefficient(0) {}
    Term(string);
    inline float get_coefficient() { return coefficient; }
    inline int get_powr() { return power; }
    inline void set_coefficient(float c) { coefficient = c; }
    inline void set_power(int p) { power = p; };
    string get_whole_Term();
    friend Term operator+(const Term &, const Term &);
    friend Term operator-(const Term &, const Term &);
    friend Term operator*(const Term &, const Term &);
    friend Term operator/(const Term &, const Term &);
    void operator+=(const Term &);
    void operator-=(const Term &);
    void operator*=(const Term &);
    void operator/=(const Term &);
    void operator=(const Term &);
    friend bool operator>(const Term &, const Term &);
    friend bool operator<(const Term &, const Term &);
    friend bool operator>=(const Term &, const Term &);
    friend bool operator<=(const Term &, const Term &);
    friend bool operator==(const Term &, const Term &);
    friend bool operator!=(const Term &, const Term &);
    Term operator~();
    float operator()(float);
    void operator++();
    void operator--();
    friend ostream &operator<<(ostream &, Term &);
    friend istream &operator>>(istream &, Term &);
};
class Polynomial
{
private:
    vector<Term> Terms;

public:
    Polynomial(vector<Term> terms1) : Terms(terms1) {}
    Polynomial(Term term1) { Terms.push_back(term1); }
    Polynomial(string);
    Polynomial(float);
    Polynomial(){};
    void set_Terms(vector<Term> terms) { Terms = terms; }
    vector<Term> get_Terms() { return Terms; }
    void sort_polynomial();
    string get_whole_polynomial();
    friend Polynomial operator+(Polynomial, Polynomial);
    friend Polynomial operator-(Polynomial, Polynomial);
    friend Polynomial operator*(Polynomial, Polynomial);
    void operator+=(Polynomial);
    void operator-=(Polynomial);
    void operator*=(Polynomial);
    void operator=(Polynomial);
    friend bool operator>(Polynomial, Polynomial);
    friend bool operator<(Polynomial, Polynomial);
    friend bool operator==(Polynomial, Polynomial);
    friend bool operator!=(Polynomial, Polynomial);
    friend bool operator>=(Polynomial, Polynomial);
    friend bool operator<=(Polynomial, Polynomial);
    Polynomial operator~();
    void operator++();
    void operator--();
    float operator()(float);
    Term &operator[](int);
    const Term &operator[](int) const;
    friend ostream &operator<<(ostream &, Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);
    int number_of_terms() { return Terms.size(); }
    int degree_of_polynomial();
    friend ostream &operator<<(ostream &, Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);
};
bool check_string_for_Term(string);
int menu1();
int menu2(Polynomial);
void compare_cout(Polynomial, Polynomial);
void save_current_polynomial_on_a_file(Polynomial, string);
void save_current_polynomial_binary(Polynomial, string);
Polynomial read_file_text();
Polynomial read_file_binary();
int main()
{
    system("color B1");
    Polynomial current_Polynomial = 0;
    int list = 0;
    bool go_to1 = false;
    while (list != 4)
    {
        if (!go_to1)
            list = menu1();
        if (list == 1) // new polynomial
        {
            int list2 = 0;
            while (list2 != 10)
            {
                list2 = menu2(current_Polynomial);
                if (list2 == 1) // add
                {
                    system("cls");
                    try
                    {
                        Polynomial poly1;
                        cout << "Enter your polynomial:";
                        cin >> poly1;
                        current_Polynomial += poly1;
                        current_Polynomial.sort_polynomial();
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 2) // subtract
                {
                    system("cls");
                    try
                    {
                        Polynomial poly1;
                        cout << "Enter your polynomial:";
                        cin >> poly1;
                        current_Polynomial -= poly1;
                        current_Polynomial.sort_polynomial();
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 3) // multiply
                {
                    system("cls");
                    try
                    {
                        Polynomial poly1;
                        cout << "Enter your polynomial:";
                        cin >> poly1;
                        current_Polynomial *= poly1;
                        current_Polynomial.sort_polynomial();
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 4) // derivative
                {
                    system("cls");
                    current_Polynomial = ~current_Polynomial;
                    current_Polynomial.sort_polynomial();
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 5) // find degree
                {
                    system("cls");
                    cout << current_Polynomial.degree_of_polynomial() << "\n";
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 6) // value for x
                {
                    system("cls");
                    float x_num;
                    cout << "Enter the x:";
                    cin >> x_num;
                    cout << "Result:" << current_Polynomial(x_num) << "\n";
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 7) // compare
                {
                    system("cls");
                    try
                    {
                        Polynomial poly1;
                        cout << "Enter your polynomial:";
                        cin >> poly1;
                        compare_cout(current_Polynomial, poly1);
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 8) // save to text
                {
                    system("cls");
                    try
                    {
                        cout << "Enter the file name:";
                        string file_name;
                        cin >> file_name;
                        save_current_polynomial_on_a_file(current_Polynomial, file_name);
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else if (list2 == 9) // save to binary
                {
                    system("cls");
                    try
                    {
                        cout << "Enter the file name:";
                        string file_name;
                        cin >> file_name;
                        save_current_polynomial_binary(current_Polynomial, file_name);
                    }
                    catch (string error)
                    {
                        cout << error << "\n";
                    }
                    cout << "Now ";
                    system("pause");
                }
                else
                {
                    if (list2 != 10)
                    {
                        cerr << "\nwrong number .Now ";
                        system("pause");
                    }
                }
            }
            go_to1 = false;
        }
        else if (list == 2) // load from text file
        {
            system("cls");
            try
            {
                current_Polynomial = read_file_text();
                go_to1 = true;
                list = 1;
            }
            catch (string error)
            {
                cerr << error << '\n';
            }
            cout << "Now ";
            system("pause");
        }
        else if (list == 3) // load from binary file
        {
            system("cls");
            try
            {
                current_Polynomial = read_file_binary();
                go_to1 = true;
                list = 1;
            }
            catch (string error)
            {
                cerr << error << '\n';
            }
            cout << "Now ";
            system("pause");
        }
        else
        {
            if (list != 4)
            {
                cerr << "\nwrong number .Now ";
                system("pause");
            }
        }
    }
}
bool check_string_for_Term(string term1)
{
    if (term1.at(0) == '+' || term1.at(0) == '-')
        term1.erase(0, 1);
    int n_point = 0, n_power = 0, n_x = 0;
    for (int i = 0; i < term1.size(); i++)
    {
        if (term1.at(i) != '0' && term1.at(i) != '1' && term1.at(i) != '2' && term1.at(i) != '3' && term1.at(i) != '4' && term1.at(i) != '5' && term1.at(i) != '6' && term1.at(i) != '7' && term1.at(i) != '8' && term1.at(i) != '9' && term1.at(i) != '.' && term1.at(i) != '^' && term1.at(i) != 'x')
            return false;
        if (term1.at(i) == '.')
            n_point++;
        else if (term1.at(i) == 'x')
            n_x++;
        else if (term1.at(i) == '^')
            n_power++;
    }
    if (n_point > 1 || n_power > 1 || n_x > 1)
        return false;
    int p_point = -1, p_x = -1, p_power = -1;
    for (int i = 0; i < term1.size(); i++)
    {
        if (term1.at(i) == '.')
            p_point = i;
        else if (term1.at(i) == 'x')
            p_x = i;
        else if (term1.at(i) == '^')
            p_power = i;
    }
    if (n_point == 1 && n_x == 1 && n_power == 1)
    {
        if (p_point == 0 || p_point >= p_x - 1 || p_x != p_power - 1 || p_power == term1.size() - 1)
            return false;
    }
    else if (n_point == 0 && n_x == 1 && n_power == 1)
    {
        if (p_x != p_power - 1 || p_power == term1.size() - 1)
            return false;
    }
    else if (n_point == 1 && n_x == 0 && n_power == 1)
    {
        return false;
    }
    else if (n_point == 1 && n_x == 1 && n_power == 0)
    {
        if (p_point == 0 || p_point >= p_x - 1 || p_x != term1.size() - 1)
            return false;
    }
    else if (n_point == 0 && n_x == 0 && n_power == 1)
    {
        return false;
    }
    else if (n_point == 1 && n_x == 0 && n_power == 0)
    {
        if (p_point == 0 || p_point == term1.size() - 1)
            return false;
    }
    else if (n_point == 0 && n_x == 1 && n_power == 0)
    {
        if (p_x != term1.size() - 1)
            return false;
    }
    return true;
}
Term::Term(string str)
{
    if (!check_string_for_Term(str))
    {
        string error = "invalid string";
        throw error;
    }
    else
    {
        string c = "", p = "";
        int posc = -1, posp = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str.at(i) == 'x')
                posc = i;
            if (str.at(i) == '^')
                posp = i;
        }
        if (posc == -1)
            c = str;
        else if (posc == 0)
            c = "1";
        else
            for (int i = 0; i < posc; i++)
                c.push_back(str.at(i));
        if (posc == -1 && posp == -1)
            p = "0";
        else if (posc != -1 && posp == -1)
            p = "1";
        else
            for (int i = posp + 1; i < str.size(); i++)
                p.push_back(str.at(i));

        power = stoi(p);
        if (c == "+")
            c = "1";
        else if (c == "-")
            c = "-1";
        coefficient = stof(c);
    }
}
string Term::get_whole_Term()
{
    if (coefficient == 0)
        return "0";
    else if (coefficient == 1 && power == 0)
        return "1";
    else if (coefficient == 1 && power == 1)
        return "x";
    else if (coefficient == 1)
        return "x^" + to_string(power);
    else if (power == 0)
        return to_string(coefficient);
    else if (power == 1)
        return to_string(coefficient) + "x";
    return to_string(coefficient) + "x^" + to_string(power);
}
Term operator+(const Term &term1, const Term &term2)
{
    Term result;
    if (term1.power == term2.power)
    {
        result.coefficient = term2.coefficient + term1.coefficient;
        result.power = term1.power;
    }
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
    return result;
}
Term operator-(const Term &term1, const Term &term2)
{
    Term result;
    if (term1.power == term2.power)
    {
        result.coefficient = term1.coefficient - term2.coefficient;
        result.power = term1.power;
    }
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
    return result;
}
Term operator*(const Term &term1, const Term &term2)
{
    Term result;
    result.coefficient = term2.coefficient * term1.coefficient;
    result.power = term2.power + term1.power;
    return result;
}
Term operator/(const Term &term1, const Term &term2)
{
    Term result;
    if (term2.coefficient == 0)
    {
        string error = "the denominator is 0";
        throw error;
    }
    else
    {
        result.coefficient = term1.coefficient / term2.coefficient;
        result.power = term1.power - term2.power;
    }
    return result;
}
void Term::operator+=(const Term &term1)
{
    if (term1.power == power)
    {
        coefficient += term1.coefficient;
    }
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
}
void Term::operator-=(const Term &term1)
{
    if (term1.power == power)
    {
        coefficient -= term1.coefficient;
    }
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
}
void Term::operator*=(const Term &term1)
{
    power += term1.power;
    coefficient *= term1.coefficient;
}
void Term::operator/=(const Term &term1)
{
    if (term1.coefficient == 0)
    {
        string error = "the denominator is 0";
        throw error;
    }
    else
    {
        power -= term1.power;
        coefficient /= term1.coefficient;
    }
}
void Term::operator=(const Term &term1)
{
    power = term1.power;
    coefficient = term1.coefficient;
}
bool operator>(const Term &term1, const Term &term2)
{
    if (term1.power > term2.power)
        return true;
    if (term1.power == term2.power && term1.coefficient > term2.coefficient)
        return true;
    return false;
}
bool operator<(const Term &term1, const Term &term2)
{
    if (term1.power < term2.power)
        return true;
    if (term1.power == term2.power && term1.coefficient < term2.coefficient)
        return true;
    return false;
}
bool operator==(const Term &term1, const Term &term2)
{
    if (term1.power == term2.power && term1.coefficient == term2.coefficient)
        return true;
    return false;
}
bool operator!=(const Term &term1, const Term &term2)
{
    if (term1.power == term2.power && term1.coefficient == term2.coefficient)
        return false;
    return true;
}
bool operator>=(const Term &term1, const Term &term2)
{
    if (term2 == term1 || term1 > term2)
        return true;
    return false;
}
bool operator<=(const Term &term1, const Term &term2)
{
    if (term2 == term1 || term1 < term2)
        return true;
    return false;
}
Term Term::operator~()
{
    Term result;
    if (coefficient == 0 || power == 0)
    {
        result.power = 0;
        result.coefficient = 0;
    }
    else
    {
        result.coefficient = power * coefficient;
        result.power = power - 1;
    }
    return result;
}
float Term::operator()(float fi)
{
    x = coefficient * (pow(fi, power));
    return x;
}
void Term::operator++()
{
    if (power == 0)
        coefficient++;
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
}
void Term::operator--()
{
    if (power == 0)
        coefficient--;
    else
    {
        string err = "The powers are not the same";
        throw err;
    }
}
ostream &operator<<(ostream &fout, Term &term1)
{
    fout << term1.get_whole_Term();
    return fout;
}
istream &operator>>(istream &fin, Term &term1)
{
    string t;
    fin >> t;
    Term term2 = t;
    term1 = term2;
    return fin;
}
////////////////////////////////////polynomial :
Polynomial::Polynomial(string polystr)
{
    vector<Term> firstterms;
    string monostr = "";
    monostr.push_back(polystr.at(0));
    for (int i = 1; i < polystr.size(); i++)
    {
        if (polystr.at(i) == '+' || polystr.at(i) == '-')
        {
            if (check_string_for_Term(monostr))
            {
                Term fterm = monostr;
                firstterms.push_back(fterm);
                monostr = "";
                monostr.push_back(polystr.at(i));
            }
            else
            {
                string error = "invalid string";
                throw error;
            }
        }
        else
        {
            monostr.push_back(polystr.at(i));
        }
    }
    if (check_string_for_Term(monostr))
    {
        Term term1 = monostr;
        firstterms.push_back(term1);
    }
    else
    {
        string error = "invalid string";
        throw error;
    }
    Terms = firstterms;
    Term zero("0");
    if (Terms.size() == 0)
        Terms.push_back(zero);
}
Polynomial::Polynomial(float fi)
{
    Term term1 = fi;
    Terms.push_back(term1);
}
void Polynomial::sort_polynomial()
{
    for (int i = 0; i < Terms.size(); i++)
    {
        for (int j = i + 1; j < Terms.size(); j++)
        {
            if (Terms.at(i).get_powr() == Terms.at(j).get_powr())
            {
                Terms.at(i) += Terms.at(j);
                swap(Terms.at(j), Terms.at(Terms.size() - 1));
                Terms.pop_back();
            }
        }
    }
    for (int i = 0; i < Terms.size(); i++)
    {
        if (Terms.at(i).get_whole_Term() == "0")
        {
            swap(Terms.at(i), Terms.at(Terms.size() - 1));
            Terms.pop_back();
        }
    }
    for (int i = 0; i < Terms.size(); i++)
    {
        for (int j = i + 1; j < Terms.size(); j++)
        {
            if (Terms.at(i) < Terms.at(j))
                swap(Terms.at(i), Terms.at(j));
        }
    }
}
string Polynomial::get_whole_polynomial()
{
    if (Terms.size() == 0)
        return "0";
    string result = "";
    result = result + Terms.at(0).get_whole_Term();
    for (int i = 1; i < Terms.size(); i++)
    {
        if (Terms.at(i).get_whole_Term().at(0) != '-')
            result = result + "+" + Terms.at(i).get_whole_Term();
        else
            result = result + Terms.at(i).get_whole_Term();
    }
    return result;
}
Polynomial operator+(Polynomial poly1, Polynomial poly2)
{
    string poly1str = poly1.get_whole_polynomial();
    string poly2str = poly2.get_whole_polynomial();
    if (poly2str.at(0) != '-')
        poly2str = "+" + poly2str;
    Polynomial result = poly1str + poly2str;
    result.sort_polynomial();
    return result;
}
Polynomial operator-(Polynomial poly1, Polynomial poly2)
{
    Polynomial poly2_2 = poly2 * -1;
    return poly1 + poly2_2;
}
Polynomial operator*(Polynomial poly1, Polynomial poly2)
{
    Polynomial result;
    for (int i = 0; i < poly1.Terms.size(); i++)
    {
        for (int j = 0; j < poly2.Terms.size(); j++)
        {
            result.Terms.push_back(poly1.Terms.at(i) * poly2.Terms.at(j));
        }
    }
    result.sort_polynomial();
    return result;
}
void Polynomial::operator+=(Polynomial poly2)
{
    Polynomial poly1(Terms);
    poly1 = poly1 + poly2;
    Terms = poly1.Terms;
}
void Polynomial::operator-=(Polynomial poly2)
{
    Polynomial poly1(Terms);
    poly1 = poly1 - poly2;
    Terms = poly1.Terms;
}
void Polynomial::operator*=(Polynomial poly2)
{
    Polynomial poly1(Terms);
    poly1 = poly1 * poly2;
    Terms = poly1.Terms;
}
void Polynomial::operator=(Polynomial poly2)
{
    poly2.sort_polynomial();
    Terms = poly2.Terms;
}
bool operator>(Polynomial poly1, Polynomial poly2)
{
    poly1.sort_polynomial();
    poly2.sort_polynomial();
    int min = poly1.Terms.size();
    min = poly2.Terms.size();
    for (int i = 0; i < min; i++)
    {
        if (poly1.Terms.at(i) > poly2.Terms.at(i))
            return true;
        if (poly1.Terms.at(i) < poly2.Terms.at(i))
            return false;
    }
    if (poly1.Terms.size() > poly2.Terms.size())
        return true;
    return false;
}
bool operator<(Polynomial poly1, Polynomial poly2)
{
    if (poly2 > poly1)
        return true;
    return false;
}
bool operator==(Polynomial poly1, Polynomial poly2)
{
    if (poly1 > poly2 || poly1 < poly2)
        return false;
    return true;
}
bool operator!=(Polynomial poly1, Polynomial poly2)
{
    if (poly1 == poly2)
        return false;
    return true;
}
bool operator>=(Polynomial poly1, Polynomial poly2)
{
    if (poly1 < poly2)
        return false;
    return true;
}
bool operator<=(Polynomial poly1, Polynomial poly2)
{
    if (poly1 > poly2)
        return false;
    return true;
}
Polynomial Polynomial::operator~()
{
    vector<Term> moshtaghs_t;
    for (int i = 0; i < Terms.size(); i++)
    {
        moshtaghs_t.push_back(~Terms.at(i));
    }
    Polynomial moshtaghs = moshtaghs_t;
    moshtaghs.sort_polynomial();
    return moshtaghs;
}
void Polynomial::operator++()
{
    Term term1 = 1;
    Terms.push_back(term1);
}
void Polynomial::operator--()
{
    Term term1 = -1;
    Terms.push_back(term1);
}
float Polynomial::operator()(float fi)
{
    float all = 0;
    for (int i = 0; i < Terms.size(); i++)
    {
        all += Terms.at(i)(fi);
    }
    return all;
}
Term &Polynomial::operator[](int index)
{
    if (index < 0 || index > Terms.size() - 1)
    {
        string err = "invalid index";
        throw err;
    }
    return Terms.at(index);
}
const Term &Polynomial::operator[](int index) const
{
    if (index < 0 || index > Terms.size() - 1)
    {
        string err = "invalid index";
        throw err;
    }
    return Terms.at(index);
}
int Polynomial::degree_of_polynomial()
{
    if (Terms.size() == 0)
        return 0;
    return Terms.at(0).get_powr();
}
ostream &operator<<(ostream &fout, Polynomial &poly1)
{
    fout << poly1.get_whole_polynomial();
    return fout;
}
istream &operator>>(istream &fin, Polynomial &poly1)
{
    string t;
    fin >> t;
    Polynomial poly2 = t;
    poly1 = poly2;
    return fin;
}
int menu1()
{
    int list;
    system("cls");
    for (int i = 0; i < 29; i++)
        cout << "\xB2";
    cout << "\n\xB1\xB1                         \xB1\xB1\n\xB1\xB1        Main Menu        \xB1\xB1";
    cout << "\n\xB1\xB1                         \xB1\xB1\n\xB1\xB1 1-New Polynomial        \xB1\xB1";
    cout << "\n\xB1\xB1 2-Load from text file   \xB1\xB1\n\xB1\xB1 3-Load from binary file \xB1\xB1";
    cout << "\n\xB1\xB1 4-Quit                  \xB1\xB1\n\xB1\xB1                         \xB1\xB1\n";
    for (int i = 0; i < 29; i++)
        cout << "\xB2";
    cout << "\nChoose(1/2/3/4):";
    cin >> list;
    return list;
}
int menu2(Polynomial poly)
{
    system("cls");
    int list;
    poly.sort_polynomial();
    int size = 35;
    if (poly.get_whole_polynomial().size() > 9)
        size += (poly.get_whole_polynomial().size() - 9);
    vector<string> lines;
    lines.resize(18);
    for (int i = 0; i < 18; i++)
    {
        lines.at(i).resize(size);
    }
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || i == 17)
                lines.at(i).at(j) = '\xB2';
            else if (j == 0 || j == 1 || j == size - 1 || j == size - 2)
                lines.at(i).at(j) = '\xB1';
            else
                lines.at(i).at(j) = ' ';
        }
    }
    string x = "Polynomial Menu";
    for (int i = 0; i < x.size(); i++)
        lines.at(2).at(i + 10) = x.at(i);
    x = "current Polynomial = " + poly.get_whole_polynomial();
    for (int i = 0; i < x.size(); i++)
        lines.at(4).at(i + 3) = x.at(i);
    x = "1- Add";
    for (int i = 0; i < x.size(); i++)
        lines.at(6).at(i + 3) = x.at(i);
    x = "2- Subtract";
    for (int i = 0; i < x.size(); i++)
        lines.at(7).at(i + 3) = x.at(i);
    x = "3- Multiply";
    for (int i = 0; i < x.size(); i++)
        lines.at(8).at(i + 3) = x.at(i);
    x = "4- Derivative";
    for (int i = 0; i < x.size(); i++)
        lines.at(9).at(i + 3) = x.at(i);
    x = "5- Find Degree";
    for (int i = 0; i < x.size(); i++)
        lines.at(10).at(i + 3) = x.at(i);
    x = "6- Find Value for specific x";
    for (int i = 0; i < x.size(); i++)
        lines.at(11).at(i + 3) = x.at(i);
    x = "7- Compare";
    for (int i = 0; i < x.size(); i++)
        lines.at(12).at(i + 3) = x.at(i);
    x = "8- Save to a text file";
    for (int i = 0; i < x.size(); i++)
        lines.at(13).at(i + 3) = x.at(i);
    x = "9- Save to a binary file";
    for (int i = 0; i < x.size(); i++)
        lines.at(14).at(i + 3) = x.at(i);
    x = "10- Back to Main Menu";
    for (int i = 0; i < x.size(); i++)
        lines.at(15).at(i + 3) = x.at(i);
    for (int i = 0; i < 18; i++)
    {
        cout << lines.at(i) << "\n";
    }
    cout << "Choose(1/2/3/4/5/6/7/8/9/10):";
    cin >> list;
    return list;
}
void compare_cout(Polynomial poly1, Polynomial poly2)
{
    cout << "Current polynomial:" << poly1 << "\nyour polynomial:" << poly2 << "\n";
    cout << "Current polynomial > your polynomial :";
    if (poly1 > poly2)
        cout << "True\n";
    else
        cout << "False\n";
    cout << "Current polynomial >= your polynomial :";
    if (poly1 >= poly2)
        cout << "True\n";
    else
        cout << "False\n";
    cout << "Current polynomial < your polynomial :";
    if (poly1 < poly2)
        cout << "True\n";
    else
        cout << "False\n";
    cout << "Current polynomial <= your polynomial :";
    if (poly1 <= poly2)
        cout << "True\n";
    else
        cout << "False\n";
    cout << "Current polynomial == your polynomial :";
    if (poly1 == poly2)
        cout << "True\n";
    else
        cout << "False\n";
}
void save_current_polynomial_on_a_file(Polynomial poly, string name)
{
    ofstream outFile(name, ios::trunc);
    if (outFile)
    {
        outFile << poly;
        outFile.close();
    }
    else
    {
        string err = "file did not oppen!";
        throw err;
    }
}
void save_current_polynomial_binary(Polynomial poly, string name)
{
    string polystr = poly.get_whole_polynomial();
    int size = polystr.size();
    ofstream outFile(name, ios::trunc | ios::binary);
    if (outFile)
    {
        outFile.write((char *)&size, sizeof(size));
        for (int i = 0; i < size; i++)
        {
            char monostr = polystr.at(i);
            outFile.write((char *)&monostr, sizeof(monostr));
        }
        outFile.close();
    }
    else
    {
        string err = "file did not oppen!";
        throw err;
    }
}
Polynomial read_file_text()
{
    Term zero("0");
    Polynomial poly(zero);
    string name, polystr;
    cout << "Enter file name:";
    cin >> name;
    ofstream file(name, ios::app); // to make sure we have the file
    ifstream fin(name, ios::in);
    if (fin)
    {
        fin >> polystr;
        fin.close();
    }
    else
    {
        string err = "file did not` open! ...";
        throw err;
    }
    if (polystr.size() == 0)
        polystr = "0";
    poly = polystr;
    poly.sort_polynomial();
    return poly;
}
Polynomial read_file_binary()
{

    string name;
    cout << "Enter file name:";
    cin >> name;
    int size = 0;
    string polystr = "";
    ofstream file(name, ios::app | ios::binary); // to make sure we have the file
    ifstream fin(name, ios::in | ios::binary);
    if (fin)
    {
        fin.read((char *)&size, sizeof(size));
        for (int i = 0; i < size; i++)
        {
            char monostr;
            fin.read((char *)&monostr, sizeof(monostr));
            polystr.push_back(monostr);
        }
        fin.close();
    }
    else
    {
        string err = "file did not  open! ...";
        throw err;
    }
    if (polystr.size() == 0)
        polystr = "0";
    Polynomial poly(polystr);
    poly.sort_polynomial();
    return poly;
}