// Project UID af1f95f547e44c8ea88730dfb185559d
//
//  main.cpp
//  p2-cv
//
//  Created by Ope Ojubanire on 1/24/22.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "Image.h"
#include "Matrix.h"
#include <cassert>
#include <string>
#include <cstdlib>
#include "processing.h"

using namespace std;

int main(int argc, char **argv) {
    
    std::ifstream fin;
    std::ofstream fout;
    string filename;
    
    
    if (argc == 5 || argc == 4 ) {
        string filename = argv[1];
        string outfilename = argv[2];
        int w;
        int h;
        Image* img = new Image;
        
        fin.open(filename.c_str());
        if (!fin.is_open()) {
        cout << "Error opening file: " << filename << endl;
            return 1;
        }
        
        ofstream fout(outfilename.c_str());
            if (argc == 5) {
            w = atoi(argv[3]);
            h = atoi(argv[4]);
            Image_init(img, fin);
            seam_carve(img,w,h);
    }
        if (argc == 4){
        w = atoi(argv[3]);
        Image_init(img, fin);
        seam_carve(img, w, Image_height(img));
    }
        
        Image_print(img,fout);
    }
    else {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    }
    return 0;
}

