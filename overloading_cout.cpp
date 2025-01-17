#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    friend std::istream& operator>> (std::istream& in, Point& point);
    //oppure defini metodi analoghi e .real() e .imag() per i Complex e usi quelli.
};

//overloading << operator

// //Consider the expression std::cout << point. If the operator is <<, what are the operands?
//  The left operand is the std::cout object, and the right operand is your Point class object. 
//  std::cout is actually an object of type std::ostream.

//To get cout to accept a Point object after the insertion operator,
// overload the insertion operator to recognize an std::ostream object
// on the left and a Point on the right. The overloaded << operator function
// must then be declared as a friend of class Complex so it can access the private data within a Point object.
//The overloaded operator returns a reference to the original ostream object,
// which means you can combine insertions: come std::cout <<"The Point is" << p <<'\n'';

// // if you try to return std::ostream by value, you’ll get a compiler error.
//  This happens because std::ostream specifically disallows being copied.
// // In this case, we return the left hand parameter as a reference.
//  This not only prevents a copy of std::ostream from being made, it also allows us to “chain” output commands together,
// such as std::cout << p (che è di tipo punto) << "ciao"; (stai facendo il chain con operatori << diversi)

//Since they take the Point type as the right argument (b in a@b), they must be implemented as non-members.
//puoi anche creare l'operatore membro << ma poi come fai a chiamarlo?
//cout come membro
// std::ostream& operator <<(std::ostream& os)
// {
//     os << "(" << r_ << ',' << i_ << ')' <<'\n';
//     return os;
// }
//problema è che per stampare devi chiamare << su un complesso e non puoi su un cout
/*Complex ciao; 
  
 ciao <<  std::cout;// ok
 std::cout << ciao; //not ok
 */


std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}
// std::ostream& operator<< (std::ostream& out, const Point& point)
// {
//     // Since operator<< is a friend of the Point class, we can access Point's members directly.
//     out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

//     return out;
// }



//the input operator needs a non-const reference to Point as it need to change its value.
std::istream& operator>> (std::istream& in, Point& point)
{
    // Since operator>> is a friend of the Point class, we can access Point's members directly.
    // note that parameter point must be non-const so we can modify the class members with the input values
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main()
{
    std::cout << "Enter a point: ";

    Point point;
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}