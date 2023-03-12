#pragma once
#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

// ��������� ���� ������
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];

    bool isEndOfWord;   // isEndOfWord - true, ���� ���� �������� ������ �����
};

// �������������� ����� ���� � ��� ����� ���������� ����������
TrieNode* getNewNode();

// ������� �����
void insert(TrieNode* root, std::string key);

// ����� ����� � ������
TrieNode* search(struct TrieNode* root, std::string key);

// ����������� ����, ��� ��������� ����� � ���� �������� ������.
bool isEmpty(TrieNode* root);

// ����� ���� ���� � ������ � �������� ������
void findAllWords(TrieNode* tnode, char buf[], int ind, std::vector<std::string>& arrWords);

// ����� ���� �������� ��������� ������� ����
void print(TrieNode* tnode, char* out, int index);
