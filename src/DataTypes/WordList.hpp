//
// Created by César B. on 5/1/2024.
//

#pragma once

#include <string>
#include <vector>

namespace DataTypes
{	struct WordScorePair
	{	std::wstring word;
		int score;
		bool operator==(WordScorePair other) const;
	};

	typedef std::vector<WordScorePair> EvaluatedWords_t;

	class WordList
	{	public:
			WordList() = delete;
			WordList(std::string filePath);
			void RemoveDuplicates();
			void CountScores();
			void SortByScores();
			inline EvaluatedWords_t GetWords() { return words; }
		private:
			EvaluatedWords_t words;
	};
}
