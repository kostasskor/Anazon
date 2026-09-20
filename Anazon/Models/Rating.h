#pragma once
#include <string>

using namespace std;

class Rating
{
private:
	int score;
	int user_id;
	string comment;
public:
	Rating(int score, string comment, int user_id)
	{
		this->score = score;
		this->comment = comment;
		this->user_id = user_id;
	}
	int getScore()
	{
		return score;
	}
	string getComment()
	{
		return comment;
	}
	int getUserId()
	{
		return user_id;
	}
};