#pragma once

class NodeNext
{
public:
  int val;
  NodeNext *left;
  NodeNext *right;
  NodeNext *next;

  NodeNext() = delete;

  NodeNext(int val) = delete;

  NodeNext(int val,
           NodeNext *left,
           NodeNext *right,
           NodeNext *next)
      : val(val),
        left(left),
        right(right),
        next(next) {}

  ~NodeNext()
  {
    delete left;
    delete right;
    delete next;
  }

  friend bool operator==(const NodeNext &, const NodeNext &);
};

bool operator==(const NodeNext &lhs, const NodeNext &rhs)
{
  bool value_equal = lhs.val == rhs.val;
  bool left_equal = false;
  if (lhs.left && rhs.left)
  {
    left_equal = (*lhs.left == *rhs.left);
  }
  else if (!lhs.left && !rhs.left)
  {
    left_equal = true;
  }

  bool right_equal = false;
  if (lhs.right && rhs.right)
  {
    right_equal = (*lhs.right == *rhs.right);
  }
  else if (!lhs.right && !rhs.right)
  {
    right_equal = true;
  }

  bool next_equal = false;
  if (lhs.next && rhs.next)
  {
    next_equal = (*lhs.next == *rhs.next);
  }
  else if (!lhs.next && !rhs.next)
  {
    next_equal = true;
  }

  return value_equal && left_equal && right_equal && next_equal;
}