
#include "cvx_polytope_spatial.h"
#include <iostream>

//using namespace std;

    SpatialRegion::SpatialRegion(float* vert , int size){

                cout << "constructor with parameters\n";

                if(size == dimension::D3){
                        for(int i=0; i < 8; i ++){
                                this->vertices3D.emplace_back(vert[3*i], vert[3*i+1], vert[3*i+2] );
                                cout << vert[3*i] << " , " << vert[3*i+1] << " , " << vert[3*i+2] << endl;
                        }
                }
                else{
                        this->vertices2D.emplace_back(vert[0],vert[1] );
                        this->vertices2D.emplace_back(vert[0],vert[3] );
                        this->vertices2D.emplace_back(vert[2],vert[1] );
                        this->vertices2D.emplace_back(vert[2],vert[3] );
                }
        
                //size == 2 ? this->dim = dimension::D2 : dimension::D3;
                if(size == 2)
                        sRegion2D = cilantro::SpaceRegion2f(this->vertices2D);
                else
                        sRegion3D = cilantro::SpaceRegion3f(this->vertices3D);
                
    }

    void SpatialRegion::test(){
        //cout << "test\n";
    }

    SpatialRegion* SpatialRegion::sr_clone(){
            //std::cout << "clone\n";
            SpatialRegion* copy = new SpatialRegion();
            copy->sRegion2D = this->sRegion2D;
            return copy;
    }
    
    void SpatialRegion::sr_complement(){
        if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.complement();
        else
                this->sRegion3D = this->sRegion3D.complement();
    }

    void SpatialRegion::sr_relative_complement(SpatialRegion *sr ){
        if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.relativeComplement(sr->sRegion2D);
        else
                this->sRegion3D = this->sRegion3D.relativeComplement(sr->sRegion3D);
    }

    

    void SpatialRegion::sr_union_with(SpatialRegion *sr ){
        if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.unionWith(sr->sRegion2D);
        else
                this->sRegion3D = this->sRegion3D.unionWith(sr->sRegion3D);
    }

    void SpatialRegion::sr_intersection_with(SpatialRegion *sr){
        if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.intersectionWith(sr->sRegion2D);
        else
                this->sRegion3D = this->sRegion3D.intersectionWith(sr->sRegion3D);
    }

    void SpatialRegion::set_dim(dimension d){
            dim = d;
    }

    dimension SpatialRegion::get_dim(){
            return dim;
    }