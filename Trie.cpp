#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>


// �������������� ����� ���� � ��� ����� ���������� ����������
TrieNode* getNewNode()
{
    // �������� ������ �� ����� ����
    struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = nullptr;
    }

    return pNode;
}


// �������
void insert(TrieNode* root, std::string key)
{
    struct TrieNode* tnode = root;

    for (int i = 0; i < key.length(); i++) {
        // 1. ����� ������ �� ������������ �����.
        int index = key[i] - 'a';

        // 2. ���������, ��� ��� ��������� ���� � ����� ��������
        if (!tnode->children[index]) {
            tnode->children[index] = getNewNode();  // 3. ��������� ���� �� ������� ������� ������� ����� ���� (��������� ���� � ������, ���� ��� ���)
        }
        // 4. ��������� �������� ���� ������ ��������� ��������
        tnode = tnode->children[index];
    }
    // 6. ���������� ���� ����� ����� ��� ���������� ����
    tnode->isEndOfWord = true;
}


// ����� ����� � ������
TrieNode* search(struct TrieNode* root, std::string key)
{
    TrieNode* node = root;

    // 4. ��������� � �.1, ���� � ����� ���� �������.
    for (int i = 0; i < key.length(); i++) {
        // 1. ����� ������ �� �������� �����.
        int index = key[i] - 'a';

        // 2. ���������, ���� ��� ��������� ���� � ����� ��������, ��������� ����� � ����������� ��������.
        if (!node->children[index]) {
            return nullptr;
        }
        // 3. ��������� �������� ���� �������� ���� �������� ����.
        node = node->children[index];
    }
    return node;
}


// ������� - �������� ��� ����������� ����, ��� ��������� ����� � ���� �������� ������.
// ��� �������� �� ���� ��������� �������� ��������� ���� root � 
// ���� ��� ����, �� ���������� false, � ��������� ������ � true.
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }
    return true;
}


// ����� ��� ����� � ������
void findAllWords(TrieNode* tnode, char buf[], int ind, std::vector<std::string>& arrWords)
{
    if (tnode != NULL) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (tnode->children[i] != NULL) {
                buf[ind] = 'a' + i;
                findAllWords(tnode->children[i], buf, ind + 1, arrWords);
            }
        }
        if (tnode->isEndOfWord) {
            buf[ind] = '\0';
            arrWords.push_back(buf);
        }
    }
}


// ������� ������ �� �����
void print(TrieNode* tnode, char* out, int index)
{
    if (tnode != NULL) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (tnode->children[i] != NULL) {
                out[index] = 'a' + i;
                print(tnode->children[i], out, index + 1);
            }
        }
        if (tnode->isEndOfWord) {
            out[index] = '\0';
            std::cout << out << std::endl;
        }
    }
}