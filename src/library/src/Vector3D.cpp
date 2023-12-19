#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include "Vector3D.h"

static double kAccuracy = 1e-6;

[[nodiscard]] double Vector3D::getX() const {
    return X;
}

[[nodiscard]] double Vector3D::getY() const {
    return Y;
}

[[nodiscard]] double Vector3D::getZ() const {
    return Z;
}

Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

void Vector3D::setX(double x) {
    X = x;
}

void Vector3D::setY(double y) {
    Y = y;
}

void Vector3D::setZ(double z) {
    Z = z;
}

Vector3D::Vector3D() : X(0), Y(0), Z(0) {}

bool Vector3D::operator==(const Vector3D &other) const {
        return (std::fabs(X - other.X) < kAccuracy) &&
               (std::fabs(Y - other.Y) < kAccuracy) &&
               (std::fabs(Z - other.Z) < kAccuracy);
}

Vector3D Vector3D::Cross(const Vector3D & other) const noexcept {
    return {
        Y*other.Z - Z*other.Y,
        Z*other.X - X*other.Z,
        X*other.Y - Y*other.X
    };
}

double Vector3D::Scalar(const Vector3D &other) const noexcept {
    return X * other.X + Y * other.Y + Z * other.Z;
}

double Vector3D::isCollinear(const Vector3D &other) const {
    auto resultCross{Cross(other)};
    return resultCross.X == 0 && resultCross.Y == 0 && resultCross.Z == 0;
}
Vector3D Vector3D::operator-(const Vector3D& other) const
{
    return {X - other.X, Y - other.Y, Z - other.Z};
}

Vector3D Vector3D::operator*(double coeff) const noexcept {
    return {
        X*coeff,
        Y*coeff,
        Z*coeff
    };
}

Vector3D Vector3D::operator+(const Vector3D &other) const noexcept {
    return {
        X + other.X,
        Y + other.Y,
        Z + other.Z
    };
}

std::ostream& operator<<(std::ostream& os,const Vector3D& vector3D){
    os<<"Point info\n";
    os<<"\tX: "<<vector3D.getX()<<'\n';
    os<<"\tY: "<<vector3D.getY()<<'\n';
    os<<"\tZ: "<<vector3D.getZ()<<'\n';
    return os;
}
