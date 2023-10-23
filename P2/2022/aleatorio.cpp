#include "aleatorio.h"

void vectorAleatorio(){
	for(int i=0 ; i<iPermutaciones ; i++){
			random_shuffle(aVector, aVector+V); // Vector aleatorio
			
			bIguales = true;
			for(int j=0 ; j<V ; j++)
				if(aVector[j] != aOrdenado[j])
					bIguales=false;
			if(bIguales)
				iOrdenados++;
	}
}
