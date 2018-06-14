#ifndef BEHAVIORAL_NODE_H
#define BEHAVIORAL_NODE_H

enum Status { RUNNING, SUCCESS, FAILURE };

class BehavioralNode {
protected:
  Status status;
  bool visited;
public:
  BehavioralNode();

  // getters
  Status getStatus();
  bool wasVisited();

  // setters
  void setVisited(bool _visited);
  void setStatus(Status _status);

  // called upon every visit by parent node
  Status process();

  // if it was not visited in this cycle
  virtual Status processInit();

  // if it was visited and hasn't returned success or failure yet
  virtual Status processContinue();

};

#endif
