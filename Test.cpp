
#include <iostream>

#include "Vector3D.h"

std::ostream &operator<<(std::ostream &out, const Vector3D &a)
{
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}

int main()
{
    Vector3D A;
    std::cout << "A = " << A << std::endl;

    std::cout << std::endl;

    A.x = 1;
    A.y = 2;
    A.z = 3;
    std::cout << "A = " << A << std::endl;

    Vector3D B;
    B[0] = 2;
    B[1] = 0;
    B[2] = -1;
    std::cout << "B = " << B << std::endl;

    std::cout << std::endl;

    std::cout << "A + B = "  << A + B  << std::endl;
    std::cout << "A - B = "  << A - B  << std::endl;
    std::cout << "2 * A = "  << 2 * A  << std::endl;
    std::cout << "A * 3 = "  << A * 3  << std::endl;
    std::cout << "A / 10 = " << A / 10 << std::endl;

    std::cout << std::endl;

    std::cout << "+A = " << +A << std::endl;
    std::cout << "-A = " << -A << std::endl;

    std::cout << std::endl;

    Vector3D C(A);
    std::cout << "C(A) = " << C << std::endl;

    C = B;
    std::cout << "C = B = " << C << std::endl;

    Vector3D D(2, 3, 4);
    std::cout << "D = " << D << std::endl;

    std::cout << std::endl;

    D += A;
    std::cout << "D += A " << D << std::endl;
    D -= A;
    std::cout << "D -= A " << D << std::endl;
    D *= 5;
    std::cout << "D *= 5 " << D << std::endl;
    D /= 5;
    std::cout << "D /= 5 " << D << std::endl;

    std::cout << std::endl;

    std::cout << "Dot(A, B) = "       << Dot(A, B)       << std::endl;
    std::cout << "Cross(A, B) = "     << Cross(A, B)     << std::endl;
    std::cout << "Triple(A, B, D) = " << Triple(A, B, D) << std::endl;

    std::cout << std::endl;

    std::cout << "Dot(A, A) = "       << Dot(A, A) << std::endl;
    std::cout << "Cross(B, B) = "     << Cross(B, B) << std::endl;
    std::cout << "Cross(B, A) = "     << Cross(B, A) << std::endl;
    std::cout << "Triple(A, A, B) = " << Triple(A, A, B) << std::endl;

    std::cout << std::endl;

    std::cout << "Length (A) = " << Length (A) << std::endl;
    std::cout << "Length2(A) = " << Length2(A) << std::endl;

    std::cout << std::endl;

    std::cout << "Dist (A, B) = " << Dist (A, B) << std::endl;
    std::cout << "Dist2(A, B) = " << Dist2(A, B) << std::endl;
    std::cout << "Dist (A, A) = " << Dist (A, A) << std::endl;
    std::cout << "Dist2(A, A) = " << Dist2(A, A) << std::endl;

    std::cout << std::endl;

    std::cout << "Norm(A) = "         << Norm(A)         << std::endl;
    std::cout << "Length(Norm(A)) = " << Length(Norm(A)) << std::endl;

    std::cout << std::endl;

    std::cout << "OK" << std::endl;
    std::cin.get();
    return 0;
}
