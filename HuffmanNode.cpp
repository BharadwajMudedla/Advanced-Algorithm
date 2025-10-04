#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct HuffmanNode {
    char character;         
    int frequency;          
    HuffmanNode *left;      
    HuffmanNode *right;     

    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

struct NodeComparator {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency; 
    }
};

void generateCodes(HuffmanNode* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << code << " ";
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

void buildHuffmanTree(const vector<char>& chars, const vector<int>& freqs) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeComparator> minHeap;
    for (size_t i = 0; i < chars.size(); i++) {
        minHeap.push(new HuffmanNode(chars[i], freqs[i]));
    }
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        HuffmanNode* merged = new HuffmanNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }
    generateCodes(minHeap.top(), "");
    cout << endl;
}
int main() {
    string input = "abcdef";
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};
    vector<char> characters(input.begin(), input.end());
    buildHuffmanTree(characters, frequencies);
    return 0;
}
