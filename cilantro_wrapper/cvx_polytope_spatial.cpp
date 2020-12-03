
#include "cvx_polytope_spatial.h"
#include <iostream>

//using namespace std;

    SpatialRegion::SpatialRegion(float* vert , int size, int dim){

                //cout << "constructor with parameters\n";

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
                if(size > 0)
                this->set_isEmpty(false);
        
    }

    SpatialRegion* SpatialRegion::sr_clone(){

            SpatialRegion* copy = new SpatialRegion();
            *copy = *this;
            return copy;
    }

    void SpatialRegion::sr_release(){
            if(this->dim == dimension::D2){
                this->vertices2D.clear();
                this->sRegion2D.~SpaceRegion();
            }
            else{
                this->vertices3D.clear();
                this->sRegion3D.~SpaceRegion();    
            }
            //delete this;
            set_isEmpty(true);
    }
    
    void SpatialRegion::sr_complement(){
        if(this->get_isEmpty())
            std::wcerr << "The spatial region is empty!\n";
        else if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.complement();
        else
                this->sRegion3D = this->sRegion3D.complement();
    }

    void SpatialRegion::sr_relative_complement(SpatialRegion *sr ){
        if(this->get_isEmpty() || sr->get_isEmpty())
            std::wcerr << "The spatial region is empty!\n";
        else if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.relativeComplement(sr->sRegion2D);
        else
                this->sRegion3D = this->sRegion3D.relativeComplement(sr->sRegion3D);
    }

    void SpatialRegion::sr_union_with(SpatialRegion *sr ){
        if(this->get_isEmpty() || sr->get_isEmpty())
            std::wcerr << "The spatial region is empty!\n";
        else if(get_dim() == dimension::D2)
                this->sRegion2D = this->sRegion2D.unionWith(sr->sRegion2D);
        else
                this->sRegion3D = this->sRegion3D.unionWith(sr->sRegion3D);
    }

    void SpatialRegion::sr_intersection_with(SpatialRegion *sr){
        if(this->get_isEmpty() || sr->get_isEmpty())
            std::wcerr << "The spatial region is empty!\n";
        else if(get_dim() == dimension::D2)
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

    bool SpatialRegion::get_isEmpty(){
            return isEmpty;
    }

    void SpatialRegion::set_isEmpty(bool val){
            isEmpty = val;
    }

    double SpatialRegion::get_Area(){
                double area = 0;
                if(this->get_isEmpty())
                        return 0;
                else if( this->get_dim() == dimension::D2)
                        for(auto polytope : this->sRegion2D.getConvexPolytopes())
                                area += polytope.getVolume();
                else{
                        for(auto polytope : this->sRegion3D.getConvexPolytopes())
                                area += polytope.getArea();
                }
                return area;
    }   

    double SpatialRegion::get_Volume(){
                if(this->get_isEmpty())
                        return 0;
                else if( this->get_dim() == dimension::D2)
                        return 0;
                else
                        return this->sRegion3D.getVolume();
    }

    void SpatialRegion::print_space_region2D(){
        cout << "Spatial Region size: " << this->sRegion2D.getConvexPolytopes().size() << endl;
        cout << "Regions Volume: " << this->get_Volume() << endl;
        cout << "Regions Area: " << this->get_Area() << endl;
        cout << "[\n";   
        int cnt = 0;
        for(auto polytope : this->sRegion2D.getConvexPolytopes()){
                if( cnt > 0 )
                    cout << ",\n";
                cout << "Polytope "<< ++cnt << " :\n" << polytope.getVertices() << endl;    
                cout << "Area: " << polytope.getArea() << endl;    
                cout << "Volume: " << polytope.getVolume() << endl; 
        }
        cout << "]\n\n";   
    }    
    
    void SpatialRegion::print_space_region3D(){
        cout << "Spatial Region size: " << this->sRegion3D.getConvexPolytopes().size() << endl;
        cout << "Regions Volume: " << this->get_Volume() << endl;
        cout << "Regions Area: " << this->get_Area() << endl;
        cout << "[\n";   
        int cnt = 0;
        for(auto polytope : this->sRegion3D.getConvexPolytopes()){
                if( cnt > 0 )
                    cout << ",\n";
                cout << "Polytope "<< ++cnt << " :\n" << polytope.getVertices() << endl;    
                cout << "Area: " << polytope.getArea() << endl;    
                cout << "Volume: " << polytope.getVolume() << endl; 
        }
        cout << "]\n\n";   
    }