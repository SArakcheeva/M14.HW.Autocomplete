/*
 * �������������� ���������� ����� �� ���������� ��������� �������
 * 
 * ���������� ��������� ������, ������� ����� ��������, 
 * � ����� ��������� �������� � ���������� ���������� �������� ���� �� ��������� �����.
 * ���������� ����� ��������������� ��� �� ������� ����� - ���� �������, ��� � ����� ������ ��������.
 * ����� ������� ��������� �� ������ ����������� � ����� ������ ����� �� ������������.
*/

#include <iostream>
#include <string>
#include <conio.h> // ���������� getch
#include "Trie.h"


void BasicFunction()
{
	// Input keys (use only 'a' through 'z' and lower case)
	std::string keys[] = { "hair", "hand",
							"hello",
							"hi", "history",
							"home", "holiday", "honey", "hotel",
							"hungry", "hypocrite" };
	int n = sizeof(keys) / sizeof(keys[0]);

	struct TrieNode* root = getNewNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	std::cout << "Dictionary:" << std::endl;
	char outt[ALPHABET_SIZE];
	print(root, outt, 0);
	std::cout << "---------------------------------------------------" << std::endl
			  << "Use keys up - down to select a variant of the word." << std::endl
			  << "When the selection is complete, press Enter." << std::endl
			  << "Press Esc to exit the program." << std::endl
			  << "---------------------------------------------------" << std::endl
			  << "Enter a word starts with 'h' and lower case" << std::endl;


	// ���� �� ������ ������� Esc (escape)
	int end = 1;
	while (end != 27)
	{
		std::string prefix = "";
		std::getline(std::cin >> std::ws, prefix);

		struct TrieNode* tnode = getNewNode();

		// ������ ���� �� ��������� ������������� ��������
		tnode = search(root, prefix);

		// ������ ��� ����� � ���������, ������ �������� �������� ��������� ���������� �������  
		char buf[ALPHABET_SIZE];
		int ind = 0;  
		std::vector<std::string> arrWords;
		findAllWords(tnode, buf, ind, arrWords);

		// ������� ��������� ����������� ����
		int wordsCount = arrWords.size();
		if (wordsCount == 0) {
			std::cout << "The word was not found in the dictionary";
		}
		else {
			int posWord = 0; // ����� ����� � arrWords
			std::cout << prefix + arrWords[posWord];

			int k = 0; // ������� ���������� (���)
			while (k != 13) {
				k = _getch();
				// ���� ��������� ���� > 1
				if (wordsCount > 1) {
					int k2 = _getch();
					switch (k2)
					{
					case 72: // ������� �����
						posWord--;
						if (posWord < 0) {
							posWord = 0;
						}
						break;
					case 80: // ������� ����
						posWord++;
						if (posWord > wordsCount - 1) {
							posWord = wordsCount - 1;
						}
						break;
					}
				}
				std::cout << "\33[2K\r";// ������� ��������� ���������� �� ����� ������
				std::cout << prefix + arrWords[posWord];
			}
		}
		std::cout << std::endl;

		end = _getch();
	}
}


int main()
{
	BasicFunction();
	
	return 0;
}