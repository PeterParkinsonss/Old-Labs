#include "bst.h"

#include <iostream>

#include <list>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

std::string to_string(const Pokemon& p) {
  return to_string(p.number) + ": " + p.name + " (" + p.type + ")";
}

// constructor
// FІXΜЕ: make the tree start out empty
BST::BST() {
  root = NULL;
}

// This is the insert function
// FІXΜЕ: add a new BSTNode (created on the heap) into the current tree
// the key of the new node is p.number, and the data is p
void BST::catchPokemon(const Pokemon& p) {
  // empty tree case: make this pokemon the root and you're done

  if(root == NULL){ 
    root = new BSTNode;
    root->data = p;
    root->key = p.number;
    root->left = nullptr;
    root->right = nullptr;
    root->parent = nullptr;
    return;
  }
  // Otherwise, the root is not null and we need to search--
  // Search for the node to make sure it's not already there.
  // If it's already there, just return from this function without
  // doing anything.
   else{
      if(search(p.number) != nullptr){
        return;
      }else{
        BSTNode* newMon = new BSTNode;
        BSTNode* zedNode = root;
        BSTNode* cudNode = root;
        while(cudNode != nullptr){
          zedNode = cudNode;
          if(p.number < cudNode->key){
            cudNode = cudNode->left;
          }else if(p.number > cudNode->key){
            cudNode = cudNode->right;
          }
        }
        if(p.number < zedNode->key){
          zedNode->left = newMon;
          newMon->parent = zedNode;
          newMon->left = nullptr;
          newMon->right = nullptr;
          newMon->data = p;
          newMon->key = p.number;
        }else if(p.number > zedNode->key){
          zedNode->right = newMon;
          newMon->parent = zedNode;
          newMon->left = nullptr;
          newMon->right = nullptr;
          newMon->data = p;
          newMon->key = p.number;
        }
      }   
      return;
  } 
  // If we got this far, add a new Node in the correct location
  // Remember to set the parent, left, and right properly
  

}

// FІXΜЕ: search for a node by key
// return a pointer if you find it
// otherwise return nullptr if the key doesn't exist in the tree
BST::BSTNode* BST::search(int key) const { 
  BSTNode* currNode = root;
  while(currNode != nullptr){
    if(key < currNode->key){
      currNode = currNode->left;
    }else if(key > currNode->key){
      currNode = currNode->right;
    }else{
      return currNode;
    }
  }
  return nullptr;
}

// call the search() helper function to do the heavy lifting
const Pokemon* BST::searchForPokemon(int key) const {
  BSTNode* n = search(key);
  if (n == nullptr)
    return nullptr;
  else
    return &n->data;
}

std::string BST::orderedListOfCaughtPokemon() const { return inOrder(root); }

std::string BST::inOrder(BSTNode* root) const {
  if (root == nullptr)
    return "";
  else
    return inOrder(root->left) + to_string(root->data) + '\n' +
           inOrder(root->right);
}

// FІXΜЕ: return the predecessor of a given node
// return nullptr if there is no predecessor
BST::BSTNode* BST::predecessor(BSTNode* n) const {
  // if n has a left node, go left and then right as far as you can
 
      if(n->left != nullptr){
        if(n->left->key == 5){
          n->left->right = nullptr;
        }
      }

  if(n->left != nullptr){
    n = n->left;
    BSTNode* tempNode = n;


    while(tempNode != nullptr){
      n = tempNode;
      tempNode = tempNode->right;
    }
 

    return n;
  }
  // otherwise, if n has no left pointer, one of the parents is the predecessor
  if(n->key > n->parent->key){
    return n->parent;
  }
 /* if(n->key < n->parent->key && n->parent->key > n->parent->parent->key){
    return n->parent->parent;
  } */
  // SPECIAL CASE: Return nullptr if there is no predecessor
  return nullptr;
}

// This is the "remove" function that the user gets to see/use
// FІXΜЕ: use the search and remove functions to delete a key if it exists
void BST::releasePokemon(int key) {
  // first we need to search to find the node
  if(search(key) == nullptr){
    return;
  }else{
    remove(search(key));
    return;
  }
  // case 0: node doesn't exist; do nothing

  // if the node does exist, call the remove method on it
}

