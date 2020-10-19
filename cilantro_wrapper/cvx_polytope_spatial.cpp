
#include "cvx_polytope_spatial.h"
#include <iostream>

//using namespace std;

    SpatialRegion::SpatialRegion(float* vert , int dim){

                cout << "constructor with parameters\n";
                if(dim == dimension::D3){
                        //for(int i=0; i < 8; i ++){
                        //        this->vertices3D.emplace_back(vert[3*i],vert[3*i+1], vert[3*i+2] );
                        //}
                }
                else{
                        this->vertices2D.emplace_back(vert[0],vert[1] );
                        this->vertices2D.emplace_back(vert[0],vert[3] );
                        this->vertices2D.emplace_back(vert[2],vert[1] );
                        this->vertices2D.emplace_back(vert[2],vert[3] );
                }
        
                dim == 2 ? this->dim = dimension::D2 : dimension::D3;
                if(dim == 2)
                        sRegion2D = cilantro::SpaceRegion2f(this->vertices2D);
                //else
                //        sRegion3D = cilantro::SpaceRegion3f(this->vertices3D);
                
    }

    void SpatialRegion::test(){
        //cout << "test\n";
    }

    SpatialRegion* SpatialRegion::sr_clone(){
            //std::cout << "clone\n";
            SpatialRegion* copy = new SpatialRegion();
            return copy;
    }
    
    void SpatialRegion::sr_complement(){
            //std::cout << "complement\n";
    }

    void SpatialRegion::sr_union_with(SpatialRegion* sr ){
            //std::cout << "union\n";

    }

    void SpatialRegion::sr_intersection_with(SpatialRegion* sr){
            //std::cout << "intersection\n";

    }