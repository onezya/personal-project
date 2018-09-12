#pragma once
#include<iostream>
#include<queue>
#include<unordered_map>
#include<fstream>
#include<string>

using namespace std;

#define OUTWORD 0  // 5 DFA states
#define P1 1
#define P2 2
#define P3 3
#define VALIDWORD 4
#define ERROR 5

/* 
* Function name: Transition
* Description:
*	Sort method of Top 10 words vector.
*/
bool MySort(const pair<int, string>& word1, const pair<int, string>& word2);


/*
* Function name: Transition
* Description: 
*	State transition process in DFA(Deterministic Finite Automaton)
*	and extract the correct word into a string
* Parameter:
*	@state: current state
*	@input: current input
*	@word: when a legal word is detected, it is stored here.
* Return:
*	@int: new state
*/
int TransitionStoreWord(int state, char input, string & word);

/*
* Function name: InsertToHashTable
* Description: 
*	Insert legal words into the hash table. Be called in the
*	Transition() function
* Parameter:
*	@word: the legal word
* Return:
*	void
*/
void InsertToHashTable(string & word);

/*
* Function name: WordFrequency
* Description: 
*	Count the number of occurrences of each word in the file, stored into
*	a hash table. This function is a wrapper of Transition and InsertToHashTable
* Parameter:
*	@filename: File that need to be counted
* Return:
*	void
*/
void WordFrequency(char * filename);

/*
* Function name: TopTenWords
* Description:
*	Display 10 words with the highest frequency. 
* Parameter:
*	none
* Return:
*	int: Total count of top ten words
*/
int TopTenWords();