// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_matrix_row) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    const int width = 10;
    const int height = 10;
    int value = 3;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, value);
    
for (int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
        ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
      }
}

  delete mat; // delete the Matrix
}


TEST(test_matrix_init) {
    Matrix *mat = new Matrix;
    const int width = 7;
    const int height = 9;
    Matrix_init(mat, width, height);

    ASSERT_EQUAL(Matrix_width(mat), width);
    ASSERT_EQUAL(Matrix_height(mat), height);
    
    delete mat; // delete the Matrix
  }

TEST(test_matrix_width) {
    Matrix *mat_small = new Matrix;
    Matrix_init(mat_small, 2, 2);
    
    Matrix *mat_wide = new Matrix;
    Matrix_init(mat_wide, 10, 2);
    
    Matrix *mat_square = new Matrix;
    Matrix_init(mat_square, 10, 10);
    
    ASSERT_EQUAL(Matrix_width(mat_small), 2);
    ASSERT_EQUAL(Matrix_width(mat_wide), 10);
    ASSERT_EQUAL(Matrix_width(mat_square), 10);
    
    delete mat_small;
    delete mat_wide;
    delete mat_square;
    
}

TEST(test_matrix_height) {
    Matrix *mat_short = new Matrix;
    Matrix_init(mat_short, 1, 1);
    
    Matrix *mat_mid = new Matrix;
    Matrix_init(mat_mid, 10, 5);
    
    Matrix *mat_tall = new Matrix;
    Matrix_init(mat_tall, 15, 15);
    
    ASSERT_EQUAL(Matrix_height(mat_short), 1);
    ASSERT_EQUAL(Matrix_height(mat_mid), 5);
    ASSERT_EQUAL(Matrix_height(mat_tall), 15);
    
    delete mat_short;
    delete mat_mid;
    delete mat_tall;
}

TEST(test_matrix_max) {
    Matrix *mat = new Matrix;
    const int width = 3;
    const int height = 5;
    const int max_value = 150;
    Matrix_init(mat, width, height);
    
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            *Matrix_at(mat, row, col) = row * width + col;
        }
    }
    *Matrix_at(mat, 4, 2) = max_value;
        ASSERT_EQUAL(Matrix_max(mat), max_value);
    
delete mat;
}

TEST(test_matrix_min_col){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);
    
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 2;
    *Matrix_at(mat, 1, 2) = 3;
    
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 3), 1);
    
}
TEST(test_matrix_basic) {
    Matrix *mat = new Matrix;
    
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 1);

string output_correct = "3 3\n1 1 1 \n1 0 1 \n1 1 1 \n";

ostringstream ss_output;
Matrix_print(mat, ss_output);
ASSERT_EQUAL(ss_output.str(), output_correct);
delete mat;
}

    
    
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here

