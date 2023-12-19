#include <iostream>
#include <Segment3D.h>
#include <cmath>

int main(){
    Segment3D   segment1(Vector3D{2,2,2},Vector3D{-2,-2,-2}),
                segment2(Vector3D{2,2,-2},Vector3D{-2,-2,2});
    try{
        std::cout<<Intersect(segment1,segment2);
    }catch (const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
}