#ifndef BEHAVIORAL_NODE_H
#define BEHAVIORAL_NODE_H

enum Status { RUNNING, SUCCESS, FAILURE };

class BehavioralNode {
  Status status;
public:
  BehavioralNode();
  Status getStatus();
};

#endif
