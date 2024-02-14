#include "expressions.h"
#include <queue> // where will you use this?
using namespace std;

// You must use recursion for every function except for breadthFirst

// FІXΜЕ: implement the evaluation function to perform the operations
//        represented by the expression tree
int evaluate(ExpressionNode *root) {
  int result = root->data;

  if(root->op == '+'){
    result =  evaluate(root->left) + evaluate(root->right);
    return result;
  }
  if(root->op == '-'){
    result =  evaluate(root->left) - evaluate(root->right);
    return result;
  }
  if(root->op == '*'){
    result =  evaluate(root->left) * evaluate(root->right);
    return result;
  }
  if(root->op == '/'){
    result =  evaluate(root->left) / evaluate(root->right);
    return result;
  }

  return result;
}

// FІXΜЕ: implement preorder traversal for expression trees, outputting a string. 
//        For each node, your string should contain the data (leaf nodes) or the 
//        op (interior nodes). You should put spaces between each node value.
std::string preOrder(ExpressionNode* root) {

  string result = " ";

  if(root->op == '+' || root->op == '-' || root->op == '*' || root->op == '/'){
    result = root->op + result + preOrder(root->left) + " " + preOrder(root->right);
    return result;
  }

  result = to_string(root->data);

  return result;
}

// FІXΜЕ: implement postorder traversal for expression trees, with the same output style as preOrder
std::string postOrder(ExpressionNode* root) {
  string result = "";
  
  if(root->op != '+' && root->op != '-' && root->op != '*' && root->op != '/'){
    result = to_string(root->data);
    return result;
  }

  if(root->op == '+' || root->op == '-' || root->op == '*' || root->op == '/'){
    result = postOrder(root->left) + " " + postOrder(root->right) + " " + root->op;
  }

  return result;
}

// FІXΜЕ: implement inorder traversal for expression trees, with the same output style as preOrder
std::string inOrder(ExpressionNode* root) {
  string result = "";
  if(root->left == nullptr && root->right == nullptr){
    result = to_string(root->data);
    return result;
  }

  result = inOrder(root->left) + " " + root->op + " " + inOrder(root->right);

  return result;
}

// THIS IS THE ONLY NON-RECURSIVE FUNCTION
// FІXΜЕ: implement breadth-first order traversal for expression trees, with the same output style as preOrder
std::string breadthFirst(ExpressionNode* root) {
  queue<ExpressionNode*> bread;
  string result = "";
 // ExpressionNode* temp;
  bread.push(root);
  bool firstOp = true;
  
  while(bread.empty() != true){
    if(bread.front()->op == '+' || bread.front()->op == '-' || bread.front()->op == '*' || bread.front()->op == '/'){
      if(firstOp != true){
        result = result + " " + bread.front()->op;
      }else{
        result = bread.front()->op;
        firstOp = false;
      }
   }else{
      result = result + " " + to_string(bread.front()->data);
   } 
   
   if(bread.front()->left != nullptr){ 
     bread.push(bread.front()->left);
   }
   if(bread.front()->right != nullptr){
     bread.push(bread.front()->right);   
   }
    bread.pop();
    
  } 

  return result;
}

// FІXΜЕ: calculate the height of a tree by finding the maximum-length
//        path from the root
int height(ExpressionNode* root) {
  if(root == NULL){
    return -1;
  }
  int result = 0;
  int answer = 0;
  result = result + 1 + height(root->left);
  answer = answer + 1 + height(root->right);

  if(result > answer){
    return result;
  }else{
    return answer;
  }
}

// FІXΜЕ: mirror all the nodes in the tree (i.e., make it so that
//        every left child becomes the right child, and vice-versa)
void reverse(ExpressionNode* root) {
  if(root == NULL){
    return;
  }
  ExpressionNode* temp = new ExpressionNode;

  reverse(root->left);
  reverse(root->right);
  
  temp->left = root->left;
  root->left = root->right;
  root->right = temp->left;

  return;
}
