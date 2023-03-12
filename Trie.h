#pragma once
#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

// Структура узла дерева
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];

    bool isEndOfWord;   // isEndOfWord - true, если ключ является концом слова
};

// инициализируем новый узел и его листы начальными значениями
TrieNode* getNewNode();

// вставка ключа
void insert(TrieNode* root, std::string key);

// поиск ключа в дереве
TrieNode* search(struct TrieNode* root, std::string key);

// определение того, что поддерево пусто и узел является листом.
bool isEmpty(TrieNode* root);

// поиск всех слов в дереве с заданным корнем
void findAllWords(TrieNode* tnode, char buf[], int ind, std::vector<std::string>& arrWords);

// вывод всех дочерних элементов данного узла
void print(TrieNode* tnode, char* out, int index);
