#include <iostream>
using namespace std;

void getjudgeD(double &, int);                                   //getjudgeD = getjudgedata
double calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main()
{
	
	double score[5];
    int judgeNum = 1;
    double scoreMean;
    
    for(int i = 0 ; i < 5 ; i++){	
	getjudgeD(score[i],judgeNum);
	judgeNum++;
    }

	scoreMean = calcScore(score[0], score[1], score[2], score[3], score[4]);
	cout << "Final Score : " << scoreMean << endl;


}

void getjudgeD(double &score ,int judgeNum)
{
	
		cout << "Judge #"<< judgeNum <<" - Please enter a score between 0.0 and 10.0 : " << endl;
		cin >> score;
		while (score < 0 || score > 10)
		{
			cout << "Score must be between 0.0 and 10.0 : ";
			cin >> score;
		}
	
}

double calcScore(double score1, double score2, double score3, double score4, double score5)
{
	double lowest,
	       highest,
	       mean;

	
	lowest = findLowest(score1, score2, score3, score4, score5);

	
	highest = findHighest(score1, score2, score3, score4, score5);
	
	
	mean = (score1 + score2 + score3 + score4 + score5 - highest - lowest) / 3;

	return mean;
}


double findLowest(double score1, double score2, double score3, double score4, double score5)
{
	
  if (score1 < score2 && score1 < score3 && score1 < score4 && score1 < score5)
  {
    return score1;
  }
  else if (score2 < score1 && score2 < score3 && score2 < score4 && score2 < score5)
  {
    return score2;
  }
  else if (score3 < score2 && score3 < score1 && score3 < score4 && score3 < score5)
  {
    return score3;
  }
  else if (score4 < score2 && score4 < score3 && score4 < score1 && score4 < score5)
  {
    return score4;
  }
  else
  {
    return score5;  
  }
}

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
	
  if (score1 > score2 && score1 > score3 && score1 > score4 && score1 > score5)
  {
    return score1;
  }
  else if (score2 > score1 && score2 > score3 && score2 > score4 && score2 > score5)
  {
    return score2;
  }
  else if (score3 > score2 && score3 > score1 && score3 > score4 && score3 > score5)
  {
    return score3;
  }
  else if (score4 > score2 && score4 > score3 && score4 > score1 && score4 > score5)
  {
    return score4;
  }
  else
  {
    return score5;  
  }
}

