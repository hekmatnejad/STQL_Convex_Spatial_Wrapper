
#ifndef __CVX_POLYTOPE_SPATIAL_H
#define __CVX_POLYTOPE_SPATIAL_H

#include <cilantro/spatial/space_region.hpp>
#include <cilantro/utilities/point_cloud.hpp>
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
    bool isEmpty = true;

public:
    //void* obj;

    SpatialRegion(){

    };

    
    ~SpatialRegion(){
        //cout << "object deleted.\n";
    };

    cilantro::SpaceRegion2f getRegion2D(){
        return sRegion2D;
    }

    cilantro::SpaceRegion3f getRegion3D(){
        return sRegion3D;
    }


    SpatialRegion(float* vert , int size, int dim);


    SpatialRegion* sr_clone();

    void sr_release();

    void sr_complement();

    void sr_relative_complement(SpatialRegion *sr);

    void sr_union_with(SpatialRegion *sr);

    void sr_intersection_with(SpatialRegion *sr);

    void set_dim(dimension d);

    dimension get_dim();

    bool get_isEmpty();

    void set_isEmpty(bool val);

    double get_Area();

    double get_Volume();

    void print_space_region2D();
     
    void print_space_region3D();

};

#endif