
#ifndef __CVX_POLYTOPE_SPATIAL_H
#define __CVX_POLYTOPE_SPATIAL_H

#include <cilantro/spatial/space_region.hpp>
#include <iostream>

using namespace std;

enum dimension {
    D2 = 2, D3
};

class SpatialRegion {
    
    dimension dim;
    std::vector<Eigen::Vector2f> vertices2D;
    std::vector<Eigen::Vector3f> vertices3D;
    cilantro::SpaceRegion2f sRegion2D;
    cilantro::SpaceRegion3f sRegion3D;

public:

    void test();

    SpatialRegion(){

    };

    
    ~SpatialRegion(){

    };

    cilantro::SpaceRegion2f getRegion2D(){
        return sRegion2D;
    }

    cilantro::SpaceRegion3f getRegion3D(){
        return sRegion3D;
    }


    SpatialRegion(float* vert , int dim);


    SpatialRegion* sr_clone();
    
    void sr_complement();

    void sr_union_with(SpatialRegion* sr );

    void sr_intersection_with(SpatialRegion* sr);

    void print_space_region2D(){
        cout << "polytope size: " << this->sRegion2D.getConvexPolytopes().size() << endl;
        for(auto polytope : this->sRegion2D.getConvexPolytopes()){
                cout << "polytope:\n" << polytope.getVertices() << endl;    
                cout << "Area: " << polytope.getArea() << endl;    
                cout << "Volume: " << polytope.getVolume() << endl; 
                cout << "--------------------------\n";   
        }
    }
};

#endif