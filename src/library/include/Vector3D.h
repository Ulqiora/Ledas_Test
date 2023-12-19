#pragma once
#include <iostream>
class Vector3D {
private:
    double X;
    double Y;
    double Z;
public:
    Vector3D();
    Vector3D(Vector3D&&) = default;
    Vector3D(const Vector3D&) = default;
    bool operator==(const Vector3D& other) const;
    Vector3D(double x, double y, double z);
    ~Vector3D() = default;
public:
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    [[nodiscard]] double getZ() const ;
    Vector3D operator*(double)const noexcept;
    Vector3D operator+(const Vector3D&)const noexcept;
    [[nodiscard]]Vector3D Cross(const Vector3D&) const noexcept;
    [[nodiscard]] double Scalar(const Vector3D&) const noexcept;
    [[nodiscard]] double isCollinear(const Vector3D&) const;
    Vector3D operator-(const Vector3D& other) const;
};

std::ostream& operator<<(std::ostream& os,const Vector3D& vector3D);