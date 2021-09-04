using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

vector<int> BubbleSort(vector<int>);
vector<int>initialization(vector<int>, int);
int min(int, int);

int main()
{    // var
	int maxDaysForIcuAndHOSPITAL_WARD_BEDS = 6;
	int NUMBER_OF_HOSPITAL_WARD_BEDS = 7;
	int NUMBER_OF_ICU_BEDS = 10;
	int NUMBER_SURGERY = 2;
	int NUMBER_OF_DAYS = 10;
	int DAY = 1;
	int EMPTY_BEDS_IN_HOSPITAL_WARD = 0;
	int SURGERY_COUNT = 0;
	//vector
	vector<int>HOSPITAL_WARD_BEDS_VECTOR;
	vector<int>ICU_BEDS_VECTOR;
	//
	ofstream OUF;
	OUF.open("OUT.txt");
	//
	//initialization
	ICU_BEDS_VECTOR = initialization(ICU_BEDS_VECTOR, NUMBER_OF_ICU_BEDS);
	HOSPITAL_WARD_BEDS_VECTOR = initialization(HOSPITAL_WARD_BEDS_VECTOR, NUMBER_OF_HOSPITAL_WARD_BEDS);
	//

/*
	for (int i = 0 ; i < HOSPITAL_WARD_BEDS_VECTOR.size() ; i++)
	{
		cout << HOSPITAL_WARD_BEDS_VECTOR[i] << " ";
	}

	cout << endl;
*/

	while (DAY <= NUMBER_OF_DAYS) //loop counter of day
	{
		OUF << "DAY: " << DAY << endl;

		//RESULT
		OUF << "AFTER-HOSPITAL_WARD, BEFOR-ICU: " << endl;
		for (int j = 0; j < ICU_BEDS_VECTOR.size(); j++)
		{
			OUF << ICU_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;
		for (int j = 0; j < HOSPITAL_WARD_BEDS_VECTOR.size(); j++)
		{
			OUF << HOSPITAL_WARD_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;
		//

		//******************************************//
		//                 ICU                      //
		//******************************************//
		for (int index = 0; index < NUMBER_OF_ICU_BEDS; index++)
		{
			if (ICU_BEDS_VECTOR[index] == 0)//accept patient in first time
			{
				ICU_BEDS_VECTOR[index] = (rand() % maxDaysForIcuAndHOSPITAL_WARD_BEDS) + 1;
			}
			else
			{
				ICU_BEDS_VECTOR[index] = ICU_BEDS_VECTOR[index] - 1;
			}
		}
		//RESULT
		OUF << "AFTER-ICU, BEFOR-SURGERY-ROOM: " << endl;
		for (int j = 0; j < ICU_BEDS_VECTOR.size(); j++)
		{
			OUF << ICU_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;

		for (int j = 0; j < HOSPITAL_WARD_BEDS_VECTOR.size(); j++)
		{
			OUF << HOSPITAL_WARD_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;
		//

		ICU_BEDS_VECTOR = BubbleSort(ICU_BEDS_VECTOR); //sorting

		//empty beds in HOSPITAL_WARD
		for (int index = 0; index < HOSPITAL_WARD_BEDS_VECTOR.size(); index++)
		{
			if (HOSPITAL_WARD_BEDS_VECTOR[index] == 0)
			{
				EMPTY_BEDS_IN_HOSPITAL_WARD = EMPTY_BEDS_IN_HOSPITAL_WARD + 1;
			}
		}

		//******************************************//
		//              SURGERY ROOM                //
		//******************************************//
		for (int index = 0; index < EMPTY_BEDS_IN_HOSPITAL_WARD; index++)
		{
			if (SURGERY_COUNT == NUMBER_SURGERY) { break; } // end of surgery in a day

			if (ICU_BEDS_VECTOR[index] < 0)//check Priority of patient (some paitient have less than 0 priority in ICU
			{
				ICU_BEDS_VECTOR[index] = (rand() % maxDaysForIcuAndHOSPITAL_WARD_BEDS) + 1; //now the bed is empty and we can accept new patinet in ICU
				SURGERY_COUNT = SURGERY_COUNT + 1;

				for (int i = 0; i < HOSPITAL_WARD_BEDS_VECTOR.size(); i++) // move The patient underwent surgery to HOSPITAL_WARD
				{
					if (HOSPITAL_WARD_BEDS_VECTOR[i] == 0)
					{
						HOSPITAL_WARD_BEDS_VECTOR[i] = (rand() % maxDaysForIcuAndHOSPITAL_WARD_BEDS) + 1;
					}
				}
				continue;
			}

			else if (ICU_BEDS_VECTOR[index] == 0)
			{
				ICU_BEDS_VECTOR[index] = (rand() % maxDaysForIcuAndHOSPITAL_WARD_BEDS) + 1; //now the bed is empty and we can accept new patinet
				SURGERY_COUNT = SURGERY_COUNT + 1;

				for (int i = 0; i < HOSPITAL_WARD_BEDS_VECTOR.size(); i++) // move The patient underwent surgery to HOSPITAL_WARD
				{
					if (HOSPITAL_WARD_BEDS_VECTOR[i] == 0)
					{
						HOSPITAL_WARD_BEDS_VECTOR[i] = (rand() % maxDaysForIcuAndHOSPITAL_WARD_BEDS) + 1;
						break;
					}
				}
				continue;
			}
		}

		OUF << "AFTER-SURGERY-ROOM, BEFOR-HOSPITAL_WARD: " << endl;
		for (int j = 0; j < ICU_BEDS_VECTOR.size(); j++)
		{
			OUF << ICU_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;

		for (int j = 0; j < HOSPITAL_WARD_BEDS_VECTOR.size(); j++)
		{
			OUF << HOSPITAL_WARD_BEDS_VECTOR[j] << " ";
		}
		OUF << endl;

		ICU_BEDS_VECTOR = BubbleSort(ICU_BEDS_VECTOR); //sorting
		HOSPITAL_WARD_BEDS_VECTOR = BubbleSort(HOSPITAL_WARD_BEDS_VECTOR); //sorting

		EMPTY_BEDS_IN_HOSPITAL_WARD = 0;
		SURGERY_COUNT = 0;
		//******************************************//
		//              HOSPITAL_WARD ROOM                 //
		//******************************************//
		for (int index = 0; index < HOSPITAL_WARD_BEDS_VECTOR.size(); index++) //count days for end of patinet hospital opration
		{
			if (HOSPITAL_WARD_BEDS_VECTOR[index] != 0)
			{
				HOSPITAL_WARD_BEDS_VECTOR[index] = HOSPITAL_WARD_BEDS_VECTOR[index] - 1;
			}
		}

		HOSPITAL_WARD_BEDS_VECTOR = BubbleSort(HOSPITAL_WARD_BEDS_VECTOR); //sorting



		DAY = DAY + 1;
		OUF << "============================================" << endl;
	}
	cout << "end";
	return 0;
}




//functions

vector<int>initialization(vector<int> vec, int number)
{
	for (int index = 0; index < number; index++)
	{
		vec.push_back(0);
	}
	return vec;
}

vector<int> BubbleSort(vector<int> vec)
{
	int temp;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] > vec[i])
			{
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
	return vec;
}
