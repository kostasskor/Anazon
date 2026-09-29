#pragma once
#include <string>

class Rating
{
private:
	int score;
	int userId;
	std::string comment;
public:
	Rating(int score, const std::string& comment, int user_id)
	{
		this->score = score;
		this->comment = comment;
		this->userId = user_id;
	}
	static bool isValidScore(int score)
	{
		return score >= 1 && score <= 5;
	}
	int getScore() const
	{
		return score;
	}
	const std::string& getComment() const
	{
		return comment;
	}
	int getUserId() const
	{
		return userId;
	}
};