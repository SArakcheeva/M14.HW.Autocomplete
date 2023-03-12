#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>


// Инициализируем новый узел и его листы начальными значениями
TrieNode* getNewNode()
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = nullptr;
    }

    return pNode;
}


// Вставка
void insert(TrieNode* root, std::string key)
{
    struct TrieNode* tnode = root;

    for (int i = 0; i < key.length(); i++) {
        // 1. Взять символ от вставляемого ключа.
        int index = key[i] - 'a';

        // 2. Проверить, что нет дочернего узла с таким символом
        if (!tnode->children[index]) {
            tnode->children[index] = getNewNode();  // 3. Присвоить узлу по индексу взятого символа новый узел (Вставляет ключ в дерево, если его нет)
        }
        // 4. Присвоить текущему узлу только созданный дочерний
        tnode = tnode->children[index];
    }
    // 6. Установить флаг конца слова для последнего узла
    tnode->isEndOfWord = true;
}


// Поиск ключа в дереве
TrieNode* search(struct TrieNode* root, std::string key)
{
    TrieNode* node = root;

    // 4. Повторять с п.1, пока в ключе есть символы.
    for (int i = 0; i < key.length(); i++) {
        // 1. Взять символ от искомого ключа.
        int index = key[i] - 'a';

        // 2. Проверить, если нет дочернего узла с таким символом, завершить поиск с результатом «неудача».
        if (!node->children[index]) {
            return nullptr;
        }
        // 3. Присвоить текущему узлу дочерний узел текущего узла.
        node = node->children[index];
    }
    return node;
}


// функция - помощник для определения того, что поддерево пусто и узел является листом.
// Она проходит по всем возможным дочерним элементам узла root и 
// если они есть, то возвращает false, в противном случае — true.
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }
    return true;
}


// Найти все слова в дереве
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


// Вывести дерево на экран
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