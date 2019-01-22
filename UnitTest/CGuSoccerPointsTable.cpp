// Unit test of show the point table.
// Author Gu Wenwei.
// Test Data from Chinese Super League, season 2018, Round 1-8.
// Test date 2018-05-01
// Test Result Ok.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Team 
struct Team
{
	int iTeamID; //unique
	string strTeamName;
};

//数据结构
//class Dataset (比赛)
//赛季  轮次 时间 主队 比分 客队 (让球(全场 半场))  (大小(全场 半场))  (分析) 半场比分
struct Dataset 
{
    string strSeason;
    int iRound;
    string strStartTime;
    Team homeTeam;
	Team awayTeam;
	string strReserve1;
	string strReserve2;
	string strReserve3;
	string strReserve4;
	string strReserve5;
	int iHalftimeHomeTeamScore;
	int iHalftimeAwayTeamScore;
	int iFulltimeHomeTeamScore;
	int iFulltimeAwayTeamScore;
};

//积分榜
//排名 球队名称 赛 胜 平 负 得 失 净 胜% 平%  负% 均得 均失 积分 近六轮
//主场积分 客场积分 半场总积分 半场主场几分 半场客场积分  (这些没有近六轮)
struct TableEntry 
{
	Team team;
	int iMatchs;
	int iWin;
	int iDraw;
	int iLose;
	int iGoal;
	int iAgainstGoal;
	int iDiff;
	int iPoints;
};

