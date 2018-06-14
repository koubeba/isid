#include "TestLeaf.h"

#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

TestLeaf::TestLeaf(int number): LeafNode() {
  i = number;
}

Status TestLeaf::processInit() {

    srand(time(NULL));
    int result = rand() % 3 + 1;

  std::cout << "Setting the test leaf "<< i << " to visited and returning...";
  visited = true;

  switch(result) {
    case 1:
      status = SUCCESS;
      std::cout << "success" << std::endl;
    break;
    case 2:
      status = FAILURE;
      std::cout << "failure" << std::endl;
    break;
    case 3:
      status = RUNNING;
      std::cout << "RUNNING" << std::endl;
    break;
  }
  return status;
}

Status TestLeaf::processContinue() {
  std::cout << "The test leaf" << i << "was already visited. Returning...";

  srand(time(NULL) + 1000);
  int result = rand() % 3 + 1;

  switch(result) {
    case 1:
      status = SUCCESS;
      std::cout << "success" << std::endl;
    break;
    case 2:
      status = FAILURE;
      std::cout << "failure" << std::endl;
    break;
    case 3:
      status = RUNNING;
      std::cout << "RUNNING" << std::endl;
    break;
  }
  return status;
}
