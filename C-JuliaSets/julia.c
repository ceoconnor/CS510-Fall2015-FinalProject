#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "cplane.h"


int main (int argc, char **argv){
    // Checks to see if the parameters are correct. Should be 9
    if(argc < 9){
        fprintf(stderr, "Parameters are not set correctly");
        return 1;
    }
    
    // Initialize the parameters
    VALUE xmin = atoi(argv[1]);
    VALUE xmax = atoi(argv[2]);
    VALUE ymin = atoi(argv[3]);
    VALUE ymax = atoi(argv[4]);
    INDEX xpoints = atoi(argv[5]);
    INDEX ypoints = atoi(argv[6]);
    VALUE creal = atoi(argv[7]);
    VALUE cimag = atoi(argv[8]);
    int MAXITER = 256;
    
    // Set up the complex plane
    CPLANE complex_plane = new_cp(xmin, xmax, ymin, ymax, xpoints, ypoints);
    Complex c, n, z;
    c.x = creal;
    c.y = cimag;
    int i, j = 0;
    
    // Creates the complex plane
    for (i=0;i<xpoints;i++){
        for(j=0;j<ypoints;j++){
            n = get(&complex_plane,i,j);
            z.x = n.x;
            z.y = n.y;
            int k = 0;
            
            // Iterates through the complex plane to create the juliamap
            while (1){
                z = juliamap(z,c);
                k++;
                // Stops the program if z is greater than 2 (otherwise will go to infinity)
                if (fabsl(z.x+z.y)>2){
                    printf("%Lf,%Lf,%d\n",n.x,n.y,k);
                    return 0;
                }
                // If z never reaches 2, it is going infinitely small so the program stops after it iterates 256 times
                else if (k>=MAXITER) {
                    printf("%Lf,%Lf,%d",n.x,n.y,k);
                    return 0;
                }
            }
        }
    }
    return 0;
}