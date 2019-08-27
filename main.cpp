#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *parentNode;
    struct TreeNode *rightNode;
    struct TreeNode *leftNode;
}*treePtr;

treePtr rootNode = NULL, currentNode = NULL;

void InsertTreeData(int nodeData){
         treePtr newNode = new TreeNode;
         newNode->data = nodeData;
         newNode->leftNode = NULL;
         newNode->rightNode = NULL;
         if(rootNode == NULL){
            newNode->parentNode = NULL;
            rootNode = newNode;
         }
         else{
            treePtr treverser = rootNode;
            while(treverser != NULL){
                if(treverser->data <= nodeData && treverser->rightNode == NULL){
                   newNode->parentNode = treverser;
                   treverser->rightNode = newNode;
                   treverser = newNode;
                   break;
                }
                else if(treverser->data <= nodeData && treverser->rightNode != NULL){
                    treverser = treverser->rightNode;
                }
                if (treverser->data > nodeData && treverser->leftNode == NULL){
                    newNode->parentNode = treverser;
                    treverser->leftNode = newNode;
                    treverser = newNode;
                    break;
                }
                else if(treverser->data > nodeData && treverser->leftNode != NULL){
                    treverser = treverser->leftNode;
                }
            }
         }
}

void TraverseInorder(treePtr treeNode) {
        if(treeNode == NULL){
            return;
        }
        else{
            TraverseInorder(treeNode->leftNode);
            cout << treeNode->data << " ";
            TraverseInorder(treeNode->rightNode);
        }
}

void TraversePreorder(treePtr treeNode){
         if(treeNode == NULL){
            return;
         }
         else{
            cout << treeNode->data << " ";
            TraversePreorder(treeNode->leftNode);
            TraversePreorder(treeNode->rightNode);
         }
}

void TraversePostorder(treePtr treeNode){
          if(treeNode == NULL){
            return;
          }
          else{
            TraversePostorder(treeNode->leftNode);
            TraversePostorder(treeNode->rightNode);
            cout << treeNode->data << " ";
          }
}

void AllLevelNodes(treePtr levelNodes, int level){
         int levelChecker = 1;
         if(level == 1){
            cout << levelNodes->data;
            return;
         }
         else{
            while(levelNodes != NULL){
                 levelChecker++;
                 if(levelChecker == level){
                    if(levelNodes->leftNode != NULL){
                       cout << levelNodes->leftNode->data << " ";
                       if(levelNodes->rightNode != NULL){
                        cout << levelNodes->rightNode->data << " ";
                       }
                    }
                    if(levelNodes->parentNode->rightNode->leftNode != NULL || levelNodes->parentNode->rightNode->rightNode != NULL){
                       while(levelNodes->parentNode != NULL){
                        levelNodes = levelNodes->parentNode;
                        if(levelNodes->rightNode->leftNode != NULL){
                            cout << levelNodes->rightNode->leftNode->data << " ";
                        }
                        if(levelNodes->rightNode->rightNode != NULL){
                            cout << levelNodes->rightNode->rightNode->data << " ";
                        }
                    }
                    }
                 }
                 levelNodes = currentNode->rightNode;
            }
            if(level > 2){
                 levelNodes = rootNode;
                 levelChecker = 1;
                 while(levelNodes != NULL){
                   levelChecker++;
                        if(levelChecker == level){
                            if(levelNodes->rightNode != NULL){
                                cout << levelNodes->rightNode->data << " ";
                                if(levelNodes->leftNode != NULL){
                                    cout << levelNodes->leftNode->data << " ";
                                }
                            }
                            if(levelNodes->parentNode->leftNode->leftNode != NULL || levelNodes->parentNode->leftNode->rightNode != NULL){
                               while(levelNodes->parentNode->parentNode != NULL){
                                  levelNodes = levelNodes->parentNode;
                                 if(levelNodes->leftNode->leftNode != NULL){
                                   cout << levelNodes->leftNode->leftNode->data << " ";
                                 }
                                 if(levelNodes->leftNode->rightNode != NULL){
                                  cout << levelNodes->leftNode->rightNode->data << " ";
                                 }
                                }
                            }
                        }
                        if(currentNode == NULL){
                           levelNodes = levelNodes->rightNode;
                        }
                        else{
                            levelNodes = currentNode->leftNode;
                        }
                 }
            }
         }
}

void ReverseOrderTree(treePtr reverseTree){
       if(reverseTree == NULL){return;}
       if(reverseTree->leftNode == NULL && reverseTree->rightNode == NULL){
          cout << reverseTree->data << " ";
        return;
       }
       ReverseOrderTree(reverseTree->rightNode);
       cout << reverseTree->data << " ";
       ReverseOrderTree(reverseTree->leftNode);
}

int main()
{
    int choice;
    do{
        cout << "Press 1 to Insert Data in tree" << endl;
        cout << "Press 2 to traverse tree Inorder." << endl;
        cout << "Press 3 to traverse tree in Preorder." << endl;
        cout << "Press 4 to traverse tree in Postorder." << endl;
        cout << "Press 5 to See the all node of a level." << endl;
        cout << "Press 6 to print Tree in Reverse Order." << endl;
        cout << "Press 7 to exit the Program." << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                int nodeData;
                cout << "Enter node data:";
                cin >> nodeData;
                InsertTreeData(nodeData);
                break;
            }
            case 2:{
                cout << "Traverse Inorder:";
                TraverseInorder(rootNode);
                cout << endl;
                break;
            }
            case 3:{
                cout << "Traverse Preorder:";
                 TraversePreorder(rootNode);
                 cout << endl;
                 break;
            }
            case 4:{
                 cout << "Traverse Postorder:";
                 TraversePostorder(rootNode);
                 cout << endl;
                 break;
            }
            case 5:{
                int level;
                 cout << "Enter Wanted level:";
                 cin >> level;
                 cout << "Nodes of this level: ";
                 AllLevelNodes(rootNode, level);
                 cout << endl;
                 break;
            }
            case 6:{
                cout << "Tree Nodes in Reverse Order:";
                  ReverseOrderTree(rootNode);
                  cout << endl;
                  break;
            }
            case 7:{
                cout << "Program end." << endl;
                break;
            }
            default:{
               cout << "You entered the wrong choice." << endl;
            }
        }
    }while(choice != 7);
    return 0;
}
