# Huff Man Code :bowtie:
## 1. Huff Man Algorithm 
![David A. Huffman](davidhuffman-wm.jpg)
*  It's an algorithm developed by **David A. Huffman**  while he was a  student at MIT, and published in the **1952** paper **"A Method for the Construction of Minimum-Redundancy Codes"**


* Huffman coding is a lossless data compression algorithm. 
* The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. 
*  The most frequent character gets the smallest code and the least frequent character gets the largest code.
* In this algorithm we use tree , maps and priority queue .

There are mainly two major parts in Huffman Coding...
1) Build a Huffman Tree from input characters.
2) Traverse the Huffman Tree and assign codes to characters.

for implementation we use the struct node ..
```c++
struct Node
    {
        char data;
        int freq;
        Node *left;
        Node *right;
        Node(char data, int freq)
        {
            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
    };
```

----------------------------
## 2. Huff Man Compression

### **Steps to build Huffman Tree** :evergreen_tree:

1. Create a leaf node for each unique character and build a min heap of all leaf nodes 
     *  Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root.
2.  Extract two nodes with the minimum frequency from the min heap.
3. Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.

4. Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.