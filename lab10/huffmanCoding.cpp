#include "huffmanCoding.h"
#include <queue> // for priority_queue
using namespace std;

// Pure virtual destructors are required to have an implementation
// in C++ for no good reason.
// The line below is equivalent to: HTreeNode::~HTreeNode() {}, 
// but it's more hip to do it this way.
HTreeNode::~HTreeNode() = default;

// Eventually, we're going to put HTreeNode*s inside a priority_queue,
// so we need to tell the pq how to compare those pointers.
// We want to prefer HTreeNodes with smaller frequencies, so 
// we'll use the following custom comparison class.
class CompareHTreeNodePointer {
public:
  bool operator()(HTreeNode* p1, HTreeNode* p2) {
    // FІXΜЕ: return true when p2's frequency is smaller than p1's
    // (it's backwards because std::priority_queue is backwards)
    return p2->getFrequency() < p1->getFrequency();
  }
};

// FІXΜЕ: implement the constructor to build the tree
HuffmanCoding::HuffmanCoding(std::ifstream& ifs){
  buildTree(ifs);
}
// FІXΜЕ: implement the destructor to remove the tree
HuffmanCoding::~HuffmanCoding(){
  delete treeRoot;
}
// FІXΜЕ: implement the buildCharFreqTable method
// This is BuildCharacterFrequencyTable from your book
// We'll use an ifstream instead of a string
  // The table is a member variable, so it's already constructed
  // and there's no need to return it. You just have to add to it.
void HuffmanCoding::buildCharFreqTable(std::ifstream& ifs){

  char c;
  while(ifs.get(c)){
    if(charFreqTable.count(c) == 0)
      charFreqTable.emplace(c, 1);
    else
      charFreqTable.at(c)++;
  }
}
// FІXΜЕ: implement the buildTree method
// This is the HuffmanBuildTree from your book
  // we want to compare HTreeNode*s using frequency, with the smallest
  // frequencies having the largest priority
void HuffmanCoding::buildTree(std::ifstream& ifs){
  buildCharFreqTable(ifs);

  priority_queue<HTreeNode*, vector<HTreeNode*>, CompareHTreeNodePointer> nodes;

  for(const auto& charFreqPair : charFreqTable){
    nodes.push(new LeafNode(charFreqPair.second, charFreqPair.first));
  }
  while (nodes.size() > 1){
    HTreeNode* left = nodes.top();
    nodes.pop();
    HTreeNode* right = nodes.top();
    nodes.pop();
    int freqSum = left->getFrequency() + right->getFrequency();

    HTreeNode* parent = new InternalNode(freqSum, left, right);
    nodes.push(parent);
  }

  treeRoot = nodes.top();
} 
// FІXΜЕ: implement the getCodes method
// calls getCodesRecursive with the correct starting values
std::map<char, std::string> HuffmanCoding::getCodes(){
  map<char, string> codes;
  getCodesRecursive(treeRoot, "", codes);
  return codes;
}
// FІXΜЕ: implement the getCodesRecursive method
// This is HuffmanGetCodes from your book
void HuffmanCoding::getCodesRecursive(HTreeNode* node, std::string prefix, std::map<char, std::string>& output){
  if(node->isLeaf()){
    output.emplace(node->getCharacter(), prefix);
  }else{
    getCodesRecursive(node->getLeft(), prefix + "0", output);
    getCodesRecursive(node->getRight(), prefix + "1", output);
  }
}
// FІXΜЕ: implement the compress method
// This is HuffmanCompress from your book
  // go back to the beginning of the file using:

std::string HuffmanCoding::compress(const std::map<char, std::string>& codes, std::ifstream& ifs){
  ifs.clear();
  ifs.seekg(0);

  string res = "";
  char c;
  while(ifs.get(c)){
    res += codes.at(c);
  }

  return res;
}
