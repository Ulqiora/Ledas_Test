#include <iostream>
#include <Segment3D.h>
#include <cmath>


Vector3D Intersect(const Segment3D& first,const Segment3D& second){
    static const double kAccuracy = 1e-6;
    auto    directionF = first.getDirection(),
            directionS = second.getDirection();
    auto cross = directionF.Cross(directionS);
    auto startFS = first.getStart() - second.getStart();
    if(cross == Vector3D{0,0,0}) {
        throw std::invalid_argument("These are collinear segments");
    }
    auto mixed = startFS.Scalar(cross);
    if(mixed != 0){
        throw std::invalid_argument("The lines of these segments do not intersect");
    }
    auto divisible = directionS.getX()*(first.getStart().getY() - second.getStart().getY())/ directionS.getY() +
                    second.getStart().getX() - first.getStart().getX();
    auto divider = directionF.getX() - (directionS.getX()*directionF.getY()/directionS.getY());
    auto firstLineParameter = divisible/divider;
    auto secondLineParameter = (directionF.getY()*firstLineParameter+first.getStart().getY()-second.getStart().getY())/directionS.getY();
    if(!((firstLineParameter > 0.0 || std::fabs(firstLineParameter) < kAccuracy) &&
         (firstLineParameter < 1.0 || std::fabs(firstLineParameter - 1.0) < kAccuracy) &&
         (secondLineParameter > 0.0 || std::fabs(secondLineParameter) < kAccuracy) &&
         (secondLineParameter < 1.0 || std::fabs(firstLineParameter - 1.0) < kAccuracy)))
        throw std::invalid_argument("The segments do not intersect");
    return first.getStart() + directionF*firstLineParameter;
}
int main(){
    Segment3D   segment1(Vector3D{3,0,0},Vector3D{1,2,0}),
                segment2(Vector3D{1,1,0},Vector3D{1,2,0});
    std::cout<<Intersect(segment1,segment2);

}