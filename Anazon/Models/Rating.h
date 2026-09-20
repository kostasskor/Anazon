#pragma once
#include <string>

class Rating
{
private:
	int score;
	int user_id;
	std::string comment;
public:
	Rating(int score, std::string comment, int user_id)
	{
		this->score = score;
		this->comment = comment;
		this->user_id = user_id;
	}
	int getScore()
	{
		return score;
	}
	std::string getComment()
	{
		return comment;
	}
	int getUserId()
	{
		return user_id;
	}
};