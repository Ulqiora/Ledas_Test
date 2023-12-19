#include "Segment3D.h"

#include <utility>

Segment3D::Segment3D(Vector3D&& start, Vector3D&& end) :
                    start(start),
                    end(end) {}

Vector3D Segment3D::getDirection() const noexcept {
    return end - start;
}

const Vector3D &Segment3D::getStart() const noexcept {
    return start;
}

const Vector3D &Segment3D::getEnd() const noexcept {
    return end;
}

