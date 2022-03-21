
#pragma once

//==============================================================================

#include <cmath>

//==============================================================================

#define FORCEINLINE __forceinline

//==============================================================================

struct Vector3D
{
    union
    {
        double vec[3];
        
        struct
        {
            double x;
            double y;
            double z;
        };
    };

    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) noexcept
        : x(x), y(y), z(z)
    {
    }

    Vector3D(const Vector3D &) = default;
    Vector3D(Vector3D &&) = default;
    ~Vector3D() = default;

    Vector3D &operator=(const Vector3D &) = default;
    Vector3D &operator=(Vector3D &&) = default;

    FORCEINLINE void operator+=(const Vector3D &a) noexcept
    {
        x += a.x;
        y += a.y;
        z += a.z;
    }

    FORCEINLINE void operator-=(const Vector3D &a) noexcept
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
    }

    FORCEINLINE void operator*=(double k) noexcept
    {
        x *= k;
        y *= k;
        z *= k;
    }

    FORCEINLINE void operator/=(double k) noexcept
    {
        const auto m = 1.0f / k;
        x *= m;
        y *= m;
        z *= m;
    }

    FORCEINLINE const double &operator[](int index) const
    {
        return vec[index];
    }

    FORCEINLINE double &operator[](int index)
    {
        return vec[index];
    }

    FORCEINLINE friend Vector3D operator-(const Vector3D &a) noexcept
    {
        return Vector3D(-a.x, -a.y, -a.z);
    }

    FORCEINLINE friend Vector3D operator+(const Vector3D &a, const Vector3D &b) noexcept
    {
        return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    FORCEINLINE friend Vector3D operator-(const Vector3D &a, const Vector3D &b) noexcept
    {
        return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    FORCEINLINE friend Vector3D operator*(double k, const Vector3D &a) noexcept
    {
        return Vector3D(k * a.x, k * a.y, k * a.z);
    }

    FORCEINLINE friend Vector3D operator*(const Vector3D &a, double k) noexcept
    {
        return Vector3D(a.x * k, a.y * k, a.z * k);
    }

    FORCEINLINE friend Vector3D operator/(const Vector3D &a, double k) noexcept
    {
        const auto inv_k = 1.0f / k;
        return Vector3D(a.x * m, a.y * m, a.z * m);
    }

    FORCEINLINE friend double Dot(const Vector3D &a, const Vector3D &b) noexcept
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    FORCEINLINE friend Vector3D Cross(const Vector3D &a, const Vector3D &b) noexcept
    {
        return Vector3D(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    FORCEINLINE friend double Triple(const Vector3D &a, const Vector3D &b, const Vector3D &c)
    {
        return Dot(a, Cross(b, c));
    }

    FORCEINLINE friend double Length2(const Vector3D &a) noexcept
    {
        return Dot(a, a);
    }

    FORCEINLINE friend double Length(const Vector3D &a) noexcept
    {
        return sqrt(Length2(a));
    }

    FORCEINLINE friend double Dist2(const Vector3D &a, const Vector3D &b)
    {
        return Length2(b - a);
    }

    FORCEINLINE friend double Dist(const Vector3D &a, const Vector3D &b)
    {
        return sqrt(Dist2(a, b));
    }

    FORCEINLINE friend Vector3D Norm(const Vector3D &a) noexcept
    {
        return a / Length(a);
    }
};

//==============================================================================
