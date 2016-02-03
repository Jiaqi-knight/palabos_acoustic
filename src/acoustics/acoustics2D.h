
#include "palabos2D.h"
#ifndef PLB_PRECOMPILED // Unless precompiled version is used,
#include "palabos2D.hh"   // include full template code
#endif
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace plb;
using namespace std;

namespace plb_acoustics{
	
	template<typename T, template<typename U> class Descriptor>
	void defineAnechoicWall(plint nx, plint ny,
	 MultiBlockLattice2D<T,Descriptor>& lattice,
	  T size_anechoic_buffer, plint orientation, T omega, 
	  Array<plint, 2> position_anechoic_wall, plint length_anechoic_wall){
		
		// delta increase to the right
		if(orientation == 1){
			for(T delta = 0; delta <= size_anechoic_buffer; delta++){        
		        DotList2D points_to_aplly_dynamics;
		        for (int i = 0; i <= length_anechoic_wall; ++i){
		            points_to_aplly_dynamics.addDot(
		            	Dot2D(position_anechoic_wall[0] + delta, i));
		        }
		        AnechoicDynamics<T,DESCRIPTOR> *anechoicDynamics = 
		        new AnechoicDynamics<T,DESCRIPTOR>(omega);
		        anechoicDynamics->setDelta((T) delta);
		        defineDynamics(lattice, points_to_aplly_dynamics, anechoicDynamics);
	    	}
		}
	}

	template<typename T, template<typename U> class Descriptor>
	void defineAnechoicWallOnTheRightSide(plint nx, plint ny,
	 MultiBlockLattice2D<T,Descriptor>& lattice, T size_anechoic_buffer, T omega){
	 	plint orientation = 1;
	    plint length_anechoic_wall = ny;
	    // position x and y
	    Array<plint, 2> position_anechoic_wall((plint) nx - size_anechoic_buffer - 1, 0);
	    defineAnechoicWall(nx, ny, lattice, size_anechoic_buffer,
	                       orientation, omega, position_anechoic_wall, length_anechoic_wall);
	}

}