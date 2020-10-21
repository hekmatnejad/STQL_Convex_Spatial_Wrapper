
#include "cvx_polytope_spatial.h"
#include <iostream>

//using namespace std;

    SpatialRegion::SpatialRegion(float* vert , int size, int dim){

                cout << "constructor with parameters\n";

                if(dim == dimension::D3){
                        for(int i=0; i < size; i ++){
                                this->vertices3D.emplace_back(vert[3*i], vert[3*i+1], vert[3*i+2] );
                                //cout << vert[3*i] << " , " << vert[3*i+1] << " , " << vert[3*i+2] << endl;
                        }
                        sRegion3D = cilantro::SpaceRegion3f(this->vertices3D);
                }
                else{
                        if (size == 4){
                                this->vertices2D.emplace_back(vert[0],vert[1] );
                                this->vertices2D.emplace_back(vert[0],vert[3] );
                                this->vertices2D.emplace_back(vert[2],vert[1] );
                                this->vertices2D.emplace_back(vert[2],vert[3] );
                        }
                        else{
                                for(int i=0; i < size; i ++){
                                        this->vertices2D.emplace_back(vert[2*i], vert[2*i+1] );
                                        //cout << vert[2*i] << " , " << vert[2*i+1] << endl;
                                }
                        }
                        sRegion2D = cilantro::SpaceRegion2f(this->vertices2D);
                }
        
    }

    SpatialRegion* SpatialRegion::sr_clone(){

            SpatialRegion* copy = new SpatialRegion();
            //copy->sRegion2D = this->sRegion2D;
            *copy = *this;
            return copy;
    }

    void SpatialRegion::sr_release(){
            delete this;
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