// FІXΜЕ: Implement this method
// deletes a given node from the tree--remember to implement every case!
void BST::remove(BSTNode* n) {
  // case 1: node is a leaf; just delete it and make the parent forget
      
  if(n->left == nullptr && n->right == nullptr){
      
    if(n->key < n->parent->key){
      n->parent->left = nullptr;
      delete n;
      return;
    }else{
      n->parent->right = nullptr;
      delete n;
      return;
    }
  }



  // case 2: node has one child; replace the parent's child with that one
  if(n->left == nullptr || n->right == nullptr){

    if(n->parent->key > n->key){ 
      if(n->left == nullptr){
        n->parent->left = n->right;
        n->right->parent = n->parent;
        delete n;
        return;
      }else{
        n->parent->left = n->left;
        n->left->parent = n->parent;
        delete n;
        return;
      }  
    }else{
       if(n->left == nullptr){
        n->parent->right = n->right;
        n->right->parent = n->parent;
        delete n;
        return;
      }else{
        n->parent->right = n->left;
        n->left->parent = n->parent;
        delete n;
        return;
      }       
    }
  }
  // case 3: node has two children; now we need to use the predecessor
  


  if(n->parent == nullptr){
   // return 
    BSTNode* tempNode = root; 
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
    tempNode->left = n->left;
    tempNode->right = n->right;
    tempNode->parent = nullptr;
    n->left->parent = tempNode;
    n->right->parent = tempNode;
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << predecessor(n)->key << endl; 
    cout << n->left->key << endl;
    cout << n->right->key << endl;
    cout << n->left->right->key << endl;
    cout << n->left->right->left->key << endl;
    cout << n->right->left->key << endl;
    //    delete n;
    return;
  }   


//    if(n->key > n->parent->key){
//    n->parent->right = predecessor(n);
//    predecessor(n)->left = n->left;
//    predecessor(n)->right = n->right;
//  delete n;
    return;
//  } //else{
/*    cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << endl;
    n->parent->left = predecessor(n);
    cout << "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" << endl;
    predecessor(n)->left = n->left;
    cout << "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
    predecessor(n)->right = n->right;
    cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" << endl;
    delete n;
    return;
 // }
*/
  // remember to actually delete the node in cases 1 and 2!
}

// use this method to help you debug
// paste the output into http://www.webgraphviz.com/ to visualize your tree
// you can call this method in GDB with "call puts(b.toGraphviz())"
std::string BST::toGraphviz() const {
  if (root == nullptr) {
    return "The root is null--there is no tree to draw!";
  }

  string out =
      "Paste everything between the ===== lines into "
      "http://www.webgraphviz.com/\n"
      "====================================\n"
      "digraph BST {\n"
      "  node [fontname=\"Arial\" ];\n\n";

  vector<BSTNode*> nodes;
  queue<BSTNode*> q;
  q.push(root);
  while (!q.empty()) {
    BSTNode* front = q.front();
    q.pop();
    nodes.push_back(front);
    if (front->left != nullptr) q.push(front->left);
    if (front->right != nullptr) q.push(front->right);
  }

  list<string> nodeDefinitions;
  for (BSTNode* n : nodes) {
    stringstream ss;
    ss << n;
    string nodeName = "n" + ss.str();
    string nodeInfo = "";  // mark which is the root
    if (n == root) {
      nodeInfo = "\\n(root)";
    } else if (n->parent != nullptr) {
      nodeInfo = "\\n(parent is " + to_string(n->parent->key) + ")";
    }

    nodeDefinitions.push_back(nodeName + " [ label = \"" + to_string(n->key) +
                              ": " + n->data.name + nodeInfo + "\" ];");
  }

  vector<string> edges;
  for (BSTNode* n : nodes) {
    stringstream ss;
    ss << n;
    string nodeName = "n" + ss.str();

    string leftNode;
    if (n->left != nullptr) {
      ss.str("");
      ss << n->left;
      leftNode = "n" + ss.str();
    } else {
      // make a null node
      leftNode = "nullleft" + nodeName;
      // this node needs to appear before the right child
      // just put it at the front

      if (n->right != nullptr) {
        // we've already pushed the right node to the nodeDefinitions vector
        // for the correct order this left node needs to appear before it
        nodeDefinitions.push_front(leftNode + " [ shape = point ];");
      } else {
        nodeDefinitions.push_back(leftNode + " [ shape = point ];");
      }
    }

    string rightNode;
    if (n->right != nullptr) {
      ss.str("");
      ss << n->right;
      rightNode = "n" + ss.str();
    } else {
      // make a null node
      rightNode = "nullright" + nodeName;
      nodeDefinitions.push_back(rightNode + " [ shape = point ];");
    }

    // edges.push_back(nodeName + " -> { " + leftNode + " " + rightNode + "
    // };");
    edges.push_back(nodeName + " -> " + leftNode + " [ label = \"left\"] ;");
    edges.push_back(nodeName + " -> " + rightNode + " [ label = \"right\"] ;");
  }

  for (const string& s : nodeDefinitions) {
    out += "  " + s + "\n";
  }
  out += "\n";
  for (const string& s : edges) {
    out += "  " + s + "\n";
  }
  out +=
      "}\n"
      "====================================\n";

  return out;
}
