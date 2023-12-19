#include "Segment3D.h"
#include <cmath>
#include <utility>
#include <array>

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

std::tuple<double, double> solveLinearSystem(std::array<double, 3> first,
                                             std::array<double, 3> second,
                                             std::array<double, 3> third) {
    double determinant = first[0] * second[1] - first[1] * second[0];

    if (determinant != 0) {
        double x = (first[2] * second[1] - second[2] * first[1]) / determinant;
        double y = (first[0] * second[2] - second[0] * first[2]) / determinant;

        return {x, y};
    }
    determinant = first[0] * third[1] - first[1] * third[0];
    if (determinant != 0) {
        double x = (first[2] * third[1] - third[2] * first[1]) / determinant;
        double y = (first[0] * third[2] - third[0] * first[2]) / determinant;
        return {x, y};
    }
    throw std::invalid_argument("Invalid argument!");
}

Vector3D Intersect(const Segment3D& first,const Segment3D& second){
    static const double kAccuracy = 1e-6;
    if (first.getStart() == second.getStart() || first.getStart() == second.getEnd()) {
        return first.getStart();
    } else if (first.getEnd() == second.getStart() || first.getEnd() == second.getEnd()){
        return first.getEnd();
    }
    auto    directionF = first.getDirection(),
            directionS = second.getDirection();
    auto cross = directionF.Cross(directionS);
    if(cross == Vector3D{0,0,0})
        throw std::invalid_argument("These are collinear segments");
    if((first.getStart() - second.getStart()).Scalar(cross) != 0)
        throw std::invalid_argument("The lines of these segments do not intersect");
    double firstLineParameter,secondLineParameter;
    std::exception_ptr exception;
    try {
        std::tie(firstLineParameter,secondLineParameter) = solveLinearSystem({
            directionF.getX(), -directionS.getX(),
            second.getStart().getX() - first.getStart().getX(),
        },{
            directionF.getY(), -directionS.getY(),
            second.getStart().getY() - first.getStart().getY()
        },{
            directionF.getZ(), -directionS.getZ(),
            second.getStart().getZ() - first.getStart().getZ()
        });
    }catch(...) {
        exception = std::current_exception();
    }
    if(!((firstLineParameter > 0.0 || std::fabs(firstLineParameter) < kAccuracy) &&
         (firstLineParameter < 1.0 || std::fabs(firstLineParameter - 1.0) < kAccuracy) &&
         (secondLineParameter > 0.0 || std::fabs(secondLineParameter) < kAccuracy) &&
         (secondLineParameter < 1.0 || std::fabs(firstLineParameter - 1.0) < kAccuracy)))
        throw std::invalid_argument("The segments do not intersect");
    return first.getStart() + directionF*firstLineParameter;
}

