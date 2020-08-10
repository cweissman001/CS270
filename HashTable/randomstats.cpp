#include <iostream>
#include <vector>

//Values used in the corresponding hashtest file
int tablesize = 390000;
int num_entries = 354986;

int main() {

  std::cout << std::endl << "Expected values for assigning " << num_entries 
            << " entries to a table of size " << tablesize << std::endl;
  
  std::vector<double> buf1(tablesize+1, 0.0);
  std::vector<double> buf2(tablesize+1, 0.0);
  std::vector<double>& p_nu_before_x = buf1;
  std::vector<double>& p_nu_after_x = buf2;

  p_nu_before_x[tablesize] = 1.0;

  for (int x = 1; x <= num_entries; x++) {
    for (int num_unused = 0; num_unused < tablesize; num_unused++) {
      p_nu_after_x[num_unused] = 
        p_nu_before_x[num_unused+1] * ((double)(num_unused+1)/(double)tablesize) + 
        p_nu_before_x[num_unused] * (1.0 - ((double)num_unused/(double)tablesize));
    }
    std::swap(p_nu_before_x, p_nu_after_x);
    p_nu_before_x[tablesize] = 0.0;
  }
  double ev_nu = 0.0;
  for (int num_unused = 0; num_unused < tablesize; num_unused++) {
    ev_nu += ((double)num_unused) * p_nu_before_x[num_unused];
  }
  std::cout << "Num unused: " << ev_nu << std::endl;
}
