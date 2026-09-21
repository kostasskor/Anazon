#pragma once
#include <string>

class Rating
{
private:
	int score;
	int user_id;
	std::string comment;
public:
	Rating(int score, const std::string& comment, int user_id)
	{
		this->score = score;
		this->comment = comment;
		this->user_id = user_id;
	}
	const int getScore() const
	{
		return score;
	}
	const std::string& getComment() const
	{
		return comment;
	}
	const int getUserId() const
	{
		return user_id;
	}
};