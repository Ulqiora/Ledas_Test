#pragma once
#include "Vector3D.h"
class Segment3D
{
private:
    Vector3D start;
    Vector3D end;
public:
    Segment3D() = delete;
    Segment3D(Segment3D&&) = default;
    Segment3D(const Segment3D&) = default;
    Segment3D(Vector3D&& start, Vector3D&& End);
    [[nodiscard]]Vector3D getDirection()const noexcept;
    const Vector3D& getStart() const noexcept;
    const Vector3D &getEnd() const noexcept;

    ~Segment3D() = default;
};
Vector3D Intersect(const Segment3D& first,const Segment3D& second);