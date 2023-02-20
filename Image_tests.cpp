// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_image_width){
    Image *img_small = new Image;
    Image_init(img_small, 3, 3);
    
    Image *img_wide = new Image;
    Image_init(img_wide, 9, 2);
    
    Image *img_square = new Image;
    Image_init(img_square, 11, 11);
    
    ASSERT_EQUAL(Image_width(img_small), 3);
    ASSERT_EQUAL(Image_width(img_wide), 9);
    ASSERT_EQUAL(Image_width(img_square), 11);
    
    
}

TEST(test_image_height) {
    Image *img_short = new Image;
    Image_init(img_short, 1, 1);
    
    Image *img_mid = new Image;
    Image_init(img_mid, 4, 6);
    
    Image *img_tall = new Image;
    Image_init(img_tall, 15, 20);
    
    ASSERT_EQUAL(Image_height(img_short), 1);
    ASSERT_EQUAL(Image_height(img_mid), 6);
    ASSERT_EQUAL(Image_height(img_tall), 20);
    
}

TEST(test_image_basic) {
// A hardcoded PPM image
    string input = "P3\n2 2\n255\n255 0 0 0 255 0 \n";
    input += "0 0 255 255 255 255 \n";
// Use istringstream for simulated input
    istringstream ss_input(input);
    
    Image *img = new Image;
    Image_init(img, ss_input);
    
    ASSERT_EQUAL(Image_width(img), 2);
    
    Pixel red = { 255, 0, 0 };
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    
delete img;
}

TEST(test_img_fill) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};
    
    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);

    // Capture our output
    ostringstream s;
    Image_print(img, s);

    // Correct output
    ostringstream correct;
    correct << "P3\n2 2\n255\n";
    correct << "255 0 0 0 255 0 \n";
    correct << "0 0 255 255 255 255 \n";
    ASSERT_EQUAL(s.str(), correct.str());

    delete img; // delete the Image
  }

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN()// Do NOT put a semicolon here


