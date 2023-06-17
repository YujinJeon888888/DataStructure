//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int element;
//typedef struct TreeNode {
//	element key;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode* binary_tree_to_BST = NULL;
//
////��ȯ���� Ž�� �Լ�
//TreeNode* search(TreeNode* node, int key) {
//	if (node == NULL) return NULL;
//	if (key == node->key) return node;
//	else if (key < node->key)
//		return search(node->left, key);
//	else
//		return search(node->right, key);
//}
//
//TreeNode* newNode(int item) {
//	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
//	temp->key = item;
//	temp->left = temp->right = NULL;
//	return temp;
//}
//
//TreeNode* insert_node(TreeNode* node, int key) {
//	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
//	if (node == NULL) return newNode(key);
//
//	//�׷��� ������ ��ȯ������ Ʈ���� ��������. 
//	if (key < node->key)
//		node->left = insert_node(node->left, key);
//	else if (key > node->key)
//		node->right = insert_node(node->right, key);
//
//	//����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
//	return node;
//}
//
//TreeNode* min_value_node(TreeNode* node) {
//	TreeNode* current = node;
//
//	//�� ���� �ܸ� ��带 ã���� ������
//	while (current->left != NULL)
//		current = current->left;
//
//	return current;
//}
//
////���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
////���ο� ��Ʈ ��带 ��ȯ�Ѵ�. 
//TreeNode* delete_node(TreeNode* root, int key) {
//	if (root == NULL) return root;
//
//	//���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
//	if (key < root->key)
//		root->left = delete_node(root->left, key);
//	//���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
//	else if (key > root->key)
//		root->right = delete_node(root->right, key);
//	//Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
//	else {
//		//�ڽ� 1�� ��� �Ǵ� �ܸ��� ���
//		if (root->left == NULL) {
//			TreeNode* temp = root->right;
//			free(root);
//			return temp;
//		}
//		else if (root->right == NULL) {
//			TreeNode* temp = root->left;
//			free(root);
//			return temp;
//		}
//		//�ڽ� 2���� ���
//		TreeNode* temp = min_value_node(root->right);
//
//		//���� ��ȸ�� �İ� ��带 �����Ѵ�. 
//		root->key = temp->key;
//		//���� ��ȸ�� �İ� ��带 �����Ѵ�. 
//		root->right = delete_node(root->right, temp->key);
//	}
//	return root;
//}
//
////���� ��ȸ ����Ʈ
//void printInorder(TreeNode* root) {
//	if (root) {
//		printInorder(root->left); //���� ����Ʈ�� ��ȸ
//		printf("[%d] ", root->key);//��� �湮
//		printInorder(root->right);//������ ����Ʈ�� ��ȸ
//	}
//}
//
////���� ��ȸ
//void inorder(TreeNode* root) {
//	if (root) {
//		inorder(root->left); //���� ����Ʈ�� ��ȸ
//		printf("[%d] ", root->key);//��� �湮
//		inorder(root->right);//������ ����Ʈ�� ��ȸ
//	}
//}
//
////����Ʈ���� ����Ž��Ʈ����
//void binaryTreeToBST(TreeNode* root) {
//	if (root) {
//		binaryTreeToBST(root->left); //���� ����Ʈ�� ��ȸ
//
//		//������ȸ�ϸ� ���湮�ϰ�, �� ���湮�� ���� ����Ž��Ʈ�� insert_node��
//		binary_tree_to_BST = insert_node(binary_tree_to_BST, root->key);
//
//		binaryTreeToBST(root->right);//������ ����Ʈ�� ��ȸ
//	}
//}
//
//int main(void) {
//	TreeNode* root = NULL;
//
//	root = newNode(10);
//	root->left = newNode(30);
//	root->right = newNode(15);
//	root->left->left = newNode(20);
//	root->right->right = newNode(5);
//
//	binaryTreeToBST(root);
//
//	printf("Following is Inorder Traversal of the converted BST :  \n");
//
//	root = binary_tree_to_BST;//�ڵ��߰�(��Ʈ�� �ٲ� ����ü ����)
//
//	printInorder(root);
//
//	return 0;
//}