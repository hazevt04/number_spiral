// C++ File for main
#include <iostream>
#include <iomanip>
#include <vector>


void print_spiral( std::vector<std::vector<int>> temp, int n ) {
   for( int rindex = 0; rindex < n; ++rindex ) {
      for( int cindex = 0; cindex < n; ++cindex ) {
         std::cout 
            << std::setw(3) 
            << temp[rindex][cindex] 
            << " "; 
      }
      std::cout << "\n";
   } 
   std::cout << "\n";
}

void print_spiral_flat( std::vector<std::vector<int>> temp, int n ) {
   std::cout << "["; 
   for( int rindex = 0; rindex < n; ++rindex ) {
      std::cout << "["; 
      for( int cindex = 0; cindex < n; ++cindex ) {
         std::cout 
            << temp[rindex][cindex] 
            << ((cindex != (n-1)) ? ", ": ""); 
      }
      std::cout << "]" 
         << ((rindex != (n-1)) ? ", ": ""); 
   } 
   std::cout << "]\n";
}

std::vector<std::vector<int>> create_spiral(int n) {
   std::vector<std::vector<int>> temp;
   for( int rindex = 0; rindex < n; ++rindex ) {
      std::vector<int> a( n, 0 );
      temp.push_back(a);
   }

   int row = 0;
   int col = 0;

   int iter = 0;
   int val = 1;
   int max_iter = (n+1)/2;

   while (iter < max_iter) {
      row = iter;
      col = iter;

      while ( col < (n-iter) ) {
         temp[row][col] = val++;
         ++col;
      }

      row = iter+1;
      col = n-(iter+1);
      while ( row < (n-iter) ) {
         temp[row][col] = val++;
         ++row;
      }

      row = n-(iter+1);
      col = n-(iter+2);
      while ( col > (iter-1) ) {
         temp[row][col] = val++;
         --col;
      }
      
      row = n-(iter+2);
      col = iter;
      while ( row > iter ) {
         temp[row][col] = val++;
         --row;
      }

      ++iter;

   } // end of while spiral_num < num_spirals
   return temp;
}



int main( int argc, char** argv ) {
   try {
      int n = 4;

      if ( argc > 1 ) {
         n = strtol( argv[1], NULL, 10 );
      }

      std::vector<std::vector<int>> temp = create_spiral(n);
      
      std::cout << "N is " << n << " Output: "; 
      print_spiral_flat(temp, n);
      std::cout << "\n";

      print_spiral(temp, n);

      return EXIT_SUCCESS;


   } catch ( std::exception& ex ) {
      std::cout << "ERROR: " << ex.what() << "\n";
      return EXIT_FAILURE;
   }
}