int main() 
{
	// form Teams
	Team team1 = {1, "Beijing Guoan"};
	Team team2 = {2, "Beijing Renhe"};
	Team team3 = {3, "Changchun Yatai"};
	Team team4 = {4, "Chongqin Siwei"};
	Team team5 = {5, "Dalian Yifang"};
	Team team6 = {6, "Guangzhou Evergrande"};
	Team team7 = {7, "Guangzhou Fuli"};
	Team team8 = {8, "Guizhou Hengfeng"};
	Team team9 = {9, "Hebei Huaxia"};
	Team team10 = {10, "Henan Jianye"};
	Team team11 = {11, "Jiangsu Suning"};
	Team team12 = {12, "Shandong Luneng"};
	Team team13 = {13, "Shanghai Shanggang"};
	Team team14 = {14, "Shanghai Shenhua"};
	Team team15 = {15, "Tianjin Quanjian"};
	Team team16 = {16, "Tianjin Taida"};

	// the whole Datasets
	vector<vector<Dataset>> vecDatasetsTotal;

	// initialization of the Match Dataset vector (Round 1 - Round 8)
	// round 1
	{
		vector<Dataset> vecDatasetsRound1;
		Dataset dataset1 = {"2018", 1, "2018-03-02-13:35", team10, team15, "", "", "", "", "", 0, 1, 0, 4};
		Dataset dataset2 = {"2018", 1, "2018-03-02-13:35", team14, team3, "", "", "", "", "", 1, 0, 1, 1};
		Dataset dataset3 = {"2018", 1, "2018-03-02-13:35", team6, team7, "", "", "", "", "", 3, 2, 4, 5};
		Dataset dataset4 = {"2018", 1, "2018-03-03-09:30", team4, team2, "", "", "", "", "", 1, 0, 1, 0};
		Dataset dataset5 = {"2018", 1, "2018-03-03-13:35", team16, team9, "", "", "", "", "", 1, 0, 1, 1};
		Dataset dataset6 = {"2018", 1, "2018-03-03-13:35", team13, team5, "", "", "", "", "", 3, 0, 8, 0};
		Dataset dataset7 = {"2018", 1, "2018-03-04-09:30", team8, team11, "", "", "", "", "", 1, 2, 1, 3};
		Dataset dataset8 = {"2018", 1, "2018-03-04-13:35", team12, team1, "", "", "", "", "", 2, 0, 3, 0};
		vecDatasetsRound1.push_back(dataset1);
		vecDatasetsRound1.push_back(dataset2);
		vecDatasetsRound1.push_back(dataset3);
		vecDatasetsRound1.push_back(dataset4);
		vecDatasetsRound1.push_back(dataset5);
 		vecDatasetsRound1.push_back(dataset6);
    	vecDatasetsRound1.push_back(dataset7);
    	vecDatasetsRound1.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound1);
    }

	// round 2
	{
		vector<Dataset> vecDatasetsRound2;
		Dataset dataset1 = {"2018", 2, "2018-03-09-13:35", team6, team3, "", "", "", "", "", 0, 0, 5, 0};
		Dataset dataset2 = {"2018", 2, "2018-03-10-09:30", team15, team2, "", "", "", "", "", 0, 1, 1, 2};
		Dataset dataset3 = {"2018", 2, "2018-03-10-13:35", team12, team4, "", "", "", "", "", 1, 0, 2, 0};
		Dataset dataset4 = {"2018", 2, "2018-03-10-13:35", team7, team5, "", "", "", "", "", 0, 0, 2, 0};
		Dataset dataset5 = {"2018", 2, "2018-03-10-13:35", team14, team13, "", "", "", "", "", 0, 1, 0, 2};
		Dataset dataset6 = {"2018", 2, "2018-03-11-09:30", team8, team9, "", "", "", "", "", 0, 1, 2, 3};
		Dataset dataset7 = {"2018", 2, "2018-03-11-13:35", team11, team1, "", "", "", "", "", 0, 1, 1, 2};
		Dataset dataset8 = {"2018", 2, "2018-03-11-13:35", team10, team16, "", "", "", "", "", 1, 0, 1, 0};
		vecDatasetsRound2.push_back(dataset1);
		vecDatasetsRound2.push_back(dataset2);
		vecDatasetsRound2.push_back(dataset3);
		vecDatasetsRound2.push_back(dataset4);
		vecDatasetsRound2.push_back(dataset5);
 		vecDatasetsRound2.push_back(dataset6);
    	vecDatasetsRound2.push_back(dataset7);
    	vecDatasetsRound2.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound2);
    }

	// round 3
	{
		vector<Dataset> vecDatasetsRound3;
		Dataset dataset1 = {"2018", 3, "2018-03-16-13:35", team5, team1, "", "", "", "", "", 0, 2, 0, 3};
		Dataset dataset2 = {"2018", 3, "2018-03-17-09:30", team9, team12, "", "", "", "", "", 1, 1, 1, 2};
		Dataset dataset3 = {"2018", 3, "2018-03-17-13:35", team4, team11, "", "", "", "", "", 2, 1, 4, 1};
		Dataset dataset4 = {"2018", 3, "2018-03-18-09:30", team3, team2, "", "", "", "", "", 1, 1, 1, 1};
		Dataset dataset5 = {"2018", 3, "2018-03-18-09:30", team7, team13, "", "", "", "", "", 2, 3, 2, 5};
		Dataset dataset6 = {"2018", 3, "2018-03-18-13:35", team8, team14, "", "", "", "", "", 0, 0, 0, 1};
		Dataset dataset7 = {"2018", 3, "2018-03-18-13:35", team6, team10, "", "", "", "", "", 1, 0, 1, 0};
		Dataset dataset8 = {"2018", 3, "2018-03-18-13:35", team16, team15, "", "", "", "", "", 1, 0, 3, 2};
		vecDatasetsRound3.push_back(dataset1);
		vecDatasetsRound3.push_back(dataset2);
		vecDatasetsRound3.push_back(dataset3);
		vecDatasetsRound3.push_back(dataset4);
		vecDatasetsRound3.push_back(dataset5);
 		vecDatasetsRound3.push_back(dataset6);
    	vecDatasetsRound3.push_back(dataset7);
    	vecDatasetsRound3.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound3);
    }

	// round 4
	{
		vector<Dataset> vecDatasetsRound4;
		Dataset dataset1 = {"2018", 4, "2018-03-30-13:35", team13, team4, "", "", "", "", "", 2, 1, 2, 1};
		Dataset dataset2 = {"2018", 4, "2018-03-30-13:35", team15, team6, "", "", "", "", "", 0, 0, 0, 1};
		Dataset dataset3 = {"2018", 4, "2018-03-31-09:30", team3, team7, "", "", "", "", "", 0, 0, 1, 2};
		Dataset dataset4 = {"2018", 4, "2018-03-31-13:35", team1, team2, "", "", "", "", "", 1, 0, 4, 0};
		Dataset dataset5 = {"2018", 4, "2018-03-31-13:35", team10, team5, "", "", "", "", "", 1, 1, 1, 1};
		Dataset dataset6 = {"2018", 4, "2018-03-31-13:35", team14, team9, "", "", "", "", "", 0, 0, 4, 2};
		Dataset dataset7 = {"2018", 4, "2018-04-01-09:30", team12, team8, "", "", "", "", "", 0, 1, 0, 2};
		Dataset dataset8 = {"2018", 4, "2018-04-01-13:35", team11, team16, "", "", "", "", "", 0, 0, 2, 1};
		vecDatasetsRound4.push_back(dataset1);
		vecDatasetsRound4.push_back(dataset2);
		vecDatasetsRound4.push_back(dataset3);
		vecDatasetsRound4.push_back(dataset4);
		vecDatasetsRound4.push_back(dataset5);
 		vecDatasetsRound4.push_back(dataset6);
    	vecDatasetsRound4.push_back(dataset7);
    	vecDatasetsRound4.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound4);
    }

	// round 5
	{
		vector<Dataset> vecDatasetsRound5;
		Dataset dataset1 = {"2018", 5, "2018-04-06-13:35", team1, team16, "", "", "", "", "", 1, 1, 1, 1};
		Dataset dataset2 = {"2018", 5, "2018-04-06-13:35", team7, team11, "", "", "", "", "", 0, 0, 0, 2};
		Dataset dataset3 = {"2018", 5, "2018-04-07-09:30", team5, team4, "", "", "", "", "", 1, 0, 2, 2};
		Dataset dataset4 = {"2018", 5, "2018-04-07-13:35", team9, team3, "", "", "", "", "", 1, 0, 2, 1};
		Dataset dataset5 = {"2018", 5, "2018-04-08-09:30", team2, team14, "", "", "", "", "", 0, 1, 0, 2};
		Dataset dataset6 = {"2018", 5, "2018-04-08-13:35", team6, team12, "", "", "", "", "", 1, 0, 1, 0};
		Dataset dataset7 = {"2018", 5, "2018-04-08-13:35", team8, team15, "", "", "", "", "", 0, 1, 0, 1};
		Dataset dataset8 = {"2018", 5, "2018-04-08-13:35", team10, team13, "", "", "", "", "", 1, 2, 1, 2};
		vecDatasetsRound5.push_back(dataset1);
		vecDatasetsRound5.push_back(dataset2);
		vecDatasetsRound5.push_back(dataset3);
		vecDatasetsRound5.push_back(dataset4);
		vecDatasetsRound5.push_back(dataset5);
 		vecDatasetsRound5.push_back(dataset6);
    	vecDatasetsRound5.push_back(dataset7);
    	vecDatasetsRound5.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound5);
    }

	// round 6
	{
		vector<Dataset> vecDatasetsRound6;
		Dataset dataset1 = {"2018", 6, "2018-04-13-12:00", team14, team6, "", "", "", "", "", 0, 0, 2, 2};
		Dataset dataset2 = {"2018", 6, "2018-04-13-13:35", team15, team11, "", "", "", "", "", 1, 0, 1, 1};
		Dataset dataset3 = {"2018", 6, "2018-04-13-14:00", team13, team9, "", "", "", "", "", 1, 0, 2, 0};
		Dataset dataset4 = {"2018", 6, "2018-04-14-09:30", team2, team8, "", "", "", "", "", 1, 1, 2, 1};
		Dataset dataset5 = {"2018", 6, "2018-04-14-09:30", team16, team7, "", "", "", "", "", 2, 1, 2, 1};
		Dataset dataset6 = {"2018", 6, "2018-04-14-13:35", team12, team5, "", "", "", "", "", 1, 0, 2, 0};
		Dataset dataset7 = {"2018", 6, "2018-04-15-09:30", team3, team10, "", "", "", "", "", 1, 0, 3, 0};
		Dataset dataset8 = {"2018", 6, "2018-04-15-13:35", team4, team1, "", "", "", "", "", 3, 2, 3, 3};
		vecDatasetsRound6.push_back(dataset1);
		vecDatasetsRound6.push_back(dataset2);
		vecDatasetsRound6.push_back(dataset3);
		vecDatasetsRound6.push_back(dataset4);
		vecDatasetsRound6.push_back(dataset5);
 		vecDatasetsRound6.push_back(dataset6);
    	vecDatasetsRound6.push_back(dataset7);
    	vecDatasetsRound6.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound6);
    }

	// round 7
	{
		vector<Dataset> vecDatasetsRound7;
		Dataset dataset1 = {"2018", 7, "2018-04-20-13:35", team10, team4, "", "", "", "", "", 0, 1, 0, 2};
		Dataset dataset2 = {"2018", 7, "2018-04-21-09:30", team9, team2, "", "", "", "", "", 0, 0, 0, 0};
		Dataset dataset3 = {"2018", 7, "2018-04-21-13:35", team7, team12, "", "", "", "", "", 1, 0, 2, 4};
		Dataset dataset4 = {"2018", 7, "2018-04-21-13:35", team8, team3, "", "", "", "", "", 1, 3, 2, 5};
		Dataset dataset5 = {"2018", 7, "2018-04-22-09:30", team5, team15, "", "", "", "", "", 1, 1, 1, 1};
		Dataset dataset6 = {"2018", 7, "2018-04-22-12:00", team11, team14, "", "", "", "", "", 3, 1, 5, 1};
		Dataset dataset7 = {"2018", 7, "2018-04-22-13:35", team1, team6, "", "", "", "", "", 0, 0, 2, 2};
		Dataset dataset8 = {"2018", 7, "2018-04-22-14:00", team13, team16, "", "", "", "", "", 0, 1, 1, 1};
		vecDatasetsRound7.push_back(dataset1);
		vecDatasetsRound7.push_back(dataset2);
		vecDatasetsRound7.push_back(dataset3);
		vecDatasetsRound7.push_back(dataset4);
		vecDatasetsRound7.push_back(dataset5);
 		vecDatasetsRound7.push_back(dataset6);
    	vecDatasetsRound7.push_back(dataset7);
    	vecDatasetsRound7.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound7);
    }

	// round 8
	{
		vector<Dataset> vecDatasetsRound8;
		Dataset dataset1 = {"2018", 8, "2018-04-28-09:30", team2, team16, "", "", "", "", "", 1, 0, 1, 0};
		Dataset dataset2 = {"2018", 8, "2018-04-28-13:35", team6, team11, "", "", "", "", "", 0, 0, 1, 0};
		Dataset dataset3 = {"2018", 8, "2018-04-28-13:35", team15, team9, "", "", "", "", "", 0, 0, 0, 3};
		Dataset dataset4 = {"2018", 8, "2018-04-29-09:30", team3, team13, "", "", "", "", "", 1, 1, 2, 1};
		Dataset dataset5 = {"2018", 8, "2018-04-29-13:35", team14, team5, "", "", "", "", "", 0, 0, 1, 0};
		Dataset dataset6 = {"2018", 8, "2018-04-29-13:35", team12, team10, "", "", "", "", "", 0, 1, 2, 1};
		Dataset dataset7 = {"2018", 8, "2018-04-29-13:35", team1, team8, "", "", "", "", "", 3, 1, 4, 3};
		Dataset dataset8 = {"2018", 8, "2018-04-29-13:35", team4, team7, "", "", "", "", "", 0, 1, 0, 1};
		vecDatasetsRound8.push_back(dataset1);
		vecDatasetsRound8.push_back(dataset2);
		vecDatasetsRound8.push_back(dataset3);
		vecDatasetsRound8.push_back(dataset4);
		vecDatasetsRound8.push_back(dataset5);
 		vecDatasetsRound8.push_back(dataset6);
    	vecDatasetsRound8.push_back(dataset7);
    	vecDatasetsRound8.push_back(dataset8);
		vecDatasetsTotal.push_back(vecDatasetsRound8);
    }

	// vector of Table Entries, all the team information in the points table
	vector<TableEntry> vecTableEntry;

	// initialization of table entry vector
	TableEntry tableEntryTeam1 = {team1, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam1);
	TableEntry tableEntryTeam2 = {team2, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam2);
	TableEntry tableEntryTeam3 = {team3, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam3);
	TableEntry tableEntryTeam4 = {team4, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam4);
	TableEntry tableEntryTeam5 = {team5, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam5);
	TableEntry tableEntryTeam6 = {team6, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam6);
	TableEntry tableEntryTeam7 = {team7, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam7);
	TableEntry tableEntryTeam8 = {team8, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam8);
	TableEntry tableEntryTeam9 = {team9, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam9);
	TableEntry tableEntryTeam10 = {team10, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam10);
	TableEntry tableEntryTeam11 = {team11, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam11);
	TableEntry tableEntryTeam12 = {team12, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam12);
	TableEntry tableEntryTeam13 = {team13, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam13);
	TableEntry tableEntryTeam14 = {team14, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam14);
	TableEntry tableEntryTeam15 = {team15, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam15);
	TableEntry tableEntryTeam16 = {team16, 0, 0, 0, 0, 0, 0, 0, 0};
	vecTableEntry.push_back(tableEntryTeam16);

	// Algorithm to form the table entries
	for (auto& itRound : vecDatasetsTotal)
	{
		for (auto& itDataset : itRound)
		{
			for (auto& itTableEntry : vecTableEntry)
			{
				if(itDataset.homeTeam.iTeamID == itTableEntry.team.iTeamID)
				{
					itTableEntry.iMatchs++;

					if (itDataset.iFulltimeHomeTeamScore > itDataset.iFulltimeAwayTeamScore)
					{
						itTableEntry.iWin += 1;
						itTableEntry.iPoints += 3;
					}
					else if (itDataset.iFulltimeHomeTeamScore == itDataset.iFulltimeAwayTeamScore)
					{
						itTableEntry.iDraw += 1;
						itTableEntry.iPoints += 1;
					}
					else
					{
						itTableEntry.iLose += 1;
					}
				
					itTableEntry.iGoal += itDataset.iFulltimeHomeTeamScore;
					itTableEntry.iAgainstGoal += itDataset.iFulltimeAwayTeamScore;
					itTableEntry.iDiff = itTableEntry.iGoal - itTableEntry.iAgainstGoal;

					continue;
				}

				if(itDataset.awayTeam.iTeamID == itTableEntry.team.iTeamID)
				{
					itTableEntry.iMatchs++;
				
					if (itDataset.iFulltimeAwayTeamScore > itDataset.iFulltimeHomeTeamScore)
					{
						itTableEntry.iWin += 1;
						itTableEntry.iPoints += 3;
					}
					else if (itDataset.iFulltimeAwayTeamScore == itDataset.iFulltimeHomeTeamScore)
					{
						itTableEntry.iDraw += 1;
						itTableEntry.iPoints += 1;
					}
					else
					{
						itTableEntry.iLose += 1;
					}
				
					itTableEntry.iGoal += itDataset.iFulltimeAwayTeamScore;
					itTableEntry.iAgainstGoal += itDataset.iFulltimeHomeTeamScore;
					itTableEntry.iDiff = itTableEntry.iGoal - itTableEntry.iAgainstGoal;

					continue;
				}
			}
		}		
	}

	// Sort the table entries according to the points. (Detail rules are different from the different leagues)
	sort(vecTableEntry.begin(), vecTableEntry.end(), [](const TableEntry& lhs, const TableEntry& rhs)
    {
		if (lhs.iPoints > rhs.iPoints)
		{
			return true;
		}
		else if (lhs.iPoints == rhs.iPoints)
		{
			return lhs.iDiff > rhs.iDiff; //Todo: according the rule
		}
		else
		{
			return false;
		}
    });

	// Test Result Output
	int iRank = 1;
	for (auto& itTableEntry : vecTableEntry)
	{
    	cout << iRank << "  " << itTableEntry.team.strTeamName << "    	" << itTableEntry.iWin << " " << itTableEntry.iDraw << " " << itTableEntry.iLose << " " 				<< itTableEntry.iGoal << " " << itTableEntry.iAgainstGoal << " " << itTableEntry.iDiff << " " << itTableEntry.iPoints << endl;
		
		iRank++;
	}

    return 0;
}
