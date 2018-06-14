#include "SelectorNode.h"
#include "SequenceNode.h"
#include "TestLeaf.h"
#include "BehavioralTree.h"

#include <iostream>
#include <stdlib.h>

int main() {
  std::cout << "Creating a sequence node" << std::endl;
  SequenceNode sN1 = SequenceNode();

  std::cout << "Adding a leaf node" << std::endl;
  sN1.addChild(new TestLeaf(1));

  std::cout << "Adding a leaf node" << std::endl;
  sN1.addChild(new TestLeaf(2));

  std::cout << "Adding a leaf node" << std::endl;
  sN1.addChild(new TestLeaf(3));

  sN1.setNumber(1);

  std::cout << "Creating a second selector node" << std::endl;
  SelectorNode sN2 = SelectorNode();

  std::cout << "Adding a leaf node" << std::endl;
  sN2.addChild(new TestLeaf(1));

  std::cout << "Adding a leaf node" << std::endl;
  sN2.addChild(new TestLeaf(2));

  std::cout << "Adding a leaf node" << std::endl;
  sN2.addChild(new TestLeaf(3));

  sN2.setNumber(2);

  std::cout << "Creating a master selector node" << std::endl;
  SelectorNode sN = SelectorNode();
  sN.addChild(&sN1);
  sN.addChild(&sN2);


  std::cout << "Creating a behavioral tree" << std::endl;
  BehavioralTree bTree = BehavioralTree(&sN);

for (int i=0; i<5; i++) {
  bTree.iterate();
  std::cout << std::endl;
}


}
